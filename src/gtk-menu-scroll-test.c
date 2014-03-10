/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * gtk-menu-scroll-test.c
 * Copyright (C) 2014 Sebastian Geiger <sebastiangeiger@mars>
 * 
 * gtk-menu-scroll-test is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * gtk-menu-scroll-test is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "gtk-menu-scroll-test.h"



/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/gtk_menu_scroll_test.ui" */
#define UI_FILE "src/gtk_menu_scroll_test.ui"
#define TOP_WINDOW "window"


G_DEFINE_TYPE (Gtkmenuscrolltest, gtk_menu_scroll_test, GTK_TYPE_APPLICATION);


/* Define the private structure in the .c file */
#define GTK_MENU_SCROLL_TEST_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GTK_MENU_SCROLL_TEST_TYPE_APPLICATION, GtkmenuscrolltestPrivate))

struct _GtkmenuscrolltestPrivate
{
	/* ANJUTA: Widgets declaration for gtk_menu_scroll_test.ui - DO NOT REMOVE */
};


gboolean menu_add_entry (gpointer user_data) {
	static GtkMenuItem *menuitem = NULL;
	static gboolean attached = FALSE;
	if(menuitem == NULL) {
		menuitem = gtk_menu_item_new_with_label ("Foo");
		g_object_ref(menuitem);
		gtk_widget_show(menuitem);
	}
	GtkMenu *menu = GTK_MENU(user_data);
	g_message("Menu: %p, Menuitem: %p", user_data, menuitem);
	if(attached) {
		gtk_container_remove (GTK_CONTAINER(menu), GTK_WIDGET(menuitem));
		attached = FALSE;
	} else {
		gtk_menu_shell_append (GTK_MENU_SHELL(menu), GTK_WIDGET(menuitem));
		attached = TRUE;
	}
	gtk_widget_queue_draw (menu);
	return TRUE;
}

/* Create a new window loading a file */
static void
gtk_menu_scroll_test_new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;

	GtkBuilder *builder;
	GError* error = NULL;

	GtkmenuscrolltestPrivate *priv = GTK_MENU_SCROLL_TEST_GET_PRIVATE(app);

	/* Load UI from file */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_critical ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, app);

	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, TOP_WINDOW));
        if (!window)
        {
		g_critical ("Widget \"%s\" is missing in file %s.",
				TOP_WINDOW,
				UI_FILE);
        }


	GtkMenu *menu = GTK_MENU(gtk_builder_get_object (builder, "menu2"));
	g_timeout_add (2000,
				   menu_add_entry,
	               menu);
	/* ANJUTA: Widgets initialization for gtk_menu_scroll_test.ui - DO NOT REMOVE */

	g_object_unref (builder);
	
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	if (file != NULL)
	{
		/* TODO: Add code here to open the file in the new window */
	}
	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
gtk_menu_scroll_test_activate (GApplication *application)
{
	gtk_menu_scroll_test_new_window (application, NULL);
}

static void
gtk_menu_scroll_test_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		gtk_menu_scroll_test_new_window (application, files[i]);
}

static void
gtk_menu_scroll_test_init (Gtkmenuscrolltest *object)
{

}

static void
gtk_menu_scroll_test_finalize (GObject *object)
{
	G_OBJECT_CLASS (gtk_menu_scroll_test_parent_class)->finalize (object);
}

static void
gtk_menu_scroll_test_class_init (GtkmenuscrolltestClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = gtk_menu_scroll_test_activate;
	G_APPLICATION_CLASS (klass)->open = gtk_menu_scroll_test_open;

	g_type_class_add_private (klass, sizeof (GtkmenuscrolltestPrivate));

	G_OBJECT_CLASS (klass)->finalize = gtk_menu_scroll_test_finalize;
}

Gtkmenuscrolltest *
gtk_menu_scroll_test_new (void)
{
	g_type_init ();

	return g_object_new (gtk_menu_scroll_test_get_type (),
	                     "application-id", "org.gnome.gtk_menu_scroll_test",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

