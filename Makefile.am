
# $Id: Makefile.am 571 2010-06-19 17:39:26Z gander $

AUTOMAKE_OPTIONS = gnu

ACLOCAL_AMFLAGS   =  -I m4

#SUBDIRS = config po lib data src doc tests

INCLUDES = -I$(top_srcdir) $(LIBMYSQLPP_CFLAGS)
LIBS		= $(LIBMYSQLPP_LIBS)

bin_PROGRAMS   =  gander

gander_SOURCES   =  gander.cpp gander.hpp

#gander_CPPFLAGS = -DDEBUG -ggdb -D__USE_STD_IOSTREAM 

#gander_LDFLAGS = -lxerces-c

#gander_CXXFLAGS = -pthread $(LIBGLADEMM_CFLAGS) $(LIBMYSQLPP_CFLAGS)
#gander_LDADD    = -L/usr/local/lib $(LIBGLADEMM_LIBS) $(LIBMYSQLPP_LIBS)
#gander_LDFLAGS  = -lmylogin

EXTRA_DIST  = gander.hpp

DISTCLEANFILES =  .deps/*.Po

#TESTS =   "$(bin_PROGRAMS) a=b c=d"

# Not sure I need these ...?
#.PHONY: maintainer-check
#maintainer-check:
#	cd tests && $(MAKE) $(AM_MAKEFLAGS) $@

#lib_LTLIBRARIES = libmylogin.la
#libmylogin_la_SOURCES  = mylogin_class.hpp mylogin_class.cpp split.hpp
#libmylogin_la_CXXFLAGS = $(LIBMYSQLPP_CFLAGS) -m64 -mtune=k8
##libmylogin_la_LIBADD    = -lboost_filesystem
##libmylogin_la_LDFLAGS  = -version-info 1:0 -lmysqlpp -lmysqlclient_r
#libmylogin_la_LDFLAGS  = -version-info 1:0 $(LIBMYSQLPP_LIBS)


#pkgincludedir = $(includedir)
#libmylogindir  =  $(pkgincludedir)
#pkgconfigdir		= $(libdir)/pkgconfig
#pkgconfig_DATA		= libmylogin.pc

#libmylogin_includedir=$(pkgincludedir)
#libmylogin_include_HEADERS = mylogin_class.hpp
#libmylogin_HEADERS = mylogin_class.hpp

#EXTRA_DIST  = mylogin_class.hpp libmylogin.pc libmylogin.spec \
#				  libmylogin.pc.in libmylogin.spec.in

#MYLOGIN_LIB = $(top_builddir)/libmylogin.la

check_PROGRAMS = gander

TESTS = $(check_PROGRAMS)

#basic_SOURCES  =  basic.cpp
#basic_CXXFLAGS = $(LIBMYSQLPP_CFLAGS) -m64 -mtune=k8
#basic_LDADD =  -L$(top_builddir)
#basic_LDFLAGS =  $(LIBMYSQLPP_LIBS) $(top_builddir)/libmylogin.la

# Man config
# Notes on the man/groff style are at:
# http://linux.die.net/man/7/man-pages
# Also, converting Perl pod pages to man is useful with:
# pod2man /usr/lib/perl5/5.10.0/Test/Tutorial.pod
# Which was found at:
# http://www.linuxfocus.org/English/November2003/article309.shtml#309lfindex7
# Which is how the following was generated:
dist_man_MANS = test_tutorial.3



