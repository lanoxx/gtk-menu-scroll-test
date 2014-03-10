## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(pkgdatadir)/ui
ui_DATA = gtk_menu_scroll_test.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(GTK_MENU_SCROLL_TEST_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = gtk_menu_scroll_test

gtk_menu_scroll_test_SOURCES = \
	main.c \
	gtk-menu-scroll-test.h \
	gtk-menu-scroll-test.c	

gtk_menu_scroll_test_LDFLAGS = \
	-Wl,--export-dynamic

gtk_menu_scroll_test_LDADD = $(GTK_MENU_SCROLL_TEST_LIBS)


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

