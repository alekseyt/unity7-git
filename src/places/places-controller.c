/* places-controller.c generated by valac, the Vala compiler
 * generated from places-controller.vala, do not modify */

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
#include <unity.h>
#include <clutk/clutk.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <clutter/clutter.h>


#define UNITY_PLACES_TYPE_CONTROLLER (unity_places_controller_get_type ())
#define UNITY_PLACES_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesController))
#define UNITY_PLACES_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesControllerClass))
#define UNITY_PLACES_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_CONTROLLER))
#define UNITY_PLACES_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_CONTROLLER))
#define UNITY_PLACES_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesControllerClass))

typedef struct _UnityPlacesController UnityPlacesController;
typedef struct _UnityPlacesControllerClass UnityPlacesControllerClass;
typedef struct _UnityPlacesControllerPrivate UnityPlacesControllerPrivate;

#define UNITY_PLACES_TYPE_MODEL (unity_places_model_get_type ())
#define UNITY_PLACES_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_MODEL, UnityPlacesModel))
#define UNITY_PLACES_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_MODEL, UnityPlacesModelClass))
#define UNITY_PLACES_IS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_MODEL))
#define UNITY_PLACES_IS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_MODEL))
#define UNITY_PLACES_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_MODEL, UnityPlacesModelClass))

typedef struct _UnityPlacesModel UnityPlacesModel;
typedef struct _UnityPlacesModelClass UnityPlacesModelClass;

#define UNITY_PLACES_TYPE_VIEW (unity_places_view_get_type ())
#define UNITY_PLACES_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_VIEW, UnityPlacesView))
#define UNITY_PLACES_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_VIEW, UnityPlacesViewClass))
#define UNITY_PLACES_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_VIEW))
#define UNITY_PLACES_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_VIEW))
#define UNITY_PLACES_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_VIEW, UnityPlacesViewClass))

typedef struct _UnityPlacesView UnityPlacesView;
typedef struct _UnityPlacesViewClass UnityPlacesViewClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;

#define UNITY_PLACES_TYPE_HOME_PLACE (unity_places_home_place_get_type ())
#define UNITY_PLACES_HOME_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_HOME_PLACE, UnityPlacesHomePlace))
#define UNITY_PLACES_HOME_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_HOME_PLACE, UnityPlacesHomePlaceClass))
#define UNITY_PLACES_IS_HOME_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_HOME_PLACE))
#define UNITY_PLACES_IS_HOME_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_HOME_PLACE))
#define UNITY_PLACES_HOME_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_HOME_PLACE, UnityPlacesHomePlaceClass))

typedef struct _UnityPlacesHomePlace UnityPlacesHomePlace;
typedef struct _UnityPlacesHomePlaceClass UnityPlacesHomePlaceClass;

#define UNITY_PLACES_TYPE_FAKE_PLACE (unity_places_fake_place_get_type ())
#define UNITY_PLACES_FAKE_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_FAKE_PLACE, UnityPlacesFakePlace))
#define UNITY_PLACES_FAKE_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_FAKE_PLACE, UnityPlacesFakePlaceClass))
#define UNITY_PLACES_IS_FAKE_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_FAKE_PLACE))
#define UNITY_PLACES_IS_FAKE_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_FAKE_PLACE))
#define UNITY_PLACES_FAKE_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_FAKE_PLACE, UnityPlacesFakePlaceClass))

typedef struct _UnityPlacesFakePlace UnityPlacesFakePlace;
typedef struct _UnityPlacesFakePlaceClass UnityPlacesFakePlaceClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define UNITY_PLACES_TYPE_PLACE_PROXY (unity_places_place_proxy_get_type ())
#define UNITY_PLACES_PLACE_PROXY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_PROXY, UnityPlacesPlaceProxy))
#define UNITY_PLACES_PLACE_PROXY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_PROXY, UnityPlacesPlaceProxyClass))
#define UNITY_PLACES_IS_PLACE_PROXY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_PROXY))
#define UNITY_PLACES_IS_PLACE_PROXY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_PROXY))
#define UNITY_PLACES_PLACE_PROXY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_PROXY, UnityPlacesPlaceProxyClass))

