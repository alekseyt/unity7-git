/* drag-controller.c generated by valac, the Vala compiler
 * generated from drag-controller.vala, do not modify */

/*
 *      unity-drag.vala
 *      Copyright (C) 2010 Canonical Ltd
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
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
#include <clutter/clutter.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define UNITY_DRAG_TYPE_MODEL (unity_drag_model_get_type ())
#define UNITY_DRAG_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_DRAG_TYPE_MODEL, UnityDragModel))
#define UNITY_DRAG_IS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_DRAG_TYPE_MODEL))
#define UNITY_DRAG_MODEL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_DRAG_TYPE_MODEL, UnityDragModelIface))

typedef struct _UnityDragModel UnityDragModel;
typedef struct _UnityDragModelIface UnityDragModelIface;

#define UNITY_DRAG_TYPE_CONTROLLER (unity_drag_controller_get_type ())
#define UNITY_DRAG_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_DRAG_TYPE_CONTROLLER, UnityDragController))
#define UNITY_DRAG_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_DRAG_TYPE_CONTROLLER, UnityDragControllerClass))
#define UNITY_DRAG_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_DRAG_TYPE_CONTROLLER))
#define UNITY_DRAG_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_DRAG_TYPE_CONTROLLER))
#define UNITY_DRAG_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_DRAG_TYPE_CONTROLLER, UnityDragControllerClass))

typedef struct _UnityDragController UnityDragController;
typedef struct _UnityDragControllerClass UnityDragControllerClass;
typedef struct _UnityDragControllerPrivate UnityDragControllerPrivate;

#define UNITY_DRAG_TYPE_VIEW (unity_drag_view_get_type ())
#define UNITY_DRAG_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_DRAG_TYPE_VIEW, UnityDragView))
#define UNITY_DRAG_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_DRAG_TYPE_VIEW, UnityDragViewClass))
#define UNITY_DRAG_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_DRAG_TYPE_VIEW))
#define UNITY_DRAG_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_DRAG_TYPE_VIEW))
#define UNITY_DRAG_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_DRAG_TYPE_VIEW, UnityDragViewClass))

typedef struct _UnityDragView UnityDragView;
typedef struct _UnityDragViewClass UnityDragViewClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_TYPE_SHELL (unity_shell_get_type ())
#define UNITY_SHELL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_SHELL, UnityShell))
#define UNITY_IS_SHELL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_SHELL))
#define UNITY_SHELL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_TYPE_SHELL, UnityShellIface))

typedef struct _UnityShell UnityShell;
typedef struct _UnityShellIface UnityShellIface;

#define UNITY_TYPE_SHELL_MODE (unity_shell_mode_get_type ())

struct _UnityDragModelIface {
	GTypeInterface parent_iface;
	ClutterActor* (*get_icon) (UnityDragModel* self);
	char* (*get_drag_data) (UnityDragModel* self);
};

struct _UnityDragController {
	GObject parent_instance;
	UnityDragControllerPrivate * priv;
};

struct _UnityDragControllerClass {
	GObjectClass parent_class;
};

struct _UnityDragControllerPrivate {
	UnityDragModel* model;
	UnityDragView* view;
	gboolean _is_dragging;
};

typedef enum  {
	UNITY_SHELL_MODE_UNDERLAY,
	UNITY_SHELL_MODE_OVERLAY
} UnityShellMode;

struct _UnityShellIface {
	GTypeInterface parent_iface;
	UnityShellMode (*get_mode) (UnityShell* self);
	ClutterStage* (*get_stage) (UnityShell* self);
	void (*show_unity) (UnityShell* self);
	gint (*get_indicators_width) (UnityShell* self);
	void (*ensure_input_region) (UnityShell* self);
	void (*grab_keyboard) (UnityShell* self, gboolean grab, guint32 timestamp);
	gboolean (*get_menus_swallow_events) (UnityShell* self);
};


extern UnityDragController* unity_drag_controller_singleton;
UnityDragController* unity_drag_controller_singleton = NULL;
extern UnityShell* unity_global_shell;
static gpointer unity_drag_controller_parent_class = NULL;

GType unity_drag_model_get_type (void);
ClutterActor* unity_drag_model_get_icon (UnityDragModel* self);
char* unity_drag_model_get_drag_data (UnityDragModel* self);
GType unity_drag_controller_get_type (void);
GType unity_drag_view_get_type (void);
#define UNITY_DRAG_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_DRAG_TYPE_CONTROLLER, UnityDragControllerPrivate))
enum  {
	UNITY_DRAG_CONTROLLER_DUMMY_PROPERTY,
	UNITY_DRAG_CONTROLLER_IS_DRAGGING
};
UnityDragController* unity_drag_controller_new (void);
UnityDragController* unity_drag_controller_construct (GType object_type);
UnityDragController* unity_drag_controller_get_default (void);
UnityDragView* unity_drag_view_new (ClutterStage* stage);
UnityDragView* unity_drag_view_construct (GType object_type, ClutterStage* stage);
void unity_drag_view_hook_actor_to_cursor (UnityDragView* self, ClutterActor* actor, float offset_x, float offset_y);
static void unity_drag_controller_on_view_motion (UnityDragController* self, float x, float y);
static void _unity_drag_controller_on_view_motion_unity_drag_view_motion (UnityDragView* _sender, float x, float y, gpointer self);
static void unity_drag_controller_on_view_end (UnityDragController* self, float x, float y);
static void _unity_drag_controller_on_view_end_unity_drag_view_end (UnityDragView* _sender, float x, float y, gpointer self);
GType unity_shell_mode_get_type (void);
GType unity_shell_get_type (void);
void unity_shell_ensure_input_region (UnityShell* self);
void unity_drag_controller_start_drag (UnityDragController* self, UnityDragModel* model, float offset_x, float offset_y);
void unity_drag_view_unhook_actor (UnityDragView* self);
gboolean unity_drag_controller_get_is_dragging (UnityDragController* self);
static GObject * unity_drag_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_drag_controller_finalize (GObject* obj);
static void unity_drag_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);


static void g_cclosure_user_marshal_VOID__OBJECT_FLOAT_FLOAT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

#line 29 "drag-controller.vala"
ClutterActor* unity_drag_model_get_icon (UnityDragModel* self) {
#line 29 "drag-controller.vala"
	return UNITY_DRAG_MODEL_GET_INTERFACE (self)->get_icon (self);
#line 157 "drag-controller.c"
}


#line 30 "drag-controller.vala"
char* unity_drag_model_get_drag_data (UnityDragModel* self) {
#line 30 "drag-controller.vala"
	return UNITY_DRAG_MODEL_GET_INTERFACE (self)->get_drag_data (self);
#line 165 "drag-controller.c"
}


static void unity_drag_model_base_init (UnityDragModelIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType unity_drag_model_get_type (void) {
	static GType unity_drag_model_type_id = 0;
	if (unity_drag_model_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityDragModelIface), (GBaseInitFunc) unity_drag_model_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		unity_drag_model_type_id = g_type_register_static (G_TYPE_INTERFACE, "UnityDragModel", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (unity_drag_model_type_id, G_TYPE_OBJECT);
	}
	return unity_drag_model_type_id;
}


#line 38 "drag-controller.vala"
UnityDragController* unity_drag_controller_get_default (void) {
#line 190 "drag-controller.c"
	UnityDragController* result;
#line 40 "drag-controller.vala"
	if (unity_drag_controller_singleton == NULL) {
#line 194 "drag-controller.c"
		UnityDragController* _tmp0_;
#line 41 "drag-controller.vala"
		unity_drag_controller_singleton = (_tmp0_ = unity_drag_controller_new (), _g_object_unref0 (unity_drag_controller_singleton), _tmp0_);
#line 198 "drag-controller.c"
	}
	result = unity_drag_controller_singleton;
#line 43 "drag-controller.vala"
	return result;
#line 203 "drag-controller.c"
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 82 "drag-controller.vala"
static void _unity_drag_controller_on_view_motion_unity_drag_view_motion (UnityDragView* _sender, float x, float y, gpointer self) {
#line 214 "drag-controller.c"
	unity_drag_controller_on_view_motion (self, x, y);
}


#line 87 "drag-controller.vala"
static void _unity_drag_controller_on_view_end_unity_drag_view_end (UnityDragView* _sender, float x, float y, gpointer self) {
#line 221 "drag-controller.c"
	unity_drag_controller_on_view_end (self, x, y);
}


#line 68 "drag-controller.vala"
void unity_drag_controller_start_drag (UnityDragController* self, UnityDragModel* model, float offset_x, float offset_y) {
#line 228 "drag-controller.c"
	ClutterActor* _tmp3_;
	UnityDragModel* _tmp4_;
#line 68 "drag-controller.vala"
	g_return_if_fail (self != NULL);
#line 68 "drag-controller.vala"
	g_return_if_fail (model != NULL);
#line 70 "drag-controller.vala"
	if (!UNITY_DRAG_IS_VIEW (self->priv->view)) {
#line 237 "drag-controller.c"
		UnityDragView* _tmp2_;
		ClutterActor* _tmp0_;
		ClutterActor* _tmp1_;
#line 71 "drag-controller.vala"
		self->priv->view = (_tmp2_ = unity_drag_view_new ((_tmp1_ = clutter_actor_get_stage (_tmp0_ = unity_drag_model_get_icon (model)), CLUTTER_IS_STAGE (_tmp1_) ? ((ClutterStage*) _tmp1_) : NULL)), _g_object_unref0 (self->priv->view), _tmp2_);
#line 243 "drag-controller.c"
		_g_object_unref0 (_tmp0_);
	}
#line 73 "drag-controller.vala"
	unity_drag_view_hook_actor_to_cursor (self->priv->view, _tmp3_ = unity_drag_model_get_icon (model), offset_x, offset_y);
#line 248 "drag-controller.c"
	_g_object_unref0 (_tmp3_);
#line 74 "drag-controller.vala"
	self->priv->model = (_tmp4_ = _g_object_ref0 (model), _g_object_unref0 (self->priv->model), _tmp4_);
#line 75 "drag-controller.vala"
	g_signal_emit_by_name (self, "drag-start", model);
#line 76 "drag-controller.vala"
	g_signal_connect_object (self->priv->view, "motion", (GCallback) _unity_drag_controller_on_view_motion_unity_drag_view_motion, self, 0);
#line 77 "drag-controller.vala"
	g_signal_connect_object (self->priv->view, "end", (GCallback) _unity_drag_controller_on_view_end_unity_drag_view_end, self, 0);
#line 78 "drag-controller.vala"
	self->priv->_is_dragging = TRUE;
#line 79 "drag-controller.vala"
	unity_shell_ensure_input_region (unity_global_shell);
#line 262 "drag-controller.c"
}


#line 82 "drag-controller.vala"
static void unity_drag_controller_on_view_motion (UnityDragController* self, float x, float y) {
#line 82 "drag-controller.vala"
	g_return_if_fail (self != NULL);
#line 84 "drag-controller.vala"
	g_signal_emit_by_name (self, "drag-motion", self->priv->model, x, y);
#line 272 "drag-controller.c"
}


#line 87 "drag-controller.vala"
static void unity_drag_controller_on_view_end (UnityDragController* self, float x, float y) {
#line 278 "drag-controller.c"
	guint _tmp0_;
	guint _tmp1_;
	UnityDragModel* _tmp2_;
#line 87 "drag-controller.vala"
	g_return_if_fail (self != NULL);
#line 89 "drag-controller.vala"
	unity_drag_view_unhook_actor (self->priv->view);
#line 90 "drag-controller.vala"
	g_signal_emit_by_name (self, "drag-drop", self->priv->model, x, y);
#line 91 "drag-controller.vala"
	g_signal_handlers_disconnect_matched (self->priv->view, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, (g_signal_parse_name ("motion", UNITY_DRAG_TYPE_VIEW, &_tmp0_, NULL, FALSE), _tmp0_), 0, NULL, (GCallback) _unity_drag_controller_on_view_motion_unity_drag_view_motion, self);
#line 92 "drag-controller.vala"
	g_signal_handlers_disconnect_matched (self->priv->view, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, (g_signal_parse_name ("end", UNITY_DRAG_TYPE_VIEW, &_tmp1_, NULL, FALSE), _tmp1_), 0, NULL, (GCallback) _unity_drag_controller_on_view_end_unity_drag_view_end, self);
#line 93 "drag-controller.vala"
	self->priv->model = (_tmp2_ = NULL, _g_object_unref0 (self->priv->model), _tmp2_);
#line 94 "drag-controller.vala"
	self->priv->_is_dragging = FALSE;
#line 95 "drag-controller.vala"
	unity_shell_ensure_input_region (unity_global_shell);
#line 298 "drag-controller.c"
}


#line 35 "drag-controller.vala"
UnityDragController* unity_drag_controller_construct (GType object_type) {
#line 304 "drag-controller.c"
	UnityDragController * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


#line 35 "drag-controller.vala"
UnityDragController* unity_drag_controller_new (void) {
#line 35 "drag-controller.vala"
	return unity_drag_controller_construct (UNITY_DRAG_TYPE_CONTROLLER);
#line 315 "drag-controller.c"
}


gboolean unity_drag_controller_get_is_dragging (UnityDragController* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_dragging;
#line 59 "drag-controller.vala"
	return result;
#line 325 "drag-controller.c"
}


static GObject * unity_drag_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityDragController * self;
	parent_class = G_OBJECT_CLASS (unity_drag_controller_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_DRAG_CONTROLLER (obj);
	{
#line 65 "drag-controller.vala"
		self->priv->_is_dragging = FALSE;
#line 339 "drag-controller.c"
	}
	return obj;
}


static void unity_drag_controller_class_init (UnityDragControllerClass * klass) {
	unity_drag_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityDragControllerPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_drag_controller_get_property;
	G_OBJECT_CLASS (klass)->constructor = unity_drag_controller_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_drag_controller_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_DRAG_CONTROLLER_IS_DRAGGING, g_param_spec_boolean ("is-dragging", "is-dragging", "is-dragging", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_signal_new ("drag_start", UNITY_DRAG_TYPE_CONTROLLER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, UNITY_DRAG_TYPE_MODEL);
	g_signal_new ("drag_motion", UNITY_DRAG_TYPE_CONTROLLER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_FLOAT_FLOAT, G_TYPE_NONE, 3, UNITY_DRAG_TYPE_MODEL, G_TYPE_FLOAT, G_TYPE_FLOAT);
	g_signal_new ("drag_drop", UNITY_DRAG_TYPE_CONTROLLER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_FLOAT_FLOAT, G_TYPE_NONE, 3, UNITY_DRAG_TYPE_MODEL, G_TYPE_FLOAT, G_TYPE_FLOAT);
}


static void unity_drag_controller_instance_init (UnityDragController * self) {
	self->priv = UNITY_DRAG_CONTROLLER_GET_PRIVATE (self);
}


static void unity_drag_controller_finalize (GObject* obj) {
	UnityDragController * self;
	self = UNITY_DRAG_CONTROLLER (obj);
	_g_object_unref0 (self->priv->model);
	_g_object_unref0 (self->priv->view);
	G_OBJECT_CLASS (unity_drag_controller_parent_class)->finalize (obj);
}


GType unity_drag_controller_get_type (void) {
	static GType unity_drag_controller_type_id = 0;
	if (unity_drag_controller_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityDragControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_drag_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityDragController), 0, (GInstanceInitFunc) unity_drag_controller_instance_init, NULL };
		unity_drag_controller_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityDragController", &g_define_type_info, 0);
	}
	return unity_drag_controller_type_id;
}


static void unity_drag_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityDragController * self;
	self = UNITY_DRAG_CONTROLLER (object);
	switch (property_id) {
		case UNITY_DRAG_CONTROLLER_IS_DRAGGING:
		g_value_set_boolean (value, unity_drag_controller_get_is_dragging (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



static void g_cclosure_user_marshal_VOID__OBJECT_FLOAT_FLOAT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__OBJECT_FLOAT_FLOAT) (gpointer data1, gpointer arg_1, float arg_2, float arg_3, gpointer data2);
	register GMarshalFunc_VOID__OBJECT_FLOAT_FLOAT callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 4);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__OBJECT_FLOAT_FLOAT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_object (param_values + 1), g_value_get_float (param_values + 2), g_value_get_float (param_values + 3), data2);
}



