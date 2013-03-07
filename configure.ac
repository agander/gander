
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.68])
m4_include([m4/version.m4])
AC_INIT([gander], [VERSION_NUMBER], [agander@gmail.com])
AC_CONFIG_AUX_DIR([build])
AC_CONFIG_MACRO_DIR([build])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([configure.ac])
AM_CONFIG_HEADER([config.h])

AM_MAINTAINER_MODE
AC_CONFIG_TESTDIR([tests])

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

AC_PATH_PROGS([BASH], [bash])
AC_PATH_PROGS([PYTHON], [python])

# Checks for header files.
# Ensure that 'AC_LANG_CPLUSPLUS' is defined before these
# or they will fail validity checks.
AC_CHECK_HEADER([iostream])
AC_CHECK_HEADER([map])
AC_CHECK_HEADER([vector])
AC_CHECK_HEADER([algorithm])
AC_CHECK_HEADER([string])

PKG_CHECK_MODULES([GLIBMM], [glibmm-2.4 >= 2.30.0 gthread-2.0 >= 2.30.0])
AC_SUBST([GLIBMM_CFLAGS])
AC_SUBST([GLIBMM_LIBS])

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
AC_MSG_CHECKING([whether to enable debugging])
AC_ARG_ENABLE([debug],
        [  --enable-debug=[no/yes]        enables debug build (default=no)],,
                 enable_debug=no)

dnl Checks for c++0x GCC switch
if test x"$DEJAGNU" = x
then
  DEJAGNU="\$(top_srcdir)/testsuite/site.exp"
fi

AC_SUBST([DEJAGNU])

AC_SUBST([DEJATOOL], [length])

dnl Checks for c++0x GCC switch
AC_SUBST([STDCXX_0X_CFLAGS]) 
AX_CHECK_COMPILE_FLAG([-std=c++0x],
                      [STDCXX_0X_CFLAGS="-std=c++0x "])

AX_CHECK_COMPILE_FLAG([-std=gnu++0x],
                      [STDCXX_0X_CFLAGS+=" -std=gnu++0x"])

dnl Checks for the DEBUG options request.
#m4_include([m4/debug.m4])
#AC_COMPILE_DEBUG
dnl Check for option to enable debug
AC_MSG_CHECKING([whether to enable debugging])
AC_ARG_ENABLE([debug],
        [  --enable-debug=[no/yes]        enables debug build (default=no)],,
                 enable_debug=no)

if [ ! test "x$enable_debug" != "xyes"]; then
  AC_DEFINE([DEBUG], [1], [Define to enable debug build: '-gdwarf-4 -O0' and '-DDEBUG'])
  AC_SUBST([DEBUG_CFLAGS], [-DDEBUG])
  AC_SUBST([DEBUG_LIBS])
  CXXFLAGS="-Wall -Wextra -gdwarf-4 -O0 -m64 -mtune=generic"
  AC_MSG_RESULT([yes])
else
  AC_MSG_RESULT([no])
  DEBUG_CFLAGS=""
  DEBUG_LIBS=""
  AC_SUBST([DEBUG_CFLAGS])
  AC_SUBST([DEBUG_LIBS])
  CXXFLAGS="-Wall -Wextra -O3 -m64 -mtune=generic"
fi

AX_BOOST_BASE([1.47])
#AX_BOOST_ASIO
#AX_BOOST_DATE_TIME
#AX_BOOST_FILESYSTEM
#AX_BOOST_IOSTREAMS
AX_BOOST_PROGRAM_OPTIONS
#AX_BOOST_PYTHON
#AX_BOOST_REGEX
#AX_BOOST_SERIALIZATION
#AX_BOOST_SIGNALS
#AX_BOOST_SYSTEM
#AX_BOOST_TEST_EXEC_MONITOR
#AX_BOOST_THREAD
#AX_BOOST_UNIT_TEST_FRAMEWORK
#AX_BOOST_WSERIALIZATION

dnl Checks for Boost home/root
BOOST_PATH=${ac_boost_path}
AC_SUBST([BOOST_PATH])
if test -z $BOOST_PATH
then
    AC_SUBST([BOOST_PATH], ['/usr'])
fi

# Pass ./configure args to distcheck target otherwise it runs 
# a basic ./configure which isnt the 'make distcheck' you really want.
DISTCHECK_CONFIGURE_FLAGS="${ac_configure_args}"
AC_SUBST([DISTCHECK_CONFIGURE_FLAGS])
#DISTCHECK_CONFIGURE_FLAGS = --enable-warnings=fatal

AC_SUBST([RELEASE_NUMBER], [1])
AC_SUBST([RELEASE], [1])

# RPM vars. Assumes that ~/.rpmmacros is defined and associated directory structure
RPM_BUILD_DIR=$(rpm --eval "%{_builddir}")
AC_SUBST([RPM_BUILD_DIR])

RPM_SOURCE_DIR=$(rpm --eval "%{_sourcedir}")
AC_SUBST([RPM_SOURCE_DIR])

AC_SUBST([RPM_INSTALL_PREFIX0])

AC_CONFIG_FILES([buildCtags], [chmod +x buildCtags])
AC_CONFIG_FILES([create_autoconf_skeleton], [chmod +x create_autoconf_skeleton])
#AC_CONFIG_FILES([need_to_run_autoreconf], [chmod +x need_to_run_autoreconf])

AC_CONFIG_FILES([test_serial], [chmod +x test_serial])

AC_CONFIG_FILES([
    Makefile
    gander.spec
    include/Makefile
    dbgoutput.pc
])
#    testsuite/Makefile
#    tests/Makefile
#    tests/package.m4

AC_OUTPUT
