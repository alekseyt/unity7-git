/* drag-view.c generated by valac, the Vala compiler
 * generated from drag-view.vala, do not modify */

/*
 *      drag-view.vala
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
#include <float.h>
#include <math.h>


#define UNITY_DRAG_TYPE_VIEW (unity_drag_view_get_type ())
#define UNITY_DRAG_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_DRAG_TYPE_VIEW, UnityDragView))
#define UNITY_DRAG_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_DRAG_TYPE_VIEW, UnityDragViewClass))
#define UNITY_DRAG_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_DRAG_TYPE_VIEW))
#define UNITY_DRAG_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_DRAG_TYPE_VIEW))
#define UNITY_DRAG_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_DRAG_TYPE_VIEW, UnityDragViewClass))

typedef struct _UnityDragView UnityDragView;
typedef struct _UnityDragViewClass UnityDragViewClass;
typedef struct _UnityDragViewPrivate UnityDragViewPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UnityDragView {
	GObject parent_instance;
	UnityDragViewPrivate * priv;
};

struct _UnityDragViewClass {
	GObjectClass parent_class;
};

struct _UnityDragViewPrivate {
	ClutterStage* _stage;
	ClutterActor* hooked_actor;
	float offset_x;
	float offset_y;
};


static gpointer unity_drag_view_parent_class = NULL;

GType unity_drag_view_get_type (void);
#define UNITY_DRAG_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_DRAG_TYPE_VIEW, UnityDragViewPrivate))
enum  {
	UNITY_DRAG_VIEW_DUMMY_PROPERTY,
	UNITY_DRAG_VIEW_STAGE
};
UnityDragView* unity_drag_view_new (ClutterStage* stage);
UnityDragView* unity_drag_view_construct (GType object_type, ClutterStage* stage);
void unity_drag_view_unhook_actor (UnityDragView* self);
ClutterStage* unity_drag_view_get_stage (UnityDragView* self);
static gboolean unity_drag_view_captured_event (UnityDragView* self, ClutterEvent* event);
static gboolean _unity_drag_view_captured_event_clutter_actor_captured_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
void unity_drag_view_hook_actor_to_cursor (UnityDragView* self, ClutterActor* actor, float offset_x, float offset_y);
static gboolean unity_drag_view_on_motion_event (UnityDragView* self, ClutterEvent* event);
static gboolean unity_drag_view_on_release_event (UnityDragView* self, ClutterEvent* event);
static gboolean _unity_drag_view_on_motion_event_clutter_actor_motion_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static gboolean _unity_drag_view_on_release_event_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static void unity_drag_view_set_stage (UnityDragView* self, ClutterStage* value);
static GObject * unity_drag_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_drag_view_finalize (GObject* obj);
static void unity_drag_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_drag_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static void g_cclosure_user_marshal_VOID__FLOAT_FLOAT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);

#line 37 "drag-view.vala"
UnityDragView* unity_drag_view_construct (GType object_type, ClutterStage* stage) {
#line 94 "drag-view.c"
	UnityDragView * self;
#line 37 "drag-view.vala"
	g_return_val_if_fail (stage != NULL, NULL);
#line 39 "drag-view.vala"
	self = (UnityDragView*) g_object_new (object_type, "stage", stage, NULL);
#line 100 "drag-view.c"
	return self;
}


#line 37 "drag-view.vala"
UnityDragView* unity_drag_view_new (ClutterStage* stage) {
#line 37 "drag-view.vala"
	return unity_drag_view_construct (UNITY_DRAG_TYPE_VIEW, stage);
#line 109 "drag-view.c"
}


#line 67 "drag-view.vala"
static gboolean _unity_drag_view_captured_event_clutter_actor_captured_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
#line 115 "drag-view.c"
	return unity_drag_view_captured_event (self, event);
}


#line 46 "drag-view.vala"
void unity_drag_view_hook_actor_to_cursor (UnityDragView* self, ClutterActor* actor, float offset_x, float offset_y) {
#line 122 "drag-view.c"
	float x = 0.0F;
	float y = 0.0F;
	ClutterActor* _tmp0_;
#line 46 "drag-view.vala"
	g_return_if_fail (self != NULL);
#line 46 "drag-view.vala"
	g_return_if_fail (actor != NULL);
#line 48 "drag-view.vala"
	if (CLUTTER_IS_ACTOR (self->priv->hooked_actor)) {
#line 49 "drag-view.vala"
		g_warning ("drag-view.vala:49: attempted to hook a new actor to dnd without unhooking previous actor");
#line 50 "drag-view.vala"
		unity_drag_view_unhook_actor (self);
#line 136 "drag-view.c"
	}
#line 53 "drag-view.vala"
	self->priv->offset_x = offset_x;
#line 54 "drag-view.vala"
	self->priv->offset_y = offset_y;
#line 56 "drag-view.vala"
	self->priv->hooked_actor = (_tmp0_ = (ClutterActor*) g_object_ref_sink ((ClutterClone*) clutter_clone_new (actor)), _g_object_unref0 (self->priv->hooked_actor), _tmp0_);
#line 57 "drag-view.vala"
	clutter_actor_unparent (self->priv->hooked_actor);
#line 58 "drag-view.vala"
	clutter_container_add_actor ((ClutterContainer*) self->priv->_stage, self->priv->hooked_actor);
#line 60 "drag-view.vala"
	clutter_actor_get_transformed_position (actor, &x, &y);
#line 61 "drag-view.vala"
	clutter_actor_set_position (self->priv->hooked_actor, x, y);
#line 62 "drag-view.vala"
	clutter_actor_show (self->priv->hooked_actor);
#line 64 "drag-view.vala"
	g_signal_connect_object ((ClutterActor*) self->priv->_stage, "captured-event", (GCallback) _unity_drag_view_captured_event_clutter_actor_captured_event, self, 0);
#line 156 "drag-view.c"
}


#line 67 "drag-view.vala"
static gboolean unity_drag_view_captured_event (UnityDragView* self, ClutterEvent* event) {
#line 162 "drag-view.c"
	gboolean result;
#line 67 "drag-view.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 69 "drag-view.vala"
	if ((*event).type == CLUTTER_MOTION) {
#line 71 "drag-view.vala"
		unity_drag_view_on_motion_event (self, event);
#line 170 "drag-view.c"
		result = TRUE;
#line 72 "drag-view.vala"
		return result;
#line 174 "drag-view.c"
	}
#line 74 "drag-view.vala"
	if ((*event).type == CLUTTER_BUTTON_RELEASE) {
#line 76 "drag-view.vala"
		unity_drag_view_on_release_event (self, event);
#line 180 "drag-view.c"
		result = TRUE;
#line 77 "drag-view.vala"
		return result;
#line 184 "drag-view.c"
	}
	result = FALSE;
#line 79 "drag-view.vala"
	return result;
#line 189 "drag-view.c"
}


#line 90 "drag-view.vala"
static gboolean _unity_drag_view_on_motion_event_clutter_actor_motion_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
#line 195 "drag-view.c"
	return unity_drag_view_on_motion_event (self, event);
}


#line 82 "drag-view.vala"
void unity_drag_view_unhook_actor (UnityDragView* self) {
#line 202 "drag-view.c"
	guint _tmp0_;
	ClutterActor* _tmp1_;
#line 82 "drag-view.vala"
	g_return_if_fail (self != NULL);
#line 84 "drag-view.vala"
	if (self->priv->hooked_actor == NULL) {
#line 84 "drag-view.vala"
		return;
#line 211 "drag-view.c"
	}
#line 85 "drag-view.vala"
	clutter_container_remove_actor ((ClutterContainer*) self->priv->_stage, self->priv->hooked_actor);
#line 86 "drag-view.vala"
	g_signal_handlers_disconnect_matched ((ClutterActor*) self->priv->_stage, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, (g_signal_parse_name ("motion-event", CLUTTER_TYPE_ACTOR, &_tmp0_, NULL, FALSE), _tmp0_), 0, NULL, (GCallback) _unity_drag_view_on_motion_event_clutter_actor_motion_event, self);
#line 87 "drag-view.vala"
	self->priv->hooked_actor = (_tmp1_ = NULL, _g_object_unref0 (self->priv->hooked_actor), _tmp1_);
#line 219 "drag-view.c"
}


#line 90 "drag-view.vala"
static gboolean unity_drag_view_on_motion_event (UnityDragView* self, ClutterEvent* event) {
#line 225 "drag-view.c"
	gboolean result;
#line 90 "drag-view.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 92 "drag-view.vala"
	if (!CLUTTER_IS_ACTOR (self->priv->hooked_actor)) {
#line 231 "drag-view.c"
		guint _tmp0_;
#line 93 "drag-view.vala"
		g_signal_handlers_disconnect_matched ((ClutterActor*) self->priv->_stage, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, (g_signal_parse_name ("captured-event", CLUTTER_TYPE_ACTOR, &_tmp0_, NULL, FALSE), _tmp0_), 0, NULL, (GCallback) _unity_drag_view_captured_event_clutter_actor_captured_event, self);
#line 235 "drag-view.c"
		result = FALSE;
#line 94 "drag-view.vala"
		return result;
#line 239 "drag-view.c"
	}
#line 96 "drag-view.vala"
	clutter_actor_set_position (self->priv->hooked_actor, (*event).motion.x - self->priv->offset_x, (*event).motion.y - self->priv->offset_y);
#line 98 "drag-view.vala"
	g_signal_emit_by_name (self, "motion", (*event).motion.x, (*event).motion.y);
#line 245 "drag-view.c"
	result = FALSE;
#line 99 "drag-view.vala"
	return result;
#line 249 "drag-view.c"
}


#line 102 "drag-view.vala"
static gboolean _unity_drag_view_on_release_event_clutter_actor_button_release_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
#line 255 "drag-view.c"
	return unity_drag_view_on_release_event (self, event);
}


#line 102 "drag-view.vala"
static gboolean unity_drag_view_on_release_event (UnityDragView* self, ClutterEvent* event) {
#line 262 "drag-view.c"
	gboolean result;
#line 102 "drag-view.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 104 "drag-view.vala"
	if (!CLUTTER_IS_ACTOR (self->priv->hooked_actor)) {
#line 268 "drag-view.c"
		guint _tmp0_;
#line 105 "drag-view.vala"
		g_signal_handlers_disconnect_matched ((ClutterActor*) self->priv->_stage, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, (g_signal_parse_name ("button-release-event", CLUTTER_TYPE_ACTOR, &_tmp0_, NULL, FALSE), _tmp0_), 0, NULL, (GCallback) _unity_drag_view_on_release_event_clutter_actor_button_release_event, self);
#line 272 "drag-view.c"
		result = FALSE;
#line 106 "drag-view.vala"
		return result;
#line 276 "drag-view.c"
	}
#line 108 "drag-view.vala"
	unity_drag_view_unhook_actor (self);
#line 109 "drag-view.vala"
	g_signal_emit_by_name (self, "end", (*event).button.x, (*event).button.y);
#line 282 "drag-view.c"
	result = FALSE;
#line 110 "drag-view.vala"
	return result;
#line 286 "drag-view.c"
}


ClutterStage* unity_drag_view_get_stage (UnityDragView* self) {
	ClutterStage* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_stage;
#line 29 "drag-view.vala"
	return result;
#line 296 "drag-view.c"
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_drag_view_set_stage (UnityDragView* self, ClutterStage* value) {
	ClutterStage* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_stage = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_stage), _tmp0_);
	g_object_notify ((GObject *) self, "stage");
}


static GObject * unity_drag_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityDragView * self;
	parent_class = G_OBJECT_CLASS (unity_drag_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_DRAG_VIEW (obj);
	{
	}
	return obj;
}


static void unity_drag_view_class_init (UnityDragViewClass * klass) {
	unity_drag_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityDragViewPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_drag_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_drag_view_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_drag_view_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_drag_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_DRAG_VIEW_STAGE, g_param_spec_object ("stage", "stage", "stage", CLUTTER_TYPE_STAGE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_signal_new ("motion", UNITY_DRAG_TYPE_VIEW, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__FLOAT_FLOAT, G_TYPE_NONE, 2, G_TYPE_FLOAT, G_TYPE_FLOAT);
	g_signal_new ("end", UNITY_DRAG_TYPE_VIEW, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__FLOAT_FLOAT, G_TYPE_NONE, 2, G_TYPE_FLOAT, G_TYPE_FLOAT);
}


static void unity_drag_view_instance_init (UnityDragView * self) {
	self->priv = UNITY_DRAG_VIEW_GET_PRIVATE (self);
}


static void unity_drag_view_finalize (GObject* obj) {
	UnityDragView * self;
	self = UNITY_DRAG_VIEW (obj);
	_g_object_unref0 (self->priv->_stage);
	_g_object_unref0 (self->priv->hooked_actor);
	G_OBJECT_CLASS (unity_drag_view_parent_class)->finalize (obj);
}


GType unity_drag_view_get_type (void) {
	static GType unity_drag_view_type_id = 0;
	if (unity_drag_view_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityDragViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_drag_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityDragView), 0, (GInstanceInitFunc) unity_drag_view_instance_init, NULL };
		unity_drag_view_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityDragView", &g_define_type_info, 0);
	}
	return unity_drag_view_type_id;
}


static void unity_drag_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityDragView * self;
	self = UNITY_DRAG_VIEW (object);
	switch (property_id) {
		case UNITY_DRAG_VIEW_STAGE:
		g_value_set_object (value, unity_drag_view_get_stage (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_drag_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityDragView * self;
	self = UNITY_DRAG_VIEW (object);
	switch (property_id) {
		case UNITY_DRAG_VIEW_STAGE:
		unity_drag_view_set_stage (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



static void g_cclosure_user_marshal_VOID__FLOAT_FLOAT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__FLOAT_FLOAT) (gpointer data1, float arg_1, float arg_2, gpointer data2);
	register GMarshalFunc_VOID__FLOAT_FLOAT callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__FLOAT_FLOAT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_float (param_values + 1), g_value_get_float (param_values + 2), data2);
}



