## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

gtk_menu_scroll_testdocdir = ${prefix}/doc/gtk_menu_scroll_test
gtk_menu_scroll_testdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(gtk_menu_scroll_testdoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(gtk_menu_scroll_testdocdir)
