# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
# Copyright 2012 Canonical
# Author: Thomi Richards
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 3, as published
# by the Free Software Foundation.
#

import logging

from autopilot.emulators.unity import UnityIntrospectionObject
from autopilot.emulators.X11 import Mouse
from autopilot.keybindings import KeybindingsHelper

# even though we don't use these directly, we need to make sure they've been
# imported so the classes contained are registered with the introspection API.
from autopilot.emulators.unity.icons import *


logger = logging.getLogger(__name__)

class SwitcherMode():
    NORMAL = 0
    ALL = 1
    DETAIL = 2

class Switcher(KeybindingsHelper):
    def __init__(self):
        super(Switcher, self).__init__()
        self._mouse = Mouse()
        controllers = SwitcherController.get_all_instances()
        assert(len(controllers) == 1)
        self.controller = controllers[0]

    @property
    def visible(self):
        return self.controller.visible

    @property
    def icons(self):
        return self.controller.model.icons

    @property
    def current_icon(self):
        return self.icons[self.selection_index]

    @property
    def selection_index(self):
        return self.controller.model.selection_index

    @property 
    def mode(self):
        """Returns the modes the switcher is currently in"""
        if not self.visible:
            return None
        if self.controller.model.detail_selection and not self.controller.model.only_detail_on_viewport:
            return SwitcherMode.DETAIL, SwitcherMode.ALL
        elif self.controller.model.detail_selection:
            return SwitcherMode.DETAIL
        elif not self.controller.model.only_detail_on_viewport:
            return SwitcherMode.ALL
        else:
            return SwitcherMode.NORMAL

    def initiate(self, mode=SwitcherMode.NORMAL):
        if mode == SwitcherMode.NORMAL:
            logger.debug("Initiating switcher with Alt+Tab")
            self.keybinding_hold_part_then_tap("switcher/reveal_normal")
            self.visible.wait_for(True)
        elif mode == SwitcherMode.DETAIL:
            logger.debug("Initiating switcher detail mode with Alt+`")
            self.keybinding_hold_part_then_tap("switcher/reveal_details")
            self.controller.model.detail_selection.wait_for(True)
        elif mode == SwitcherMode.ALL:
            logger.debug("Initiating switcher in 'all workspaces' mode. Ctrl+Alt+Tab")
            self.keybinding_hold_part_then_tap("switcher/reveal_all")
            self.controller.model.only_detail_on_viewport.wait_for(False)

    def next_icon(self):
        """Move to the next icon."""
        logger.debug("Selecting next item in switcher.")
        self.keybinding("switcher/next")

    def previous_icon(self):
        """Move to the previous icon."""
        logger.debug("Selecting previous item in switcher.")
        self.keybinding("switcher/prev")

    def cancel(self):
        """
        Stop switcher without activating the selected icon and releasing the keys.
        NOTE: Does not release Alt.
        """
        logger.debug("Cancelling switcher.")
        self.keybinding("switcher/cancel")
        self.controller.visible.wait_for(False)

    def terminate(self):
        """Stop switcher without activating the selected icon."""
        logger.debug("Terminating switcher.")
        self.keybinding("switcher/cancel")
        self.keybinding_release("switcher/reveal_normal")
        self.controller.visible.wait_for(False)

    def select(self):
        """Stop switcher and activate the selected icon."""
        logger.debug("Stopping switcher")
        self.keybinding_release("switcher/reveal_normal")
        self.controller.visible.wait_for(False)

    def next_via_mouse(self):
        """Move to the next icon using the mouse scroll wheel"""
        logger.debug("Selecting next item in switcher with mouse scroll wheel.")
        self._mouse.press(6)
        self._mouse.release(6)

    def previous_via_mouse(self):
        """Move to the previous icon using the mouse scroll wheel"""
        logger.debug("Selecting previous item in switcher with mouse scroll wheel.")
        self._mouse.press(7)
        self._mouse.release(7)

    def show_details(self):
        """Show detail mode."""
        logger.debug("Showing details view.")
        self.keybinding("switcher/detail_start")
        self.controller.model.detail_selection.wait_for(True)

    def hide_details(self):
        """Hide detail mode."""
        logger.debug("Hiding details view.")
        self.keybinding("switcher/detail_stop")
        self.controller.model.detail_selection.wait_for(False)

    def next_detail(self):
        """Move to next detail in the switcher."""
        logger.debug("Selecting next item in details mode.")
        self.keybinding("switcher/detail_next")

    def previous_detail(self):
        """Move to the previous detail in the switcher."""
        logger.debug("Selecting previous item in details mode.")
        self.keybinding("switcher/detail_prev")


class SwitcherController(UnityIntrospectionObject):
    """
    An emulator class for interacting with the switcher controller
    """

    @property
    def view(self):
        return self.get_children_by_type(SwitcherView)[0]

    @property
    def model(self):
        return self.get_children_by_type(SwitcherModel)[0]

class SwitcherView(UnityIntrospectionObject):
    """
    An emulator class for interacting with with SwitcherView
    """

class SwitcherModel(UnityIntrospectionObject):
    """
    An emulator class for interacting with the SwitcherModel
    """

    @property
    def icons(self):
        return self.get_children_by_type(SimpleLauncherIcon)