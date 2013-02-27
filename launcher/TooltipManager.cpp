// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2012 Canonical Ltd
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
 * Authored by: Jacob Edwards <j.johan.edwards@gmail.com>
 */

#include "TooltipManager.h"

namespace unity
{
namespace launcher
{

namespace
{
const unsigned int TOOLTIPS_SHOW_TIMEOUT_LENGTH = 1000;
}

TooltipManager::TooltipManager()
   : _show_tooltips(false)
   , _hovered(false)
   , _icon(nullptr)
{}

void TooltipManager::SetIcon(AbstractLauncherIcon::Ptr const& newIcon) { 
  if (_icon == newIcon)
    return;

  if (_show_tooltips) {
    if (_icon)
      _icon->HideTooltip();
    if (newIcon)
      newIcon->ShowTooltip();
  }
  else if (!newIcon) {
    StopTimer();
  }

  _icon = newIcon;
}

void TooltipManager::SetHover(bool on_launcher) { 
  if (_hovered == on_launcher) {
    return;
  }
  _hovered = on_launcher;

  if (_show_tooltips && !_hovered) {
    _show_tooltips = false;
    if (_icon)
      _icon->HideTooltip();
  }
}

void TooltipManager::MouseMoved() {
  if (!_icon || _show_tooltips)
    return;

  ResetTimer();
}

void TooltipManager::ResetTimer() {
  StopTimer();
  _hover_timer->Run([&] () {
    _show_tooltips = true;
    _icon->ShowTooltip();
    return false;
  });
}

void TooltipManager::StopTimer() {
  _hover_timer.reset(new glib::Timeout(TOOLTIPS_SHOW_TIMEOUT_LENGTH));
}

} // namespace launcher
} // namespace unity
