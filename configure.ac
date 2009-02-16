AC_INIT([orpheus], [0.1], [bartspaans@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CHECK_LIB(mingus, note_to_str)
LIBS="-lmingus"
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
  Makefile
  src/Makefile
])
AC_OUTPUT