typedef struct _UnityPlacesPlaceProxy UnityPlacesPlaceProxy;
typedef struct _UnityPlacesPlaceProxyClass UnityPlacesPlaceProxyClass;
#define _g_key_file_free0(var) ((var == NULL) ? NULL : (var = (g_key_file_free (var), NULL)))
typedef struct _UnityPlacesPlacePrivate UnityPlacesPlacePrivate;
typedef struct _UnityPlacesHomePlacePrivate UnityPlacesHomePlacePrivate;

#define UNITY_PLACES_DEFAULT_TYPE_VIEW (unity_places_default_view_get_type ())
#define UNITY_PLACES_DEFAULT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_DEFAULT_TYPE_VIEW, UnityPlacesDefaultView))
#define UNITY_PLACES_DEFAULT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_DEFAULT_TYPE_VIEW, UnityPlacesDefaultViewClass))
#define UNITY_PLACES_DEFAULT_IS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_DEFAULT_TYPE_VIEW))
#define UNITY_PLACES_DEFAULT_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_DEFAULT_TYPE_VIEW))
#define UNITY_PLACES_DEFAULT_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_DEFAULT_TYPE_VIEW, UnityPlacesDefaultViewClass))

typedef struct _UnityPlacesDefaultView UnityPlacesDefaultView;
typedef struct _UnityPlacesDefaultViewClass UnityPlacesDefaultViewClass;
typedef struct _UnityPlacesFakePlacePrivate UnityPlacesFakePlacePrivate;

#define UNITY_PLACES_APPLICATION_TYPE_APPLICATION_VIEW (unity_places_application_application_view_get_type ())
#define UNITY_PLACES_APPLICATION_APPLICATION_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_APPLICATION_TYPE_APPLICATION_VIEW, UnityPlacesApplicationApplicationView))
#define UNITY_PLACES_APPLICATION_APPLICATION_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_APPLICATION_TYPE_APPLICATION_VIEW, UnityPlacesApplicationApplicationViewClass))
#define UNITY_PLACES_APPLICATION_IS_APPLICATION_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_APPLICATION_TYPE_APPLICATION_VIEW))
#define UNITY_PLACES_APPLICATION_IS_APPLICATION_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_APPLICATION_TYPE_APPLICATION_VIEW))
#define UNITY_PLACES_APPLICATION_APPLICATION_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_APPLICATION_TYPE_APPLICATION_VIEW, UnityPlacesApplicationApplicationViewClass))

typedef struct _UnityPlacesApplicationApplicationView UnityPlacesApplicationApplicationView;
typedef struct _UnityPlacesApplicationApplicationViewClass UnityPlacesApplicationApplicationViewClass;

#define UNITY_PLACES_FILE_TYPE_FILE_VIEW (unity_places_file_file_view_get_type ())
#define UNITY_PLACES_FILE_FILE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_FILE_TYPE_FILE_VIEW, UnityPlacesFileFileView))
#define UNITY_PLACES_FILE_FILE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_FILE_TYPE_FILE_VIEW, UnityPlacesFileFileViewClass))
#define UNITY_PLACES_FILE_IS_FILE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_FILE_TYPE_FILE_VIEW))
#define UNITY_PLACES_FILE_IS_FILE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_FILE_TYPE_FILE_VIEW))
#define UNITY_PLACES_FILE_FILE_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_FILE_TYPE_FILE_VIEW, UnityPlacesFileFileViewClass))

typedef struct _UnityPlacesFileFileView UnityPlacesFileFileView;
typedef struct _UnityPlacesFileFileViewClass UnityPlacesFileFileViewClass;

struct _UnityPlacesController {
	GObject parent_instance;
	UnityPlacesControllerPrivate * priv;
};

struct _UnityPlacesControllerClass {
	GObjectClass parent_class;
};

