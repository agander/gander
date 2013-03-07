

AUTOMAKE_OPTIONS = dejagnu

#SUBDIRS = config po lib data src doc tests

AM_COLOR_TESTS=always

#RUNTEST = ${top_srcdir}/runtest
RUNTESTDEFAULTFLAGS = --srcdir $(srcdir)/testsuite
#RUNTEST=$(RUNTEST)

#export DEJAGNU
#DEJATOOL            = length

#RUNTESTDEFAULTFLAGS = --tool $$tool --srcdir $$srcdir
EXPECT = expect

#$(RUNTEST) --tool length length.exp
check-length: site.exp
	$(RUNTEST) length.exp

check-timeseed:	site.exp
	$(RUNTEST) timeseed.exp

DISTCLEANFILES =  testrun.sum \
				  testrun.log

