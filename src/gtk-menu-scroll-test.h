/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * gtk-menu-scroll-test.h
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

#ifndef _GTK_MENU_SCROLL_TEST_
#define _GTK_MENU_SCROLL_TEST_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GTK_MENU_SCROLL_TEST_TYPE_APPLICATION             (gtk_menu_scroll_test_get_type ())
#define GTK_MENU_SCROLL_TEST_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_MENU_SCROLL_TEST_TYPE_APPLICATION, Gtkmenuscrolltest))
#define GTK_MENU_SCROLL_TEST_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_MENU_SCROLL_TEST_TYPE_APPLICATION, GtkmenuscrolltestClass))
#define GTK_MENU_SCROLL_TEST_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_MENU_SCROLL_TEST_TYPE_APPLICATION))
#define GTK_MENU_SCROLL_TEST_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_MENU_SCROLL_TEST_TYPE_APPLICATION))
#define GTK_MENU_SCROLL_TEST_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_MENU_SCROLL_TEST_TYPE_APPLICATION, GtkmenuscrolltestClass))

typedef struct _GtkmenuscrolltestClass GtkmenuscrolltestClass;
typedef struct _Gtkmenuscrolltest Gtkmenuscrolltest;
typedef struct _GtkmenuscrolltestPrivate GtkmenuscrolltestPrivate;

struct _GtkmenuscrolltestClass
{
	GtkApplicationClass parent_class;
};

struct _Gtkmenuscrolltest
{
	GtkApplication parent_instance;

	GtkmenuscrolltestPrivate *priv;

};

GType gtk_menu_scroll_test_get_type (void) G_GNUC_CONST;
Gtkmenuscrolltest *gtk_menu_scroll_test_new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */

