/* test-unity.c generated by valac, the Vala compiler
 * generated from test-unity.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/*
 * Copyright (C) 2009 Canonical Ltd
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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <clutk/clutk.h>
#include <unity-static.h>
#include <clutter/clutter.h>
#include <unity-places/unity-places.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <gobject/gvaluecollector.h>


#define TYPE_MAIN (main_get_type ())
#define MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MAIN, Main))
#define MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MAIN, MainClass))
#define IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MAIN))
#define IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MAIN))
#define MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MAIN, MainClass))

typedef struct _Main Main;
typedef struct _MainClass MainClass;
typedef struct _MainPrivate MainPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define MAIN_TYPE_TEST_PLACE (main_test_place_get_type ())
#define MAIN_TEST_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MAIN_TYPE_TEST_PLACE, MainTestPlace))
#define MAIN_TEST_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MAIN_TYPE_TEST_PLACE, MainTestPlaceClass))
#define MAIN_IS_TEST_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MAIN_TYPE_TEST_PLACE))
#define MAIN_IS_TEST_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MAIN_TYPE_TEST_PLACE))
#define MAIN_TEST_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MAIN_TYPE_TEST_PLACE, MainTestPlaceClass))

typedef struct _MainTestPlace MainTestPlace;
typedef struct _MainTestPlaceClass MainTestPlaceClass;
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))
typedef struct _MainTestPlacePrivate MainTestPlacePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _ParamSpecMain ParamSpecMain;

struct _Main {
	GTypeInstance parent_instance;
	volatile int ref_count;
	MainPrivate * priv;
};

struct _MainClass {
	GTypeClass parent_class;
	void (*finalize) (Main *self);
};

struct _MainTestPlace {
	UnityPlace parent_instance;
	MainTestPlacePrivate * priv;
};

struct _MainTestPlaceClass {
	UnityPlaceClass parent_class;
};

struct _ParamSpecMain {
	GParamSpec parent_instance;
};


static gpointer main_test_place_parent_class = NULL;
static gpointer main_parent_class = NULL;

gpointer main_ref (gpointer instance);
void main_unref (gpointer instance);
GParamSpec* param_spec_main (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_main (GValue* value, gpointer v_object);
gpointer value_get_main (const GValue* value);
GType main_get_type (void);
enum  {
	MAIN_DUMMY_PROPERTY
};
#define MAIN_firefox_desktop TESTDIR "/firefox.desktop"
static void main_add_launcher_tests (void);
static gboolean _lambda10_ (void);
static gboolean __lambda10__gsource_func (gpointer self);
gint main_main (char** args, int args_length1);
static void _lambda0_ (void);
static void __lambda0__gcallback (void);
static void _lambda1_ (void);
static void __lambda1__gcallback (void);
static void _lambda2_ (void);
static void __lambda2__gcallback (void);
static void _lambda3_ (void);
static void __lambda3__gcallback (void);
static void _lambda4_ (void);
static void __lambda4__gcallback (void);
static void _lambda5_ (void);
static void __lambda5__gcallback (void);
static void _lambda6_ (void);
static void __lambda6__gcallback (void);
static void _lambda7_ (void);
static void __lambda7__gcallback (void);
MainTestPlace* main_test_place_new (void);
MainTestPlace* main_test_place_construct (GType object_type);
GType main_test_place_get_type (void);
static void _lambda8_ (void);
static void __lambda8__gcallback (void);
Main* main_new (void);
Main* main_construct (GType object_type);
enum  {
	MAIN_TEST_PLACE_DUMMY_PROPERTY
};
static void _lambda9_ (gboolean a, MainTestPlace* self);
static void __lambda9__unity_place_is_active (UnityPlace* _sender, gboolean is_active, gpointer self);
static GObject * main_test_place_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void main_finalize (Main* obj);



#line 33 "test-unity.vala"
static gboolean _lambda10_ (void) {
#line 144 "test-unity.c"
	gboolean result;
#line 34 "test-unity.vala"
	g_test_run ();
#line 35 "test-unity.vala"
	gtk_main_quit ();
#line 150 "test-unity.c"
	result = FALSE;
#line 36 "test-unity.vala"
	return result;
#line 154 "test-unity.c"
}


#line 33 "test-unity.vala"
static gboolean __lambda10__gsource_func (gpointer self) {
#line 160 "test-unity.c"
	return _lambda10_ ();
}


#line 25 "test-unity.vala"
gint main_main (char** args, int args_length1) {
#line 167 "test-unity.c"
	gint result;
#line 27 "test-unity.vala"
	gtk_init (&args_length1, &args);
#line 28 "test-unity.vala"
	ctk_init (&args_length1, &args);
#line 29 "test-unity.vala"
	g_test_init (&args_length1, &args, NULL);
#line 31 "test-unity.vala"
	main_add_launcher_tests ();
#line 33 "test-unity.vala"
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, __lambda10__gsource_func, NULL, NULL);
#line 40 "test-unity.vala"
	gtk_main ();
#line 181 "test-unity.c"
	result = 0;
#line 42 "test-unity.vala"
	return result;
#line 185 "test-unity.c"
}


#line 25 "test-unity.vala"
int main (int argc, char ** argv) {
#line 25 "test-unity.vala"
	g_type_init ();
#line 25 "test-unity.vala"
	return main_main (argv, argc);
#line 195 "test-unity.c"
}


#line 47 "test-unity.vala"
static void _lambda0_ (void) {
#line 201 "test-unity.c"
	UnityUnderlayWindow* window;
#line 48 "test-unity.vala"
	window = g_object_ref_sink (unity_underlay_window_new (FALSE, 0, 0));
#line 50 "test-unity.vala"
	g_assert (GTK_IS_WINDOW (window));
#line 52 "test-unity.vala"
	gtk_widget_show ((GtkWidget*) window);
#line 53 "test-unity.vala"
	g_assert (gtk_widget_get_visible ((GtkWidget*) window));
#line 211 "test-unity.c"
	_g_object_unref0 (window);
}


#line 47 "test-unity.vala"
static void __lambda0__gcallback (void) {
#line 218 "test-unity.c"
	_lambda0_ ();
}


#line 57 "test-unity.vala"
static void _lambda1_ (void) {
#line 225 "test-unity.c"
	UnityBackground* bg;
#line 58 "test-unity.vala"
	bg = g_object_ref_sink (unity_background_new ());
#line 59 "test-unity.vala"
	g_assert (CLUTTER_IS_ACTOR (bg));
#line 231 "test-unity.c"
	_g_object_unref0 (bg);
}


#line 57 "test-unity.vala"
static void __lambda1__gcallback (void) {
#line 238 "test-unity.c"
	_lambda1_ ();
}


#line 61 "test-unity.vala"
static void _lambda2_ (void) {
#line 245 "test-unity.c"
	UnityQuicklauncherModelsApplicationModel* model;
#line 62 "test-unity.vala"
	model = unity_quicklauncher_models_application_model_new (MAIN_firefox_desktop);
#line 63 "test-unity.vala"
	g_assert (UNITY_QUICKLAUNCHER_MODELS_IS_APPLICATION_MODEL (model));
#line 251 "test-unity.c"
	_g_object_unref0 (model);
}


#line 61 "test-unity.vala"
static void __lambda2__gcallback (void) {
#line 258 "test-unity.c"
	_lambda2_ ();
}


#line 66 "test-unity.vala"
static void _lambda3_ (void) {
#line 265 "test-unity.c"
	UnityQuicklauncherModelsApplicationModel* model;
	UnityQuicklauncherLauncherView* view;
#line 67 "test-unity.vala"
	model = unity_quicklauncher_models_application_model_new (MAIN_firefox_desktop);
#line 68 "test-unity.vala"
	view = g_object_ref_sink (unity_quicklauncher_launcher_view_new ((UnityQuicklauncherModelsLauncherModel*) model));
#line 69 "test-unity.vala"
	g_assert (UNITY_QUICKLAUNCHER_IS_LAUNCHER_VIEW (view));
#line 274 "test-unity.c"
	_g_object_unref0 (model);
	_g_object_unref0 (view);
}


#line 66 "test-unity.vala"
static void __lambda3__gcallback (void) {
#line 282 "test-unity.c"
	_lambda3_ ();
}


#line 72 "test-unity.vala"
static void _lambda4_ (void) {
#line 289 "test-unity.c"
	UnityQuicklauncherQuicklistMenu* view;
#line 73 "test-unity.vala"
	view = g_object_ref_sink (unity_quicklauncher_quicklist_menu_new ());
#line 74 "test-unity.vala"
	g_assert (UNITY_QUICKLAUNCHER_IS_QUICKLIST_MENU (view));
#line 295 "test-unity.c"
	_g_object_unref0 (view);
}


#line 72 "test-unity.vala"
static void __lambda4__gcallback (void) {
#line 302 "test-unity.c"
	_lambda4_ ();
}


#line 77 "test-unity.vala"
static void _lambda5_ (void) {
#line 309 "test-unity.c"
	UnityQuicklauncherManager* manager;
#line 78 "test-unity.vala"
	manager = g_object_ref_sink (unity_quicklauncher_manager_new ());
#line 79 "test-unity.vala"
	g_assert (UNITY_QUICKLAUNCHER_IS_MANAGER (manager));
#line 315 "test-unity.c"
	_g_object_unref0 (manager);
}


#line 77 "test-unity.vala"
static void __lambda5__gcallback (void) {
#line 322 "test-unity.c"
	_lambda5_ ();
}


#line 82 "test-unity.vala"
static void _lambda6_ (void) {
#line 329 "test-unity.c"
	UnityQuicklauncherPrism* webapp;
#line 83 "test-unity.vala"
	webapp = unity_quicklauncher_prism_new ("http://www.google.com", "/tmp/icon.svg");
#line 84 "test-unity.vala"
	g_assert (UNITY_QUICKLAUNCHER_IS_PRISM (webapp));
#line 335 "test-unity.c"
	_g_object_unref0 (webapp);
}


#line 82 "test-unity.vala"
static void __lambda6__gcallback (void) {
#line 342 "test-unity.c"
	_lambda6_ ();
}


#line 87 "test-unity.vala"
static void _lambda7_ (void) {
#line 349 "test-unity.c"
	UnityWidgetsScroller* scroller;
	UnityWidgetsScroller* _tmp0_;
#line 88 "test-unity.vala"
	scroller = g_object_ref_sink (unity_widgets_scroller_new (CTK_ORIENTATION_VERTICAL, 0));
#line 89 "test-unity.vala"
	g_assert (UNITY_WIDGETS_IS_SCROLLER (scroller));
#line 91 "test-unity.vala"
	scroller = (_tmp0_ = g_object_ref_sink (unity_widgets_scroller_new (CTK_ORIENTATION_HORIZONTAL, 0)), _g_object_unref0 (scroller), _tmp0_);
#line 92 "test-unity.vala"
	g_assert (UNITY_WIDGETS_IS_SCROLLER (scroller));
#line 360 "test-unity.c"
	_g_object_unref0 (scroller);
}


#line 87 "test-unity.vala"
static void __lambda7__gcallback (void) {
#line 367 "test-unity.c"
	_lambda7_ ();
}


#line 95 "test-unity.vala"
static void _lambda8_ (void) {
#line 374 "test-unity.c"
	GError * _inner_error_;
	MainTestPlace* place;
	GMainLoop* loop;
	_inner_error_ = NULL;
#line 96 "test-unity.vala"
	place = main_test_place_new ();
#line 98 "test-unity.vala"
	g_assert (MAIN_IS_TEST_PLACE (place));
#line 100 "test-unity.vala"
	loop = g_main_loop_new (NULL, FALSE);
#line 385 "test-unity.c"
	{
		DBusGConnection* conn;
#line 104 "test-unity.vala"
		conn = dbus_g_bus_get (DBUS_BUS_SESSION, &_inner_error_);
#line 390 "test-unity.c"
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
#line 106 "test-unity.vala"
		utils_register_object_on_dbus (conn, "/com/canonical/Unity/Place", (GObject*) place);
#line 110 "test-unity.vala"
		g_main_loop_run (loop);
#line 398 "test-unity.c"
		_dbus_g_connection_unref0 (conn);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
#line 114 "test-unity.vala"
			g_warning ("test-unity.vala:114: TestPlace error: %s", e->message);
#line 410 "test-unity.c"
			_g_error_free0 (e);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (place);
		_g_main_loop_unref0 (loop);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (place);
	_g_main_loop_unref0 (loop);
}


#line 95 "test-unity.vala"
static void __lambda8__gcallback (void) {
#line 429 "test-unity.c"
	_lambda8_ ();
}


#line 45 "test-unity.vala"
static void main_add_launcher_tests (void) {
#line 47 "test-unity.vala"
	g_test_add_func ("/Unity/Window", __lambda0__gcallback);
#line 57 "test-unity.vala"
	g_test_add_func ("/Unity/Background", __lambda1__gcallback);
#line 61 "test-unity.vala"
	g_test_add_func ("/Unity/Quicklauncher/ApplicationModel", __lambda2__gcallback);
#line 66 "test-unity.vala"
	g_test_add_func ("/Unity/Quicklauncher/LauncherView", __lambda3__gcallback);
#line 72 "test-unity.vala"
	g_test_add_func ("/Unity/Quicklauncher/Quicklist-view", __lambda4__gcallback);
#line 77 "test-unity.vala"
	g_test_add_func ("/Unity/Quicklauncher/Manager", __lambda5__gcallback);
#line 82 "test-unity.vala"
	g_test_add_func ("/Unity/Quicklauncher/Prism", __lambda6__gcallback);
#line 87 "test-unity.vala"
	g_test_add_func ("/Unity/Widgets/Scroller", __lambda7__gcallback);
#line 95 "test-unity.vala"
	g_test_add_func ("/Unity/Places/TestPlace", __lambda8__gcallback);
#line 454 "test-unity.c"
}


#line 22 "test-unity.vala"
Main* main_construct (GType object_type) {
#line 460 "test-unity.c"
	Main* self;
	self = (Main*) g_type_create_instance (object_type);
	return self;
}


#line 22 "test-unity.vala"
Main* main_new (void) {
#line 22 "test-unity.vala"
	return main_construct (TYPE_MAIN);
#line 471 "test-unity.c"
}


#line 121 "test-unity.vala"
MainTestPlace* main_test_place_construct (GType object_type) {
#line 477 "test-unity.c"
	MainTestPlace * self;
#line 123 "test-unity.vala"
	self = (MainTestPlace*) g_object_new (object_type, "name", "neil", "icon-name", "gtk-apply", "tooltip", "hello", NULL);
#line 481 "test-unity.c"
	return self;
}


#line 121 "test-unity.vala"
MainTestPlace* main_test_place_new (void) {
#line 121 "test-unity.vala"
	return main_test_place_construct (MAIN_TYPE_TEST_PLACE);
#line 490 "test-unity.c"
}


#line 35 "glib-2.0.vapi"
static char* bool_to_string (gboolean self) {
#line 496 "test-unity.c"
	char* result;
#line 36 "glib-2.0.vapi"
	if (self) {
#line 500 "test-unity.c"
		result = g_strdup ("true");
#line 37 "glib-2.0.vapi"
		return result;
#line 504 "test-unity.c"
	} else {
		result = g_strdup ("false");
#line 39 "glib-2.0.vapi"
		return result;
#line 509 "test-unity.c"
	}
}


#line 128 "test-unity.vala"
static void _lambda9_ (gboolean a, MainTestPlace* self) {
#line 516 "test-unity.c"
	char* _tmp1_;
	char* _tmp0_;
#line 128 "test-unity.vala"
	g_print ("%s", _tmp1_ = g_strconcat (_tmp0_ = bool_to_string (a), "\n", NULL));
#line 521 "test-unity.c"
	_g_free0 (_tmp1_);
	_g_free0 (_tmp0_);
}


#line 128 "test-unity.vala"
static void __lambda9__unity_place_is_active (UnityPlace* _sender, gboolean is_active, gpointer self) {
#line 529 "test-unity.c"
	_lambda9_ (is_active, self);
}


static GObject * main_test_place_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	MainTestPlace * self;
	parent_class = G_OBJECT_CLASS (main_test_place_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = MAIN_TEST_PLACE (obj);
	{
#line 128 "test-unity.vala"
		g_signal_connect_object ((UnityPlace*) self, "is-active", (GCallback) __lambda9__unity_place_is_active, self, 0);
#line 544 "test-unity.c"
	}
	return obj;
}


static void main_test_place_class_init (MainTestPlaceClass * klass) {
	main_test_place_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->constructor = main_test_place_constructor;
}


static void main_test_place_instance_init (MainTestPlace * self) {
}


GType main_test_place_get_type (void) {
	static GType main_test_place_type_id = 0;
	if (main_test_place_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (MainTestPlaceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) main_test_place_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MainTestPlace), 0, (GInstanceInitFunc) main_test_place_instance_init, NULL };
		main_test_place_type_id = g_type_register_static (UNITY_TYPE_PLACE, "MainTestPlace", &g_define_type_info, 0);
	}
	return main_test_place_type_id;
}


static void value_main_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_main_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		main_unref (value->data[0].v_pointer);
	}
}


static void value_main_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = main_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_main_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_main_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		Main* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = main_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_main_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	Main** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = main_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_main (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecMain* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_MAIN), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_main (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_MAIN), NULL);
	return value->data[0].v_pointer;
}


void value_set_main (GValue* value, gpointer v_object) {
	Main* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_MAIN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_MAIN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		main_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		main_unref (old);
	}
}


static void main_class_init (MainClass * klass) {
	main_parent_class = g_type_class_peek_parent (klass);
	MAIN_CLASS (klass)->finalize = main_finalize;
}


static void main_instance_init (Main * self) {
	self->ref_count = 1;
}


static void main_finalize (Main* obj) {
	Main * self;
	self = MAIN (obj);
}


GType main_get_type (void) {
	static GType main_type_id = 0;
	if (main_type_id == 0) {
		static const GTypeValueTable g_define_type_value_table = { value_main_init, value_main_free_value, value_main_copy_value, value_main_peek_pointer, "p", value_main_collect_value, "p", value_main_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (MainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Main), 0, (GInstanceInitFunc) main_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		main_type_id = g_type_register_fundamental (g_type_fundamental_next (), "Main", &g_define_type_info, &g_define_type_fundamental_info, 0);
	}
	return main_type_id;
}


gpointer main_ref (gpointer instance) {
	Main* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void main_unref (gpointer instance) {
	Main* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		MAIN_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




