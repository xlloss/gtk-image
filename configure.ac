#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([gtk-image], [0.1], [slash.linuc.c@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([gtk_image.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES(GLIB, glib-2.0)
PKG_CHECK_MODULES(GTK30, gtk+-3.0)

# Checks for header files.
CFLAGS="$CFLAGS -O0 $GTK30_CFLAGS $GLIB_CFLAGS -g -Wall -Werror"

# Checks for typedefs, structures, and compiler characteristics.


# Checks for library functions.
LIBS="$GLIB_LIBS $GTK30_LIBS"

#AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