struct _UnityPlacesControllerPrivate {
	UnityShell* _shell;
	UnityPlacesModel* model;
	UnityPlacesView* view;
};

struct _UnityPlacesPlace {
	GObject parent_instance;
	UnityPlacesPlacePrivate * priv;
};

struct _UnityPlacesPlaceClass {
	GObjectClass parent_class;
	ClutterActor* (*get_view) (UnityPlacesPlace* self);
};

struct _UnityPlacesHomePlace {
	UnityPlacesPlace parent_instance;
	UnityPlacesHomePlacePrivate * priv;
};

struct _UnityPlacesHomePlaceClass {
	UnityPlacesPlaceClass parent_class;
};

struct _UnityPlacesFakePlace {
	UnityPlacesPlace parent_instance;
	UnityPlacesFakePlacePrivate * priv;
};

struct _UnityPlacesFakePlaceClass {
	UnityPlacesPlaceClass parent_class;
};


static gpointer unity_places_controller_parent_class = NULL;
static gpointer unity_places_home_place_parent_class = NULL;
static gpointer unity_places_fake_place_parent_class = NULL;

GType unity_places_controller_get_type (void);
GType unity_places_model_get_type (void);
GType unity_places_view_get_type (void);
#define UNITY_PLACES_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_CONTROLLER, UnityPlacesControllerPrivate))
enum  {
	UNITY_PLACES_CONTROLLER_DUMMY_PROPERTY,
	UNITY_PLACES_CONTROLLER_SHELL
};
UnityPlacesController* unity_places_controller_new (UnityShell* shell);
UnityPlacesController* unity_places_controller_construct (GType object_type, UnityShell* shell);
UnityPlacesHomePlace* unity_places_home_place_new (void);
UnityPlacesHomePlace* unity_places_home_place_construct (GType object_type);
GType unity_places_place_get_type (void);
GType unity_places_home_place_get_type (void);
static void unity_places_controller_on_place_activated (UnityPlacesController* self, UnityPlacesPlace* place);
static void _unity_places_controller_on_place_activated_unity_places_place_activated (UnityPlacesPlace* _sender, gpointer self);
void unity_places_model_add (UnityPlacesModel* self, UnityPlacesPlace* place);
void unity_places_controller_load_remote_places (UnityPlacesController* self);
UnityPlacesFakePlace* unity_places_fake_place_new (const char* name, const char* icon_name);
UnityPlacesFakePlace* unity_places_fake_place_construct (GType object_type, const char* name, const char* icon_name);
GType unity_places_fake_place_get_type (void);
static gboolean unity_places_controller_load_places (UnityPlacesController* self);
static void unity_places_controller_load_place (UnityPlacesController* self, const char* filename);
UnityPlacesPlaceProxy* unity_places_place_proxy_new (const char* name, const char* icon_name, const char* comment, const char* dbus_name, const char* dbus_path);
UnityPlacesPlaceProxy* unity_places_place_proxy_construct (GType object_type, const char* name, const char* icon_name, const char* comment, const char* dbus_name, const char* dbus_path);
GType unity_places_place_proxy_get_type (void);
void unity_places_view_set_content_view (UnityPlacesView* self, ClutterActor* actor);
ClutterActor* unity_places_place_get_view (UnityPlacesPlace* self);
UnityPlacesView* unity_places_controller_get_view (UnityPlacesController* self);
UnityShell* unity_places_controller_get_shell (UnityPlacesController* self);
static void unity_places_controller_set_shell (UnityPlacesController* self, UnityShell* value);
UnityPlacesModel* unity_places_model_new (void);
UnityPlacesModel* unity_places_model_construct (GType object_type);
UnityPlacesView* unity_places_view_new (UnityPlacesModel* model, UnityShell* shell);
UnityPlacesView* unity_places_view_construct (GType object_type, UnityPlacesModel* model, UnityShell* shell);
static gboolean _unity_places_controller_load_places_gsource_func (gpointer self);
static GObject * unity_places_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_controller_finalize (GObject* obj);
static void unity_places_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
enum  {
	UNITY_PLACES_HOME_PLACE_DUMMY_PROPERTY
};
UnityPlacesDefaultView* unity_places_default_view_new (void);
UnityPlacesDefaultView* unity_places_default_view_construct (GType object_type);
GType unity_places_default_view_get_type (void);
static ClutterActor* unity_places_home_place_real_get_view (UnityPlacesPlace* base);
enum  {
	UNITY_PLACES_FAKE_PLACE_DUMMY_PROPERTY
};
const char* unity_places_place_get_name (UnityPlacesPlace* self);
UnityPlacesApplicationApplicationView* unity_places_application_application_view_new (void);
UnityPlacesApplicationApplicationView* unity_places_application_application_view_construct (GType object_type);
GType unity_places_application_application_view_get_type (void);
UnityPlacesFileFileView* unity_places_file_file_view_new (void);
UnityPlacesFileFileView* unity_places_file_file_view_construct (GType object_type);
GType unity_places_file_file_view_get_type (void);
static ClutterActor* unity_places_fake_place_real_get_view (UnityPlacesPlace* base);
static int _vala_strcmp0 (const char * str1, const char * str2);



