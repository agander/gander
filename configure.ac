# $Id: configure.ac 571 2010-06-19 17:39:26Z gander $

# Process this file with autoconf to produce a configure script.
AC_PREREQ(2.59)
m4_include([m4/version.m4])
AC_INIT([gander], [VERSION_NUMBER], [agander@gmail.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([gander.cpp])
AM_CONFIG_HEADER(config.h)

AM_MAINTAINER_MODE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_ENABLE_SHARED
AC_PROG_LIBTOOL

AC_PROG_MAKE_SET
AC_LANG_CPLUSPLUS

# Checks for libraries.
#AC_CHECK_LIB([xerces-c],[main])


# Checks for header files.
# Ensure that 'AC_LANG_CPLUSPLUS' is defined before these
# or they will fail validity checks.
AC_CHECK_HEADER([iostream])
AC_CHECK_HEADER([map])
AC_CHECK_HEADER([vector])
AC_CHECK_HEADER([algorithm])
AC_CHECK_HEADER([string])

#PKG_CHECK_MODULES(LIBMYSQLPP, libmysqlpp >= 1.7.26)
#AC_SUBST(LIBMYSQLPP_CFLAGS)
#AC_SUBST(LIBMYSQLPP_LIBS)

# Checks for typedefs, structures, and compiler characteristics.
#AC_C_CONST


# Checks for library functions.
#AC_CHECK_FUNCS([cout])


# Sets up tests.
# Initialize the test suite.
#AC_CONFIG_TESTDIR(tests)
#AC_CONFIG_FILES([tests/Makefile tests/atlocal])

#$(srcdir)/package.m4: $(top_srcdir)/configure.ac
#{                                      \
#   echo '# Signature of the current package.'; \
#   echo 'm4_define([AT_PACKAGE_NAME],      [@PACKAGE_NAME@])'; \
#   echo 'm4_define([AT_PACKAGE_TARNAME],   [@PACKAGE_TARNAME@])'; \
#   echo 'm4_define([AT_PACKAGE_VERSION],   [@PACKAGE_VERSION@])'; \
#   echo 'm4_define([AT_PACKAGE_STRING],    [@PACKAGE_STRING@])'; \
#   echo 'm4_define([AT_PACKAGE_BUGREPORT], [@PACKAGE_BUGREPORT@])'; \
#} >$(srcdir)/package.m4

# Forced settings
#AC_SUBST([AM_CPPFLAGS], [-ggdb])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST

#m4_include([m4/debug.m4])
#AC_COMPILE_DEBUG
dnl Check for option to enable debug
AC_MSG_CHECKING(whether to enable debugging)
AC_ARG_ENABLE(debug,
        [  --enable-debug=[no/yes]        enables debug build (default=no)],,
                 enable_debug=no)

dnl Checks for libraries
if [ ! test "x$enable_debug" != "xyes"]; then
  AC_DEFINE(DEBUG, 1, [Define to enable debug build: '-ggdb3 -O0'])
  AC_SUBST(DEBUG_CFLAGS)
  AC_SUBST(DEBUG_LIBS)
  CXXFLAGS="-Wall -ggdb3 -O0 -m64 -mtune=k8"
  AC_MSG_RESULT(yes)
else
  AC_MSG_RESULT(no)
  DEBUG_CFLAGS=""
  DEBUG_LIBS=""
  AC_SUBST(DEBUG_CFLAGS)
  AC_SUBST(DEBUG_LIBS)
  CXXFLAGS="-Wall -O3 -m64 -mtune=k8"
fi

AX_BOOST_BASE([1.37])
AX_BOOST_ASIO
AX_BOOST_DATE_TIME
AX_BOOST_FILESYSTEM
AX_BOOST_IOSTREAMS
AX_BOOST_PROGRAM_OPTIONS
AX_BOOST_PYTHON
AX_BOOST_REGEX
AX_BOOST_SERIALIZATION
AX_BOOST_SIGNALS
AX_BOOST_SYSTEM
AX_BOOST_TEST_EXEC_MONITOR
AX_BOOST_THREAD
AX_BOOST_UNIT_TEST_FRAMEWORK
AX_BOOST_WSERIALIZATION

# Pass ./configure args to distcheck target otherwise it runs 
# a basic ./configure which isnt the 'make distcheck' you really want.
DISTCHECK_CONFIGURE_FLAGS="${ac_configure_args}"
AC_SUBST(DISTCHECK_CONFIGURE_FLAGS)

AC_CONFIG_FILES([
   Makefile
])
#   gander.spec
#   gander.pc
#   tests/Makefile
#   tests/atlocal

AC_OUTPUT


AX_BOOST
AX_BOOST_ASIO
AX_BOOST_BASE
AX_BOOST_DATE_TIME
AX_BOOST_FILESYSTEM
AX_BOOST_IOSTREAMS
AX_BOOST_PROGRAM_OPTIONS
AX_BOOST_PYTHON
AX_BOOST_REGEX
AX_BOOST_SERIALIZATION
AX_BOOST_SIGNALS
AX_BOOST_SYSTEM
AX_BOOST_TEST_EXEC_MONITOR
AX_BOOST_THREAD
AX_BOOST_UNIT_TEST_FRAMEWORK
AX_BOOST_WSERIALIZATION
