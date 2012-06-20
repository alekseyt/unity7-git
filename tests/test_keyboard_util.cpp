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
 * Authored by: Marco Trevisan (Treviño) <3v1n0@ubuntu.com>
 */

#include <gtest/gtest.h>
#include <algorithm>

#include "KeyboardUtil.h"

using namespace unity::ui;

namespace
{

TEST(TestKeyboardUtil, PrintableKeySymbols)
{
  EXPECT_TRUE(KeyboardUtil::IsPrintableKeySymbol(XK_Delete));
  EXPECT_TRUE(KeyboardUtil::IsPrintableKeySymbol(XK_BackSpace));
  EXPECT_TRUE(KeyboardUtil::IsPrintableKeySymbol(XK_space));
  EXPECT_TRUE(KeyboardUtil::IsPrintableKeySymbol(XK_3));
  EXPECT_TRUE(KeyboardUtil::IsPrintableKeySymbol(XK_v));
  EXPECT_TRUE(KeyboardUtil::IsPrintableKeySymbol(XK_1));
  EXPECT_TRUE(KeyboardUtil::IsPrintableKeySymbol(XK_ntilde));
  EXPECT_TRUE(KeyboardUtil::IsPrintableKeySymbol(XK_0));
  EXPECT_TRUE(KeyboardUtil::IsPrintableKeySymbol(XK_exclam));

  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_F1));
  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_Select));
  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_Hyper_R));
  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_Control_L));
  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_Shift_L));
  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_Super_L));
  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_Print));
  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_Insert));
  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_Num_Lock));
  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_Caps_Lock));
  EXPECT_FALSE(KeyboardUtil::IsPrintableKeySymbol(XK_ISO_Level3_Shift));
}

TEST(TestKeyboardUtil, MoveKeySymbols)
{
  std::vector<KeySym> move_symbols { XK_Home, XK_Left, XK_Up, XK_Right, XK_Down,
                                     XK_Prior, XK_Page_Up, XK_Next, XK_Page_Down,
                                     XK_End, XK_Begin };

  for (KeySym sym = 0; sym < XK_VoidSymbol; ++sym)
  {
    if (std::find(move_symbols.begin(), move_symbols.end(), sym) != move_symbols.end())
      EXPECT_TRUE(KeyboardUtil::IsMoveKeySymbol(sym));
    else
      EXPECT_FALSE(KeyboardUtil::IsMoveKeySymbol(sym));
  }
}

} // Namespace