#line 34 "places-controller.vala"
UnityPlacesController* unity_places_controller_construct (GType object_type, UnityShell* shell) {
#line 254 "places-controller.c"
	UnityPlacesController * self;
#line 34 "places-controller.vala"
	g_return_val_if_fail (shell != NULL, NULL);
#line 36 "places-controller.vala"
	self = (UnityPlacesController*) g_object_new (object_type, "shell", shell, NULL);
#line 260 "places-controller.c"
	return self;
}


#line 34 "places-controller.vala"
UnityPlacesController* unity_places_controller_new (UnityShell* shell) {
#line 34 "places-controller.vala"
	return unity_places_controller_construct (UNITY_PLACES_TYPE_CONTROLLER, shell);
#line 269 "places-controller.c"
}


#line 121 "places-controller.vala"
static void _unity_places_controller_on_place_activated_unity_places_place_activated (UnityPlacesPlace* _sender, gpointer self) {
#line 275 "places-controller.c"
	unity_places_controller_on_place_activated (self, _sender);
}


#line 47 "places-controller.vala"
static gboolean unity_places_controller_load_places (UnityPlacesController* self) {
#line 282 "places-controller.c"
	gboolean result;
	UnityPlacesHomePlace* homeplace;
	UnityPlacesFakePlace* place;
#line 47 "places-controller.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 49 "places-controller.vala"
	homeplace = unity_places_home_place_new ();
#line 50 "places-controller.vala"
	g_signal_connect_object ((UnityPlacesPlace*) homeplace, "activated", (GCallback) _unity_places_controller_on_place_activated_unity_places_place_activated, self, 0);
#line 51 "places-controller.vala"
	unity_places_model_add (self->priv->model, (UnityPlacesPlace*) homeplace);
#line 53 "places-controller.vala"
	unity_places_controller_load_remote_places (self);
#line 55 "places-controller.vala"
	place = unity_places_fake_place_new ("Files & Folders", PKGDATADIR "/files.png");
#line 56 "places-controller.vala"
	g_signal_connect_object ((UnityPlacesPlace*) place, "activated", (GCallback) _unity_places_controller_on_place_activated_unity_places_place_activated, self, 0);
#line 57 "places-controller.vala"
	unity_places_model_add (self->priv->model, (UnityPlacesPlace*) place);
#line 302 "places-controller.c"
	result = FALSE;
	_g_object_unref0 (homeplace);
	_g_object_unref0 (place);
#line 59 "places-controller.vala"
	return result;
#line 308 "places-controller.c"
}


#line 1047 "glib-2.0.vapi"
static const char* string_to_string (const char* self) {
#line 314 "places-controller.c"
	const char* result;
#line 1047 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 318 "places-controller.c"
	result = self;
#line 1048 "glib-2.0.vapi"
	return result;
#line 322 "places-controller.c"
}


