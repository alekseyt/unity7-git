// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2013 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Marco Trevisan <marco.trevisan@canonical.com>
 */

#include <NuxCore/Logger.h>
#include <composite/composite.h>
#include <boost/range/adaptor/reversed.hpp>
#include "DecorationsWidgets.h"

namespace unity
{
namespace decoration
{
namespace
{
DECLARE_LOGGER(logger, "unity.decoration.widgets");
CompositeScreen* cscreen_ = CompositeScreen::get(screen);
}

Item::Item()
  : visible(true)
  , focused(false)
  , sensitive(true)
  , mouse_owner(false)
  , max_(std::numeric_limits<int>::max(), std::numeric_limits<int>::max())
{
  auto parent_relayout_cb = [this] {
    if (BasicContainer::Ptr const& parent = parent_.lock())
      parent->Relayout();
  };

  visible.changed.connect(sigc::hide(parent_relayout_cb));
  geo_parameters_changed.connect(parent_relayout_cb);
}

void Item::SetSize(int width, int height)
{
  natural_.width = std::max(0, width);
  natural_.height = std::max(0, height);
  SetMinWidth(width);
  SetMaxWidth(width);
  SetMinHeight(height);
  SetMaxHeight(height);
}

void Item::SetCoords(int x, int y)
{
  auto& geo = InternalGeo();

  if (geo.x() == x && geo.y() == y)
    return;

  geo.setX(x);
  geo.setY(y);
  geo_parameters_changed.emit();
}

int Item::GetNaturalWidth() const
{
  return natural_.width;
}

int Item::GetNaturalHeight() const
{
  return natural_.height;
}

void Item::SetMaxWidth(int value)
{
  int clamped = std::max(0, value);

  if (max_.width == clamped)
    return;

  max_.width = clamped;
  min_.width = std::min(min_.width, max_.width);

  if (Geometry().width() > max_.width)
    InternalGeo().setWidth(std::min(GetNaturalWidth(), max_.width));

  geo_parameters_changed.emit();
}

void Item::SetMinWidth(int value)
{
  int clamped = std::max(0, value);

  if (min_.width == clamped)
    return;

  min_.width = clamped;
  max_.width = std::max(min_.width, max_.width);

  if (Geometry().width() < min_.width)
    InternalGeo().setWidth(min_.width);

  geo_parameters_changed.emit();
}

void Item::SetMaxHeight(int value)
{
  int clamped = std::max(0, value);

  if (max_.height == clamped)
    return;

  max_.height = clamped;
  min_.height = std::min(min_.height, max_.height);

  if (Geometry().height() > max_.height)
    InternalGeo().setHeight(std::min(GetNaturalHeight(), max_.height));

  geo_parameters_changed.emit();
}

void Item::SetMinHeight(int value)
{
  int clamped = std::max(0, value);

  if (min_.height == clamped)
    return;

  min_.height = clamped;
  max_.height = std::max(min_.height, max_.height);

  if (Geometry().height() < min_.height)
    InternalGeo().setHeight(min_.height);

  geo_parameters_changed.emit();
}

void Item::Damage()
{
  cscreen_->damageRegion(Geometry());
}

CompRect const& Item::Geometry() const
{
  return const_cast<Item*>(this)->InternalGeo();
}

void Item::SetParent(BasicContainer::Ptr const& parent)
{
  if (parent && !parent_.expired())
  {
    LOG_ERROR(logger) << "This item has already a parent!";
    return;
  }

  parent_ = parent;
}

BasicContainer::Ptr Item::GetParent() const
{
  return parent_.lock();
}

//

void TexturedItem::Draw(GLWindow* ctx, GLMatrix const& transformation, GLWindowPaintAttrib const& attrib,
                        CompRegion const& clip, unsigned mask)
{
  if (!visible)
    return;

  ctx->vertexBuffer()->begin();
  ctx->glAddGeometry({texture_.quad.matrix}, texture_.quad.box, clip);

  if (ctx->vertexBuffer()->end())
    ctx->glDrawTexture(texture_, transformation, attrib, mask);
}

int TexturedItem::GetNaturalWidth() const
{
  return (texture_.st) ? texture_.st->width() : Item::GetNaturalWidth();
}

int TexturedItem::GetNaturalHeight() const
{
  return (texture_.st) ? texture_.st->height() : Item::GetNaturalHeight();
}

CompRect& TexturedItem::InternalGeo()
{
  return texture_.quad.box;
}

void TexturedItem::SetCoords(int x, int y)
{
  texture_.SetCoords(x, y);
}

//

BasicContainer::BasicContainer()
{
  geo_parameters_changed.connect(sigc::mem_fun(this, &BasicContainer::Relayout));
  focused.changed.connect([this] (bool focused) {
    for (auto const& item : items_)
      item->focused = focused;
  });
}

//

Layout::Layout()
  : inner_padding(0, sigc::mem_fun(this, &Layout::SetPadding))
  , left_padding(0, sigc::mem_fun(this, &Layout::SetPadding))
  , right_padding(0, sigc::mem_fun(this, &Layout::SetPadding))
  , top_padding(0, sigc::mem_fun(this, &Layout::SetPadding))
  , bottom_padding(0, sigc::mem_fun(this, &Layout::SetPadding))
  , relayouting_(false)
{}

void Layout::Append(Item::Ptr const& item)
{
  if (!item || std::find(items_.begin(), items_.end(), item) != items_.end())
    return;

  items_.push_back(item);
  item->focused = focused();
  item->SetParent(shared_from_this());
  Relayout();
}

void Layout::Remove(Item::Ptr const& item)
{
  auto it = std::find(items_.begin(), items_.end(), item);

  if (it == items_.end())
    return;

  item->SetParent(nullptr);
  items_.erase(it);
  Relayout();
}

void Layout::Relayout()
{
  if (relayouting_)
    return;

  relayouting_ = true;
  int loop = 0;

  nux::Size available_space(std::max(0, max_.width - left_padding - right_padding),
                            std::max(0, max_.height - top_padding - bottom_padding));

  do
  {
    nux::Size content(std::min(left_padding(), max_.width), 0);

    for (auto const& item : items_)
    {
      if (!item->visible())
        continue;

      if (loop == 0)
      {
        item->SetMinWidth(item->GetNaturalWidth());
        item->SetMaxWidth(available_space.width);
        item->SetMinHeight(std::min(available_space.height, item->GetNaturalHeight()));
        item->SetMaxHeight(available_space.height);
      }

      auto const& item_geo = item->Geometry();
      content.height = std::max(content.height, item_geo.height());
      item->SetX(rect_.x() + content.width);

      if (item_geo.width() > 0)
        content.width += item_geo.width() + inner_padding;
    }

    if (!items_.empty() && content.width > inner_padding)
      content.width -= inner_padding;

    int actual_right_padding = std::max(0, std::min(right_padding(), max_.width - content.width));
    int vertical_padding = top_padding + bottom_padding;

    content.width += actual_right_padding;
    content.height += std::min(vertical_padding, max_.height);

    if (content.width < min_.width)
      content.width = min_.width;

    if (content.height < min_.height)
      content.height = min_.height;

    int exceeding_width = content.width - max_.width + inner_padding + right_padding - actual_right_padding;
    int content_y = rect_.y() + top_padding;

    for (auto const& item : boost::adaptors::reverse(items_))
    {
      if (!item->visible())
        continue;

      auto const& item_geo = item->Geometry();

      if (exceeding_width > 0)
        exceeding_width -= inner_padding;

      if (exceeding_width > 0 && item_geo.width() > 0)
      {
        int old_width = item_geo.width();
        int max_item_width = std::max(0, old_width - exceeding_width);
        item->SetMaxWidth(max_item_width);
        exceeding_width -= (old_width - max_item_width);
      }

      item->SetY(content_y + (content.height - vertical_padding - item_geo.height()) / 2);
    }

    rect_.setWidth(content.width);
    rect_.setHeight(content.height);

    if (loop > 1)
    {
      LOG_ERROR(logger) << "Relayouting is taking more than expected, process should be completed in maximum two loops!";
      break;
    }

    ++loop;
  }
  while (rect_.width() > max_.width || rect_.height() > max_.height);

  relayouting_ = false;
}

void Layout::Draw(GLWindow* ctx, GLMatrix const& transformation, GLWindowPaintAttrib const& attrib,
                  CompRegion const& clip, unsigned mask)
{
  for (auto const& item : items_)
  {
    if (item->visible())
      item->Draw(ctx, transformation, attrib, clip, mask);
  }
}

bool Layout::SetPadding(int& target, int new_value)
{
  int padding = std::max(0, new_value);

  if (padding == target)
    return false;

  target = padding;
  Relayout();

  return true;
}

} // decoration namespace
} // unity namespace
