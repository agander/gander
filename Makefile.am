
AUTOMAKE_OPTIONS = dejagnu
#AUTOMAKE_OPTIONS = gnu

ACLOCAL_AMFLAGS	= -I build ${ACLOCAL_FLAGS}

SUBDIRS = include 
#testsuite 

#AM_INCLUDES = -I$(top_srcdir) -I$(top_srcdir)/include
#LIBS		= $(GLIBMM_LIBS)

bin_PROGRAMS   =  length

length_SOURCES  =  length.cpp
length_CPPFLAGS = $(BOOST_CPPFLAGS) @DEBUG_CFLAGS@ -I$(top_srcdir)/include
length_CXXFLAGS = -pthread $(GLIBMM_CFLAGS)
length_LDADD    =  $(BOOST_PROGRAM_OPTIONS_LIB) $(GLIBMM_LIBS)
length_LDFLAGS  = $(BOOST_LDFLAGS)

bin_PROGRAMS += serial
serial_SOURCES = serial.cpp
serial_CPPFLAGS = @STDCXX_0X_CFLAGS@ @BOOST_CPPFLAGS@ @GLIBMM_CFLAGS@
#serial_CXXFLAGS = -D_GLIBCXX_PROFILE @BOOST_CPPFLAGS@
#serial_CFLAGS = @GSL_CFLAGS@
serial_LDFLAGS  =  @GLIBMM_LIBS@

#EXTRA_DIST	=  t1.txt