#line 62 "places-controller.vala"
void unity_places_controller_load_remote_places (UnityPlacesController* self) {
#line 328 "places-controller.c"
	GError * _inner_error_;
	char* placesdir;
	GFile* dir;
#line 62 "places-controller.vala"
	g_return_if_fail (self != NULL);
#line 334 "places-controller.c"
	_inner_error_ = NULL;
#line 64 "places-controller.vala"
	placesdir = g_strdup (PKGDATADIR "/places");
#line 66 "places-controller.vala"
	dir = g_file_new_for_path (placesdir);
#line 340 "places-controller.c"
	{
		GFileEnumerator* enumerator;
		GFileInfo* file_info;
#line 69 "places-controller.vala"
		enumerator = g_file_enumerate_children (dir, G_FILE_ATTRIBUTE_STANDARD_NAME, 0, NULL, &_inner_error_);
#line 346 "places-controller.c"
		if (_inner_error_ != NULL) {
			goto __catch9_g_error;
			goto __finally9;
		}
		file_info = NULL;
#line 73 "places-controller.vala"
		while (TRUE) {
#line 354 "places-controller.c"
			GFileInfo* _tmp0_;
			GFileInfo* _tmp1_;
			char* _tmp2_;
			char* _tmp3_;
			char* filename;
#line 73 "places-controller.vala"
			_tmp0_ = g_file_enumerator_next_file (enumerator, NULL, &_inner_error_);
#line 362 "places-controller.c"
			if (_inner_error_ != NULL) {
				_g_object_unref0 (enumerator);
				_g_object_unref0 (file_info);
				goto __catch9_g_error;
				goto __finally9;
			}
#line 73 "places-controller.vala"
			if (!((file_info = (_tmp1_ = _tmp0_, _g_object_unref0 (file_info), _tmp1_)) != NULL)) {
#line 73 "places-controller.vala"
				break;
#line 373 "places-controller.c"
			}
#line 75 "places-controller.vala"
			filename = (_tmp3_ = g_strconcat (_tmp2_ = g_strconcat (placesdir, "/", NULL), g_file_info_get_name (file_info), NULL), _g_free0 (_tmp2_), _tmp3_);
#line 76 "places-controller.vala"
			unity_places_controller_load_place (self, filename);
#line 379 "places-controller.c"
			_g_free0 (filename);
		}
		_g_object_unref0 (enumerator);
		_g_object_unref0 (file_info);
	}
	goto __finally9;
	__catch9_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp4_;
#line 81 "places-controller.vala"
			g_message (_tmp4_ = g_strconcat ("Unable to read places from ", string_to_string (placesdir), ": %s", NULL), _error_->message);
#line 395 "places-controller.c"
			_g_free0 (_tmp4_);
			_g_error_free0 (_error_);
		}
	}
	__finally9:
	if (_inner_error_ != NULL) {
		_g_free0 (placesdir);
		_g_object_unref0 (dir);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_free0 (placesdir);
	_g_object_unref0 (dir);
}


