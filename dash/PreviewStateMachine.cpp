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
 * Authored by: Gord Allott <gord.allott@canonical.com>>
 */

#include "PreviewStateMachine.h"
#include <NuxCore/Logger.h>
namespace unity
{
namespace dash
{

namespace
{
nux::logging::Logger logger("unity.dash.PreviewStateMachine");
}
PreviewStateMachine::PreviewStateMachine()
  : preview_active(false)
  , left_results(-1)
  , right_results(-1)
  , stored_preview_(nullptr)
  , requires_activation_(true)
{
  for (int pos = SplitPosition::START; pos != SplitPosition::END; pos++)
  {
    split_positions_[pos] = -1;
  }

  left_results.changed.connect([&] (int value) { CheckPreviewRequirementsFulfilled();});
  right_results.changed.connect([&] (int value) { CheckPreviewRequirementsFulfilled();});
}

PreviewStateMachine::~PreviewStateMachine()
{
}

void PreviewStateMachine::ActivatePreview(Preview::Ptr preview)
{
  stored_preview_ = preview;
  CheckPreviewRequirementsFulfilled();
  left_results = -1;
  right_results = -1;
  requires_activation_ = true;
}

void PreviewStateMachine::Reset()
{
  left_results = -1;
  right_results = -1;
  stored_preview_ = nullptr;
  requires_activation_ = true;
}

void PreviewStateMachine::ClosePreview()
{
  stored_preview_ = nullptr;
  preview_active = true;
  SetSplitPosition(SplitPosition::CONTENT_AREA, -1); 
}

void PreviewStateMachine::SetSplitPosition(SplitPosition position, int coord)
{
  split_positions_[static_cast<int>(position)] = coord;
  CheckPreviewRequirementsFulfilled();
}

int PreviewStateMachine::GetSplitPosition(SplitPosition position)
{
  return split_positions_[static_cast<int>(position)];
}

void PreviewStateMachine::CheckPreviewRequirementsFulfilled()
{
  if (!requires_activation_)
    return;

  if (stored_preview_ == nullptr)
    return;

  /* right now this is disabled as long as we aren't doing the fancy splitting animation
   * as we don't care about positions
   *
  if (GetSplitPosition(CONTENT_AREA) < 0) return;
  if (GetSplitPosition(FILTER_BAR) < 0) return;
  if (GetSplitPosition(LENS_BAR) < 0) return;
  if (GetSplitPosition(SEARCH_BAR) < 0) return;
   */
 
  if (left_results < 0 ||
      right_results < 0)
    return;

  LOG_DEBUG(logger) << "activating preview: " << left_results << " - " << right_results;
  preview_active = true;
  PreviewActivated(stored_preview_);
  requires_activation_ = false;
}

}
}