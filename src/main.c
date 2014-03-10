/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
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

#include <config.h>
#include <gtk/gtk.h>
#include "gtk-menu-scroll-test.h"






int
main (int argc, char *argv[])
{
	Gtkmenuscrolltest *app;
	int status;


	
	app = gtk_menu_scroll_test_new ();
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	

	return status;
}

