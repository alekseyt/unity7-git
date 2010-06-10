/* places-place-view.c generated by valac, the Vala compiler
 * generated from places-place-view.vala, do not modify */

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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutter/clutter.h>
#include <stdlib.h>
#include <string.h>


#define UNITY_PLACES_TYPE_PLACE_VIEW (unity_places_place_view_get_type ())
#define UNITY_PLACES_PLACE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_VIEW, UnityPlacesPlaceView))
#define UNITY_PLACES_IS_PLACE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_VIEW))
#define UNITY_PLACES_PLACE_VIEW_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), UNITY_PLACES_TYPE_PLACE_VIEW, UnityPlacesPlaceViewIface))

typedef struct _UnityPlacesPlaceView UnityPlacesPlaceView;
typedef struct _UnityPlacesPlaceViewIface UnityPlacesPlaceViewIface;

struct _UnityPlacesPlaceViewIface {
	GTypeInterface parent_iface;
	void (*init_with_properties) (UnityPlacesPlaceView* self, GHashTable* props);
};



GType unity_places_place_view_get_type (void);
void unity_places_place_view_init_with_properties (UnityPlacesPlaceView* self, GHashTable* props);



void unity_places_place_view_init_with_properties (UnityPlacesPlaceView* self, GHashTable* props) {
	UNITY_PLACES_PLACE_VIEW_GET_INTERFACE (self)->init_with_properties (self, props);
}


static void unity_places_place_view_base_init (UnityPlacesPlaceViewIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType unity_places_place_view_get_type (void) {
	static volatile gsize unity_places_place_view_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceViewIface), (GBaseInitFunc) unity_places_place_view_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType unity_places_place_view_type_id;
		unity_places_place_view_type_id = g_type_register_static (G_TYPE_INTERFACE, "UnityPlacesPlaceView", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (unity_places_place_view_type_id, CLUTTER_TYPE_ACTOR);
		g_once_init_leave (&unity_places_place_view_type_id__volatile, unity_places_place_view_type_id);
	}
	return unity_places_place_view_type_id__volatile;
}