#line 85 "places-controller.vala"
static void unity_places_controller_load_place (UnityPlacesController* self, const char* filename) {
#line 415 "places-controller.c"
	GError * _inner_error_;
	char* group;
	GKeyFile* file;
#line 85 "places-controller.vala"
	g_return_if_fail (self != NULL);
#line 85 "places-controller.vala"
	g_return_if_fail (filename != NULL);
#line 423 "places-controller.c"
	_inner_error_ = NULL;
#line 87 "places-controller.vala"
	group = g_strdup ("Place");
#line 89 "places-controller.vala"
	file = g_key_file_new ();
#line 429 "places-controller.c"
	{
		char* name;
		char* comment;
		char* icon_name;
		char* dbus_name;
		char* dbus_path;
		UnityPlacesPlace* place;
#line 93 "places-controller.vala"
		g_key_file_load_from_file (file, filename, G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS, &_inner_error_);
#line 439 "places-controller.c"
		if (_inner_error_ != NULL) {
			goto __catch10_g_error;
			goto __finally10;
		}
#line 97 "places-controller.vala"
		name = g_key_file_get_string (file, group, "Name", &_inner_error_);
#line 446 "places-controller.c"
		if (_inner_error_ != NULL) {
			goto __catch10_g_error;
			goto __finally10;
		}
#line 98 "places-controller.vala"
		comment = g_key_file_get_string (file, group, "Comment", &_inner_error_);
#line 453 "places-controller.c"
		if (_inner_error_ != NULL) {
			_g_free0 (name);
			goto __catch10_g_error;
			goto __finally10;
		}
#line 99 "places-controller.vala"
		icon_name = g_key_file_get_string (file, group, "Icon", &_inner_error_);
#line 461 "places-controller.c"
		if (_inner_error_ != NULL) {
			_g_free0 (name);
			_g_free0 (comment);
			goto __catch10_g_error;
			goto __finally10;
		}
#line 100 "places-controller.vala"
		dbus_name = g_key_file_get_string (file, group, "DBusName", &_inner_error_);
#line 470 "places-controller.c"
		if (_inner_error_ != NULL) {
			_g_free0 (name);
			_g_free0 (comment);
			_g_free0 (icon_name);
			goto __catch10_g_error;
			goto __finally10;
		}
#line 101 "places-controller.vala"
		dbus_path = g_key_file_get_string (file, group, "DBusPath", &_inner_error_);
#line 480 "places-controller.c"
		if (_inner_error_ != NULL) {
			_g_free0 (name);
			_g_free0 (comment);
			_g_free0 (icon_name);
			_g_free0 (dbus_name);
			goto __catch10_g_error;
			goto __finally10;
		}
#line 103 "places-controller.vala"
		place = (UnityPlacesPlace*) unity_places_place_proxy_new (name, icon_name, comment, dbus_name, dbus_path);
#line 109 "places-controller.vala"
		if (UNITY_PLACES_IS_PLACE (place)) {
#line 111 "places-controller.vala"
			g_signal_connect_object (place, "activated", (GCallback) _unity_places_controller_on_place_activated_unity_places_place_activated, self, 0);
#line 112 "places-controller.vala"
			unity_places_model_add (self->priv->model, place);
#line 497 "places-controller.c"
		}
		_g_free0 (name);
		_g_free0 (comment);
		_g_free0 (icon_name);
		_g_free0 (dbus_name);
		_g_free0 (dbus_path);
		_g_object_unref0 (place);
	}
	goto __finally10;
	__catch10_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp0_;
#line 117 "places-controller.vala"
			g_warning (_tmp0_ = g_strconcat ("Unable to load place '", string_to_string (filename), "': %s", NULL), e->message);
#line 516 "places-controller.c"
			_g_free0 (_tmp0_);
			_g_error_free0 (e);
		}
	}
	__finally10:
	if (_inner_error_ != NULL) {
		_g_free0 (group);
		_g_key_file_free0 (file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_free0 (group);
	_g_key_file_free0 (file);
}


#line 121 "places-controller.vala"
static void unity_places_controller_on_place_activated (UnityPlacesController* self, UnityPlacesPlace* place) {
#line 536 "places-controller.c"
	ClutterActor* _tmp0_;
#line 121 "places-controller.vala"
	g_return_if_fail (self != NULL);
#line 121 "places-controller.vala"
	g_return_if_fail (place != NULL);
#line 123 "places-controller.vala"
	unity_places_view_set_content_view (self->priv->view, _tmp0_ = unity_places_place_get_view (place));
#line 544 "places-controller.c"
	_g_object_unref0 (_tmp0_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


#line 127 "places-controller.vala"
UnityPlacesView* unity_places_controller_get_view (UnityPlacesController* self) {
#line 556 "places-controller.c"
	UnityPlacesView* result;
#line 127 "places-controller.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 560 "places-controller.c"
	result = _g_object_ref0 (self->priv->view);
#line 129 "places-controller.vala"
	return result;
#line 564 "places-controller.c"
}


UnityShell* unity_places_controller_get_shell (UnityPlacesController* self) {
	UnityShell* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_shell;
#line 30 "places-controller.vala"
	return result;
#line 574 "places-controller.c"
}


static void unity_places_controller_set_shell (UnityPlacesController* self, UnityShell* value) {
	UnityShell* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_shell = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_shell), _tmp0_);
	g_object_notify ((GObject *) self, "shell");
}


#line 47 "places-controller.vala"
static gboolean _unity_places_controller_load_places_gsource_func (gpointer self) {
#line 588 "places-controller.c"
	return unity_places_controller_load_places (self);
}


static GObject * unity_places_controller_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesController * self;
	parent_class = G_OBJECT_CLASS (unity_places_controller_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_CONTROLLER (obj);
	{
		UnityPlacesModel* _tmp0_;
		UnityPlacesView* _tmp1_;
#line 41 "places-controller.vala"
		self->priv->model = (_tmp0_ = unity_places_model_new (), _g_object_unref0 (self->priv->model), _tmp0_);
#line 42 "places-controller.vala"
		self->priv->view = (_tmp1_ = g_object_ref_sink (unity_places_view_new (self->priv->model, self->priv->_shell)), _g_object_unref0 (self->priv->view), _tmp1_);
#line 44 "places-controller.vala"
		g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _unity_places_controller_load_places_gsource_func, g_object_ref (self), g_object_unref);
#line 609 "places-controller.c"
	}
	return obj;
}


