/* scrollerchild-controller.c generated by valac, the Vala compiler
 * generated from scrollerchild-controller.vala, do not modify */

/*
 *      scrollerchild-controller.vala
 *      Copyright (C) 2010 Canonical Ltd
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 *
 *
 *      Authored by Gordon Allott <gord.allott@canonical.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <unity.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <clutk/clutk.h>
#include <clutter/clutter.h>


#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER_MENU_STATE (unity_launcher_scroller_child_controller_menu_state_get_type ())

#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER (unity_launcher_scroller_child_controller_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildController))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildControllerClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildControllerClass))

typedef struct _UnityLauncherScrollerChildController UnityLauncherScrollerChildController;
typedef struct _UnityLauncherScrollerChildControllerClass UnityLauncherScrollerChildControllerClass;
typedef struct _UnityLauncherScrollerChildControllerPrivate UnityLauncherScrollerChildControllerPrivate;

#define UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM (unity_launcher_shortcut_item_get_type ())
#define UNITY_LAUNCHER_SHORTCUT_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM, UnityLauncherShortcutItem))
#define UNITY_LAUNCHER_IS_SHORTCUT_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM))
#define UNITY_LAUNCHER_SHORTCUT_ITEM_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_LAUNCHER_TYPE_SHORTCUT_ITEM, UnityLauncherShortcutItemIface))

typedef struct _UnityLauncherShortcutItem UnityLauncherShortcutItem;
typedef struct _UnityLauncherShortcutItemIface UnityLauncherShortcutItemIface;

#define UNITY_LAUNCHER_TYPE_SCROLLER_CHILD (unity_launcher_scroller_child_get_type ())
#define UNITY_LAUNCHER_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChild))
#define UNITY_LAUNCHER_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_IS_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD))
#define UNITY_LAUNCHER_SCROLLER_CHILD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, UnityLauncherScrollerChildClass))

typedef struct _UnityLauncherScrollerChild UnityLauncherScrollerChild;
typedef struct _UnityLauncherScrollerChildClass UnityLauncherScrollerChildClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER (unity_launcher_quicklist_controller_get_type ())
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistController))
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistControllerClass))
#define UNITY_LAUNCHER_IS_QUICKLIST_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_IS_QUICKLIST_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER))
#define UNITY_LAUNCHER_QUICKLIST_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_CONTROLLER, UnityLauncherQuicklistControllerClass))

typedef struct _UnityLauncherQuicklistController UnityLauncherQuicklistController;
typedef struct _UnityLauncherQuicklistControllerClass UnityLauncherQuicklistControllerClass;
typedef struct _UnityLauncherQuicklistControllerPrivate UnityLauncherQuicklistControllerPrivate;
typedef struct _UnityLauncherScrollerChildPrivate UnityLauncherScrollerChildPrivate;

#define UNITY_LAUNCHER_TYPE_PIN_TYPE (unity_launcher_pin_type_get_type ())

typedef enum  {
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_NO_MENU,
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_LABEL,
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU,
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU_CLOSE_WHEN_LEAVE
} UnityLauncherScrollerChildControllerMenuState;

struct _UnityLauncherShortcutItemIface {
	GTypeInterface parent_iface;
	char* (*get_name) (UnityLauncherShortcutItem* self);
	void (*activated) (UnityLauncherShortcutItem* self);
};

struct _UnityLauncherScrollerChildController {
	GObject parent_instance;
	UnityLauncherScrollerChildControllerPrivate * priv;
	char* name;
	UnityLauncherScrollerChildControllerMenuState menu_state;
	guint32 last_press_time;
	gboolean button_down;
	float click_start_pos;
	gint drag_sensitivity;
};

struct _UnityLauncherScrollerChildControllerClass {
	GObjectClass parent_class;
	GeeArrayList* (*get_menu_shortcuts) (UnityLauncherScrollerChildController* self);
	GeeArrayList* (*get_menu_shortcut_actions) (UnityLauncherScrollerChildController* self);
	void (*activate) (UnityLauncherScrollerChildController* self);
};

struct _UnityLauncherScrollerChildControllerPrivate {
	UnityLauncherScrollerChild* _child;
};

struct _UnityLauncherQuicklistController {
	GObject parent_instance;
	UnityLauncherQuicklistControllerPrivate * priv;
	CtkMenu* menu;
	gboolean is_in_label;
	gboolean is_in_menu;
};

struct _UnityLauncherQuicklistControllerClass {
	GObjectClass parent_class;
};

typedef enum  {
	UNITY_LAUNCHER_PIN_TYPE_UNPINNED,
	UNITY_LAUNCHER_PIN_TYPE_PINNED,
	UNITY_LAUNCHER_PIN_TYPE_ALWAYS,
	UNITY_LAUNCHER_PIN_TYPE_NEVER
} UnityLauncherPinType;

struct _UnityLauncherScrollerChild {
	CtkActor parent_instance;
	UnityLauncherScrollerChildPrivate * priv;
	UnityLauncherPinType pin_type;
	UnityLauncherScrollerChildController* controller;
};

struct _UnityLauncherScrollerChildClass {
	CtkActorClass parent_class;
	void (*force_rotation_jump) (UnityLauncherScrollerChild* self, float degrees);
};


static gpointer unity_launcher_scroller_child_controller_parent_class = NULL;
static UnityDragModelIface* unity_launcher_scroller_child_controller_unity_drag_model_parent_iface = NULL;

GType unity_launcher_scroller_child_controller_menu_state_get_type (void);
GType unity_launcher_scroller_child_controller_get_type (void);
GType unity_launcher_shortcut_item_get_type (void);
GType unity_launcher_scroller_child_get_type (void);
#define UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, UnityLauncherScrollerChildControllerPrivate))
enum  {
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_DUMMY_PROPERTY,
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CHILD
};
UnityLauncherScrollerChildController* unity_launcher_scroller_child_controller_construct (GType object_type, UnityLauncherScrollerChild* child_);
GeeArrayList* unity_launcher_scroller_child_controller_get_menu_shortcuts (UnityLauncherScrollerChildController* self);
static GeeArrayList* unity_launcher_scroller_child_controller_real_get_menu_shortcuts (UnityLauncherScrollerChildController* self);
GeeArrayList* unity_launcher_scroller_child_controller_get_menu_shortcut_actions (UnityLauncherScrollerChildController* self);
static GeeArrayList* unity_launcher_scroller_child_controller_real_get_menu_shortcut_actions (UnityLauncherScrollerChildController* self);
void unity_launcher_scroller_child_controller_activate (UnityLauncherScrollerChildController* self);
static void unity_launcher_scroller_child_controller_real_activate (UnityLauncherScrollerChildController* self);
static void unity_launcher_scroller_child_controller_ensure_menu_state (UnityLauncherScrollerChildController* self);
static gboolean unity_launcher_scroller_child_controller_on_leave_event (UnityLauncherScrollerChildController* self, ClutterEvent* event);
static gboolean unity_launcher_scroller_child_controller_on_press_event (UnityLauncherScrollerChildController* self, ClutterEvent* event);
GType unity_launcher_quicklist_controller_get_type (void);
UnityLauncherQuicklistController* unity_launcher_quicklist_controller_get_default (void);
gboolean unity_launcher_quicklist_controller_menu_is_open (UnityLauncherQuicklistController* self);
void unity_launcher_quicklist_controller_close_menu (UnityLauncherQuicklistController* self);
static gboolean unity_launcher_scroller_child_controller_on_release_event (UnityLauncherScrollerChildController* self, ClutterEvent* event);
static gboolean unity_launcher_scroller_child_controller_on_enter_event (UnityLauncherScrollerChildController* self, ClutterEvent* event);
CtkActor* unity_launcher_quicklist_controller_get_attached_actor (UnityLauncherQuicklistController* self);
UnityLauncherScrollerChild* unity_launcher_scroller_child_controller_get_child (UnityLauncherScrollerChildController* self);
static void _unity_launcher_scroller_child_controller_ensure_menu_state_clutter_actor_destroy (ClutterActor* _sender, gpointer self);
#define UNITY_PANEL_search_entry_has_focus FALSE
void unity_launcher_quicklist_controller_show_label (UnityLauncherQuicklistController* self, const char* label, CtkActor* attached_widget);
void unity_launcher_quicklist_controller_show_menu (UnityLauncherQuicklistController* self, GeeArrayList* prefix_shortcuts, GeeArrayList* affix_shortcuts, gboolean hide_on_leave);
static ClutterActor* unity_launcher_scroller_child_controller_real_get_icon (UnityDragModel* base);
static char* unity_launcher_scroller_child_controller_real_get_drag_data (UnityDragModel* base);
static gboolean unity_launcher_scroller_child_controller_on_motion_event (UnityLauncherScrollerChildController* self, ClutterEvent* event);
static void unity_launcher_scroller_child_controller_set_child (UnityLauncherScrollerChildController* self, UnityLauncherScrollerChild* value);
GType unity_launcher_pin_type_get_type (void);
static gboolean _unity_launcher_scroller_child_controller_on_press_event_clutter_actor_button_press_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static gboolean _unity_launcher_scroller_child_controller_on_release_event_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static gboolean _unity_launcher_scroller_child_controller_on_enter_event_clutter_actor_enter_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static gboolean _unity_launcher_scroller_child_controller_on_leave_event_clutter_actor_leave_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static gboolean _unity_launcher_scroller_child_controller_on_motion_event_clutter_actor_motion_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
#define UNITY_LAUNCHER_SHORT_DELAY ((guint) 400)
static GObject * unity_launcher_scroller_child_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_launcher_scroller_child_controller_finalize (GObject* obj);
static void unity_launcher_scroller_child_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_launcher_scroller_child_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



GType unity_launcher_scroller_child_controller_menu_state_get_type (void) {
	static volatile gsize unity_launcher_scroller_child_controller_menu_state_type_id__volatile = 0;
	if (g_once_init_enter (&unity_launcher_scroller_child_controller_menu_state_type_id__volatile)) {
		static const GEnumValue values[] = {{UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_NO_MENU, "UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_NO_MENU", "no-menu"}, {UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_LABEL, "UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_LABEL", "label"}, {UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU, "UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU", "menu"}, {UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU_CLOSE_WHEN_LEAVE, "UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU_CLOSE_WHEN_LEAVE", "menu-close-when-leave"}, {0, NULL, NULL}};
		GType unity_launcher_scroller_child_controller_menu_state_type_id;
		unity_launcher_scroller_child_controller_menu_state_type_id = g_enum_register_static ("UnityLauncherScrollerChildControllerMenuState", values);
		g_once_init_leave (&unity_launcher_scroller_child_controller_menu_state_type_id__volatile, unity_launcher_scroller_child_controller_menu_state_type_id);
	}
	return unity_launcher_scroller_child_controller_menu_state_type_id__volatile;
}


UnityLauncherScrollerChildController* unity_launcher_scroller_child_controller_construct (GType object_type, UnityLauncherScrollerChild* child_) {
	UnityLauncherScrollerChildController * self;
	g_return_val_if_fail (child_ != NULL, NULL);
	self = (UnityLauncherScrollerChildController*) g_object_new (object_type, "child", child_, NULL);
	return self;
}


static GeeArrayList* unity_launcher_scroller_child_controller_real_get_menu_shortcuts (UnityLauncherScrollerChildController* self) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `unity_launcher_scroller_child_controller_get_menu_shortcuts'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


GeeArrayList* unity_launcher_scroller_child_controller_get_menu_shortcuts (UnityLauncherScrollerChildController* self) {
	return UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_GET_CLASS (self)->get_menu_shortcuts (self);
}


static GeeArrayList* unity_launcher_scroller_child_controller_real_get_menu_shortcut_actions (UnityLauncherScrollerChildController* self) {
	g_return_val_if_fail (self != NULL, NULL);
	g_critical ("Type `%s' does not implement abstract method `unity_launcher_scroller_child_controller_get_menu_shortcut_actions'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


GeeArrayList* unity_launcher_scroller_child_controller_get_menu_shortcut_actions (UnityLauncherScrollerChildController* self) {
	return UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_GET_CLASS (self)->get_menu_shortcut_actions (self);
}


static void unity_launcher_scroller_child_controller_real_activate (UnityLauncherScrollerChildController* self) {
	g_return_if_fail (self != NULL);
	g_critical ("Type `%s' does not implement abstract method `unity_launcher_scroller_child_controller_activate'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void unity_launcher_scroller_child_controller_activate (UnityLauncherScrollerChildController* self) {
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_GET_CLASS (self)->activate (self);
}


static gboolean unity_launcher_scroller_child_controller_on_leave_event (UnityLauncherScrollerChildController* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	self->button_down = FALSE;
	if (self->menu_state != UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU) {
		self->menu_state = UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_NO_MENU;
	}
	unity_launcher_scroller_child_controller_ensure_menu_state (self);
	result = FALSE;
	return result;
}


static gboolean unity_launcher_scroller_child_controller_on_press_event (UnityLauncherScrollerChildController* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	switch ((*event).button.button) {
		case 1:
		{
			{
				self->last_press_time = (*event).button.time;
				self->button_down = TRUE;
				self->click_start_pos = (*event).button.x;
			}
			break;
		}
		case 3:
		{
			{
				self->menu_state = UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU;
				unity_launcher_scroller_child_controller_ensure_menu_state (self);
			}
			break;
		}
		default:
		{
			break;
		}
	}
	result = FALSE;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean unity_launcher_scroller_child_controller_on_release_event (UnityLauncherScrollerChildController* self, ClutterEvent* event) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	if ((*event).button.button == 1) {
		_tmp1_ = self->button_down == TRUE;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_tmp0_ = ((*event).button.time - self->last_press_time) < 500;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		UnityLauncherQuicklistController* controller;
		gboolean _tmp2_ = FALSE;
		controller = _g_object_ref0 (unity_launcher_quicklist_controller_get_default ());
		if (controller->is_in_label) {
			_tmp2_ = TRUE;
		} else {
			_tmp2_ = unity_launcher_quicklist_controller_menu_is_open (controller);
		}
		if (_tmp2_) {
			unity_launcher_quicklist_controller_close_menu (controller);
		}
		unity_launcher_scroller_child_controller_activate (self);
		_g_object_unref0 (controller);
	}
	self->button_down = FALSE;
	result = FALSE;
	return result;
}


static gboolean unity_launcher_scroller_child_controller_on_enter_event (UnityLauncherScrollerChildController* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	self->menu_state = UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_LABEL;
	unity_launcher_scroller_child_controller_ensure_menu_state (self);
	result = FALSE;
	return result;
}


static void _unity_launcher_scroller_child_controller_ensure_menu_state_clutter_actor_destroy (ClutterActor* _sender, gpointer self) {
	unity_launcher_scroller_child_controller_ensure_menu_state (self);
}


static void unity_launcher_scroller_child_controller_ensure_menu_state (UnityLauncherScrollerChildController* self) {
	UnityLauncherQuicklistController* controller;
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	if (unity_drag_controller_get_is_dragging (unity_drag_controller_get_default ())) {
		return;
	}
	controller = _g_object_ref0 (unity_launcher_quicklist_controller_get_default ());
	if (unity_launcher_quicklist_controller_menu_is_open (controller)) {
		CtkActor* _tmp1_;
		_tmp0_ = (_tmp1_ = unity_launcher_quicklist_controller_get_attached_actor (controller)) != CTK_ACTOR (self->priv->_child);
		_g_object_unref0 (_tmp1_);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		g_signal_connect_object ((ClutterActor*) controller->menu, "destroy", (GCallback) _unity_launcher_scroller_child_controller_ensure_menu_state_clutter_actor_destroy, self, 0);
		_g_object_unref0 (controller);
		return;
	}
	if (self->menu_state == UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_NO_MENU) {
		gboolean _tmp2_ = FALSE;
		if (controller->is_in_label) {
			_tmp2_ = TRUE;
		} else {
			_tmp2_ = unity_launcher_quicklist_controller_menu_is_open (controller);
		}
		if (_tmp2_) {
			unity_launcher_quicklist_controller_close_menu (controller);
		}
	}
	if (self->menu_state == UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_LABEL) {
		if (!unity_launcher_quicklist_controller_menu_is_open (controller)) {
			if (UNITY_PANEL_search_entry_has_focus == FALSE) {
				unity_launcher_quicklist_controller_show_label (controller, self->name, (CtkActor*) self->priv->_child);
			}
		}
	}
	if (self->menu_state == UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_MENU) {
		if (controller->is_in_label) {
			GeeArrayList* shortcuts;
			GeeArrayList* actions;
			gboolean _tmp3_ = FALSE;
			shortcuts = unity_launcher_scroller_child_controller_get_menu_shortcuts (self);
			actions = unity_launcher_scroller_child_controller_get_menu_shortcut_actions (self);
			if (gee_collection_get_size ((GeeCollection*) shortcuts) > 0) {
				_tmp3_ = TRUE;
			} else {
				_tmp3_ = gee_collection_get_size ((GeeCollection*) actions) > 0;
			}
			if (_tmp3_) {
				unity_launcher_quicklist_controller_show_menu (controller, shortcuts, actions, FALSE);
			} else {
				self->menu_state = UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_MENU_STATE_LABEL;
			}
			_g_object_unref0 (shortcuts);
			_g_object_unref0 (actions);
		}
	}
	_g_object_unref0 (controller);
}


static ClutterActor* unity_launcher_scroller_child_controller_real_get_icon (UnityDragModel* base) {
	UnityLauncherScrollerChildController * self;
	ClutterActor* result = NULL;
	self = (UnityLauncherScrollerChildController*) base;
	result = _g_object_ref0 ((ClutterActor*) self->priv->_child);
	return result;
}


static char* unity_launcher_scroller_child_controller_real_get_drag_data (UnityDragModel* base) {
	UnityLauncherScrollerChildController * self;
	char* result = NULL;
	self = (UnityLauncherScrollerChildController*) base;
	result = g_strdup (self->name);
	return result;
}


static gboolean unity_launcher_scroller_child_controller_on_motion_event (UnityLauncherScrollerChildController* self, ClutterEvent* event) {
	gboolean result = FALSE;
	UnityDragController* drag_controller;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	drag_controller = _g_object_ref0 (unity_drag_controller_get_default ());
	if (self->button_down) {
		_tmp0_ = unity_drag_controller_get_is_dragging (drag_controller) == FALSE;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		float diff;
		diff = fabsf ((*event).motion.x - self->click_start_pos);
		if (diff > self->drag_sensitivity) {
			float x = 0.0F;
			float y = 0.0F;
			clutter_actor_get_transformed_position ((ClutterActor*) self->priv->_child, &x, &y);
			unity_drag_controller_start_drag (drag_controller, (UnityDragModel*) self, (*event).button.x - x, (*event).button.y - y);
			self->button_down = FALSE;
			result = TRUE;
			_g_object_unref0 (drag_controller);
			return result;
		}
	}
	result = FALSE;
	_g_object_unref0 (drag_controller);
	return result;
}


UnityLauncherScrollerChild* unity_launcher_scroller_child_controller_get_child (UnityLauncherScrollerChildController* self) {
	UnityLauncherScrollerChild* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_child;
	return result;
}


static void unity_launcher_scroller_child_controller_set_child (UnityLauncherScrollerChildController* self, UnityLauncherScrollerChild* value) {
	UnityLauncherScrollerChild* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_child = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_child), _tmp0_);
	g_object_notify ((GObject *) self, "child");
}


static gboolean _unity_launcher_scroller_child_controller_on_press_event_clutter_actor_button_press_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_launcher_scroller_child_controller_on_press_event (self, event);
	return result;
}


static gboolean _unity_launcher_scroller_child_controller_on_release_event_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_launcher_scroller_child_controller_on_release_event (self, event);
	return result;
}


static gboolean _unity_launcher_scroller_child_controller_on_enter_event_clutter_actor_enter_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_launcher_scroller_child_controller_on_enter_event (self, event);
	return result;
}


static gboolean _unity_launcher_scroller_child_controller_on_leave_event_clutter_actor_leave_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_launcher_scroller_child_controller_on_leave_event (self, event);
	return result;
}


static gboolean _unity_launcher_scroller_child_controller_on_motion_event_clutter_actor_motion_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = unity_launcher_scroller_child_controller_on_motion_event (self, event);
	return result;
}


static GObject * unity_launcher_scroller_child_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityLauncherScrollerChildController * self;
	parent_class = G_OBJECT_CLASS (unity_launcher_scroller_child_controller_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER (obj);
	{
		UnityLauncherScrollerChildController* _tmp0_;
		ClutterAnimation* anim;
		self->priv->_child->controller = (_tmp0_ = _g_object_ref0 (self), _g_object_unref0 (self->priv->_child->controller), _tmp0_);
		g_signal_connect_object ((ClutterActor*) self->priv->_child, "button-press-event", (GCallback) _unity_launcher_scroller_child_controller_on_press_event_clutter_actor_button_press_event, self, 0);
		g_signal_connect_object ((ClutterActor*) self->priv->_child, "button-release-event", (GCallback) _unity_launcher_scroller_child_controller_on_release_event_clutter_actor_button_release_event, self, 0);
		g_signal_connect_object ((ClutterActor*) self->priv->_child, "enter-event", (GCallback) _unity_launcher_scroller_child_controller_on_enter_event_clutter_actor_enter_event, self, 0);
		g_signal_connect_object ((ClutterActor*) self->priv->_child, "leave-event", (GCallback) _unity_launcher_scroller_child_controller_on_leave_event_clutter_actor_leave_event, self, 0);
		g_signal_connect_object ((ClutterActor*) self->priv->_child, "motion-event", (GCallback) _unity_launcher_scroller_child_controller_on_motion_event_clutter_actor_motion_event, self, 0);
		clutter_actor_set_reactive ((ClutterActor*) self->priv->_child, TRUE);
		clutter_actor_set_opacity ((ClutterActor*) self->priv->_child, (guint8) 0);
		anim = _g_object_ref0 (clutter_actor_animate ((ClutterActor*) self->priv->_child, (gulong) CLUTTER_EASE_IN_QUAD, UNITY_LAUNCHER_SHORT_DELAY, "opacity", 0xff, NULL));
		_g_object_unref0 (anim);
	}
	return obj;
}


static void unity_launcher_scroller_child_controller_class_init (UnityLauncherScrollerChildControllerClass * klass) {
	unity_launcher_scroller_child_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityLauncherScrollerChildControllerPrivate));
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->get_menu_shortcuts = unity_launcher_scroller_child_controller_real_get_menu_shortcuts;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->get_menu_shortcut_actions = unity_launcher_scroller_child_controller_real_get_menu_shortcut_actions;
	UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CLASS (klass)->activate = unity_launcher_scroller_child_controller_real_activate;
	G_OBJECT_CLASS (klass)->get_property = unity_launcher_scroller_child_controller_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_launcher_scroller_child_controller_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_launcher_scroller_child_controller_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_launcher_scroller_child_controller_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CHILD, g_param_spec_object ("child", "child", "child", UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_signal_new ("request_removal", UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	g_signal_new ("closed", UNITY_LAUNCHER_TYPE_SCROLLER_CHILD_CONTROLLER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}


static void unity_launcher_scroller_child_controller_unity_drag_model_interface_init (UnityDragModelIface * iface) {
	unity_launcher_scroller_child_controller_unity_drag_model_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_icon = unity_launcher_scroller_child_controller_real_get_icon;
	iface->get_drag_data = unity_launcher_scroller_child_controller_real_get_drag_data;
}


static void unity_launcher_scroller_child_controller_instance_init (UnityLauncherScrollerChildController * self) {
	self->priv = UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_GET_PRIVATE (self);
	self->name = g_strdup ("If you can read this, file a bug!!");
	self->last_press_time = (guint32) 0;
	self->button_down = FALSE;
	self->click_start_pos = 0.0f;
	self->drag_sensitivity = 7;
}


static void unity_launcher_scroller_child_controller_finalize (GObject* obj) {
	UnityLauncherScrollerChildController * self;
	self = UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER (obj);
	_g_object_unref0 (self->priv->_child);
	_g_free0 (self->name);
	G_OBJECT_CLASS (unity_launcher_scroller_child_controller_parent_class)->finalize (obj);
}


GType unity_launcher_scroller_child_controller_get_type (void) {
	static volatile gsize unity_launcher_scroller_child_controller_type_id__volatile = 0;
	if (g_once_init_enter (&unity_launcher_scroller_child_controller_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityLauncherScrollerChildControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_launcher_scroller_child_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityLauncherScrollerChildController), 0, (GInstanceInitFunc) unity_launcher_scroller_child_controller_instance_init, NULL };
		static const GInterfaceInfo unity_drag_model_info = { (GInterfaceInitFunc) unity_launcher_scroller_child_controller_unity_drag_model_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType unity_launcher_scroller_child_controller_type_id;
		unity_launcher_scroller_child_controller_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityLauncherScrollerChildController", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_type_add_interface_static (unity_launcher_scroller_child_controller_type_id, UNITY_DRAG_TYPE_MODEL, &unity_drag_model_info);
		g_once_init_leave (&unity_launcher_scroller_child_controller_type_id__volatile, unity_launcher_scroller_child_controller_type_id);
	}
	return unity_launcher_scroller_child_controller_type_id__volatile;
}


static void unity_launcher_scroller_child_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityLauncherScrollerChildController * self;
	self = UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER (object);
	switch (property_id) {
		case UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CHILD:
		g_value_set_object (value, unity_launcher_scroller_child_controller_get_child (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_launcher_scroller_child_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityLauncherScrollerChildController * self;
	self = UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER (object);
	switch (property_id) {
		case UNITY_LAUNCHER_SCROLLER_CHILD_CONTROLLER_CHILD:
		unity_launcher_scroller_child_controller_set_child (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




