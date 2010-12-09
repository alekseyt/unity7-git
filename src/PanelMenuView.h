/*
 * Copyright (C) 2010 Canonical Ltd
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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#ifndef PANEL_MENU_VIEW_H
#define PANEL_MENU_VIEW_H

#include <Nux/View.h>

#include "IndicatorObjectProxy.h"

#include "PanelIndicatorObjectView.h"

#include "Introspectable.h"

class PanelMenuView : public PanelIndicatorObjectView
{
public:
  PanelMenuView ();
  ~PanelMenuView ();

  virtual long ProcessEvent (nux::IEvent &ievent, long TraverseInfo, long ProcessEventInfo);
  virtual void Draw (nux::GraphicsEngine& GfxContext, bool force_draw);
  virtual void DrawContent (nux::GraphicsEngine &GfxContext, bool force_draw);
  virtual void DrawLayout ();
  virtual long PostLayoutManagement (long LayoutResult);
  virtual void PreLayoutManagement ();
  
  void RecvButtonMouseDown (int x, int y, unsigned long button_flags, unsigned long key_flags);
  void RecvButtonMouseUp (int x, int y, unsigned long button_flags, unsigned long key_flags);
  void RecvButtonMouseEnter (int x, int y, unsigned long button_flags, unsigned long key_flags);
  void RecvButtonMouseLeave (int x, int y, unsigned long button_flags, unsigned long key_flags);
  void RecvButtonMouseMove (int x, int y, int dx, int dy, unsigned long button_flags, unsigned long key_flags);
  
  void SetProxy (IndicatorObjectProxy *proxy);
 
  void OnMouseEnterRecv (int x, int y, unsigned long button_flags, unsigned long key_flags);
  void OnMouseLeaveRecv (int x, int y, unsigned long button_flags, unsigned long key_flags);

  void OnEntryAdded (IndicatorObjectEntryProxy *proxy);
  void OnEntryMoved (IndicatorObjectEntryProxy *proxy);
  void OnEntryRemoved (IndicatorObjectEntryProxy *proxy);

  nux::HLayout *_title_layout;
  nux::HLayout *_menu_layout;
protected:
  const gchar * GetName ();
  const gchar * GetChildsName ();
  void          AddProperties (GVariantBuilder *builder); 
};

#endif // PANEL_INDICATOR_OBJECT_VIEW_H