static void unity_places_controller_class_init (UnityPlacesControllerClass * klass) {
	unity_places_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesControllerPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_places_controller_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_controller_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_controller_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_controller_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_CONTROLLER_SHELL, g_param_spec_object ("shell", "shell", "shell", UNITY_TYPE_SHELL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_places_controller_instance_init (UnityPlacesController * self) {
	self->priv = UNITY_PLACES_CONTROLLER_GET_PRIVATE (self);
}


static void unity_places_controller_finalize (GObject* obj) {
	UnityPlacesController * self;
	self = UNITY_PLACES_CONTROLLER (obj);
	_g_object_unref0 (self->priv->_shell);
	_g_object_unref0 (self->priv->model);
	_g_object_unref0 (self->priv->view);
	G_OBJECT_CLASS (unity_places_controller_parent_class)->finalize (obj);
}


GType unity_places_controller_get_type (void) {
	static GType unity_places_controller_type_id = 0;
	if (unity_places_controller_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesController), 0, (GInstanceInitFunc) unity_places_controller_instance_init, NULL };
		unity_places_controller_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityPlacesController", &g_define_type_info, 0);
	}
	return unity_places_controller_type_id;
}


static void unity_places_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesController * self;
	self = UNITY_PLACES_CONTROLLER (object);
	switch (property_id) {
		case UNITY_PLACES_CONTROLLER_SHELL:
		g_value_set_object (value, unity_places_controller_get_shell (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesController * self;
	self = UNITY_PLACES_CONTROLLER (object);
	switch (property_id) {
		case UNITY_PLACES_CONTROLLER_SHELL:
		unity_places_controller_set_shell (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


#line 135 "places-controller.vala"
UnityPlacesHomePlace* unity_places_home_place_construct (GType object_type) {
#line 681 "places-controller.c"
	UnityPlacesHomePlace * self;
#line 137 "places-controller.vala"
	self = (UnityPlacesHomePlace*) g_object_new (object_type, "name", "Home", "icon-name", PKGDATADIR "/home.png", "comment", "", NULL);
#line 685 "places-controller.c"
	return self;
}


#line 135 "places-controller.vala"
UnityPlacesHomePlace* unity_places_home_place_new (void) {
#line 135 "places-controller.vala"
	return unity_places_home_place_construct (UNITY_PLACES_TYPE_HOME_PLACE);
#line 694 "places-controller.c"
}


#line 142 "places-controller.vala"
static ClutterActor* unity_places_home_place_real_get_view (UnityPlacesPlace* base) {
#line 700 "places-controller.c"
	UnityPlacesHomePlace * self;
	ClutterActor* result;
	self = (UnityPlacesHomePlace*) base;
	result = (ClutterActor*) g_object_ref_sink (unity_places_default_view_new ());
#line 144 "places-controller.vala"
	return result;
#line 707 "places-controller.c"
}


static void unity_places_home_place_class_init (UnityPlacesHomePlaceClass * klass) {
	unity_places_home_place_parent_class = g_type_class_peek_parent (klass);
	UNITY_PLACES_PLACE_CLASS (klass)->get_view = unity_places_home_place_real_get_view;
}


static void unity_places_home_place_instance_init (UnityPlacesHomePlace * self) {
}


GType unity_places_home_place_get_type (void) {
	static GType unity_places_home_place_type_id = 0;
	if (unity_places_home_place_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesHomePlaceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_home_place_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesHomePlace), 0, (GInstanceInitFunc) unity_places_home_place_instance_init, NULL };
		unity_places_home_place_type_id = g_type_register_static (UNITY_PLACES_TYPE_PLACE, "UnityPlacesHomePlace", &g_define_type_info, 0);
	}
	return unity_places_home_place_type_id;
}


#line 150 "places-controller.vala"
UnityPlacesFakePlace* unity_places_fake_place_construct (GType object_type, const char* name, const char* icon_name) {
#line 733 "places-controller.c"
	UnityPlacesFakePlace * self;
#line 150 "places-controller.vala"
	g_return_val_if_fail (name != NULL, NULL);
#line 150 "places-controller.vala"
	g_return_val_if_fail (icon_name != NULL, NULL);
#line 152 "places-controller.vala"
	self = (UnityPlacesFakePlace*) g_object_new (object_type, "name", name, "icon-name", icon_name, "comment", "", NULL);
#line 741 "places-controller.c"
	return self;
}


#line 150 "places-controller.vala"
UnityPlacesFakePlace* unity_places_fake_place_new (const char* name, const char* icon_name) {
#line 150 "places-controller.vala"
	return unity_places_fake_place_construct (UNITY_PLACES_TYPE_FAKE_PLACE, name, icon_name);
#line 750 "places-controller.c"
}


#line 155 "places-controller.vala"
static ClutterActor* unity_places_fake_place_real_get_view (UnityPlacesPlace* base) {
#line 756 "places-controller.c"
	UnityPlacesFakePlace * self;
	ClutterActor* result;
	self = (UnityPlacesFakePlace*) base;
#line 157 "places-controller.vala"
	if (_vala_strcmp0 (unity_places_place_get_name ((UnityPlacesPlace*) self), "Applications") == 0) {
#line 762 "places-controller.c"
		result = (ClutterActor*) g_object_ref_sink (unity_places_application_application_view_new ());
#line 158 "places-controller.vala"
		return result;
#line 766 "places-controller.c"
	}
	result = (ClutterActor*) g_object_ref_sink (unity_places_file_file_view_new ());
#line 160 "places-controller.vala"
	return result;
#line 771 "places-controller.c"
}


static void unity_places_fake_place_class_init (UnityPlacesFakePlaceClass * klass) {
	unity_places_fake_place_parent_class = g_type_class_peek_parent (klass);
	UNITY_PLACES_PLACE_CLASS (klass)->get_view = unity_places_fake_place_real_get_view;
}


static void unity_places_fake_place_instance_init (UnityPlacesFakePlace * self) {
}


GType unity_places_fake_place_get_type (void) {
	static GType unity_places_fake_place_type_id = 0;
	if (unity_places_fake_place_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesFakePlaceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_fake_place_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesFakePlace), 0, (GInstanceInitFunc) unity_places_fake_place_instance_init, NULL };
		unity_places_fake_place_type_id = g_type_register_static (UNITY_PLACES_TYPE_PLACE, "UnityPlacesFakePlace", &g_define_type_info, 0);
	}
	return unity_places_fake_place_type_id;
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