DISTCLEANFILES =  .deps/*.Po tests/atconfig

dist_bin_SCRIPTS	=	buildCtags
BUILDCTAGSSOURCES	=	buildCtags.in

dist_bin_SCRIPTS	+=	create_autoconf_skeleton
CREATE_AUTOCONF_SKELETONSOURCES	= create_autoconf_skeleton.in

#dist_bin_SCRIPTS	=	need_to_run_autoreconf
#NEED_TO_RUN_AUTORECONFSOURCES = need_to_run_autoreconf.in

CLEANFILES = $(dist_bin_SCRIPTS)

do_subst = sed -e 's,[@]datadir[@],$(datadir),g' \
           -e 's,[@]PYTHON[@],$(PYTHON),g' \
           -e 's,[@]BASH[@],$(BASH),g' \
           -e 's,[@]PERL[@],$(PERL),g' \
           -e 's,[@]PACKAGE[@],$(PACKAGE),g' \
           -e 's,[@]VERSION[@],$(VERSION),g'

# RPM generation steps.
#rpmbuild --define="_prefix $(prefix)" --define="boost_path ${ac_boost_path}" -ba pword.spec
#rpmbuild --sign --define="_prefix $(prefix)" --define="_boost_path ${BOOST_PATH}" -ba @PACKAGE_TARNAME@.spec
rpm: distcheck dist
	cp -p $(distdir).tar.gz @RPM_SOURCE_DIR@
	rpmbuild --define="_prefix $(prefix)" --define="_boost_path ${BOOST_PATH}" -ba @PACKAGE_TARNAME@.spec


#buildCtags: buildCtags.in Makefile
#	$(do_subst) < $(srcdir)/buildCtags.in > buildCtags
#	chmod +x buildCtags


#TESTS =   "$(bin_PROGRAMS) a=b c=d"

# Not sure I need these ...?
#.PHONY: maintainer-check
#maintainer-check:
#	cd tests && $(MAKE) $(AM_MAKEFLAGS) $@

#lib_LTLIBRARIES = libmylogin.la
#libmylogin_la_SOURCES  = mylogin_class.hpp mylogin_class.cpp split.hpp
#libmylogin_la_CXXFLAGS = $(GLIBMM_CFLAGS) -m64 -mtune=k8
##libmylogin_la_LIBADD    = -lboost_filesystem
##libmylogin_la_LDFLAGS  = -version-info 1:0 -lmysqlpp -lmysqlclient_r
#libmylogin_la_LDFLAGS  = -version-info 1:0 $(GLIBMM_LIBS)

#pkgincludedir = $(includedir)
#libmylogindir  =  $(pkgincludedir)

#pkgconfigdir = $(libdir)/pkgconfig
#nodist_pkgconfig_DATA = glib/$(GLIBMM_MODULE_NAME).pc gio/$(GIOMM_MODULE_NAME).pc

pkgconfigdir		= $(libdir)/pkgconfig
pkgconfig_DATA		= dbgoutput.pc

#libmylogin_includedir=$(pkgincludedir)
#libmylogin_include_HEADERS = mylogin_class.hpp
#libmylogin_HEADERS = mylogin_class.hpp

#EXTRA_DIST  = mylogin_class.hpp libmylogin.pc libmylogin.spec \
#				  libmylogin.pc.in libmylogin.spec.in

#MYLOGIN_LIB = $(top_builddir)/libmylogin.la

check_PROGRAMS	=	test_time_seed
check_SCRIPTS	=	test_serial

TESTS = $(check_PROGRAMS) \
		$(check_SCRIPTS)

test_time_seed_SOURCES   =  test_time_seed.cpp 
#general.hpp
test_time_seed_CPPFLAGS = -I$(top_srcdir)/include -I$(top_builddir)/include \
						  $(BOOST_CPPFLAGS) @STDCXX_0X_CFLAGS@ @DEBUG_CFLAGS@
#test_time_seed_LDFLAGS = -lxerces-c

TEST_SERIALSOURCES	=	test_serial.in

#rm -fr t/
#mkdir t && cd t/ && mkdir dtmpl.dir && \
#echo "#!$(SHELL)" > dtmpl_good.sh && chmod ug+x dtmpl_good.sh && > dtmpl_nbg.sh &&\
#chmod ug+x dtmpl_nbg.sh && ls -l && ./dtmpl dtmpl
#rm -fr t/

# Testsuite.

#TESTSUITE_FILES = \
#	testsuite/length.exp

#testsuite/runtest.all/topdir/subdir1/subfile1 \
#testsuite/runtest.all/topdir/subdir1/subfile2 \
#testsuite/runtest.all/topdir/subdir2/subfile2 \
#testsuite/runtest.all/libs.exp \
#testsuite/runtest.all/options.exp \
#testsuite/runtest.all/remote.test \
#testsuite/runtest.all/stats-sub.exp \
#testsuite/runtest.all/stats.exp \
#testsuite/runtest.all/target.test \
#testsuite/runtest.all/utils.test \
#testsuite/runtest.all/clone_output.test \
#testsuite/runtest.all/config.test \
#testsuite/runtest.all/default_procs.tcl \
#testsuite/config/default.exp \
#testsuite/lib/libsup.exp \
#testsuite/lib/util-defs.exp \
#testsuite/libdejagnu/tunit.exp

#RUNTEST = ${top_srcdir}/runtest
#RUNTESTDEFAULTFLAGS = --srcdir $(srcdir)/testsuite 
#RUNTEST=$(RUNTEST)

#export DEJAGNU

#DEJATOOL            = length

# Testsuite/check forwarding targets.
#check-length:
#	AMOUNT=$((( ${RANDOM}*5 ))) \
#	export AMOUNT; \
#	base64 < /dev/urandom 


#basic_SOURCES  =  basic.cpp
#basic_CXXFLAGS = $(GLIBMM_CFLAGS) -m64 -mtune=k8
#basic_LDADD =  -L$(top_builddir)
#basic_LDFLAGS =  $(GLIBMM_LIBS) $(top_builddir)/libmylogin.la

# Man config
# Notes on the man/groff style are at:
# http://linux.die.net/man/7/man-pages
# Also, converting Perl pod pages to man is useful with:
# pod2man /usr/lib/perl5/5.10.0/Test/Tutorial.pod
# Which was found at:
# http://www.linuxfocus.org/English/November2003/article309.shtml#309lfindex7
# Which is how the following was generated:
#dist_man_MANS = test_tutorial.3




