#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
    Pexpect script to run autoconf testsuite
"""
import sys, os, os.path
#import pexpect
import re

string='''
####1
ttteest
####1
ttttteeeestt

####2   

ttest
####2'''

def smthng():
    pattern = r'''.*?####(.*?)####'''
    returnmatch = re.compile(pattern, re.MULTILINE).findall(string)
    return returnmatch

subdirs_1line="""
SUBDIRS =   testsuite
"""

subdirs_2line="""
SUBDIRS = testsuite src
"""

subdirs_3line="""
SUBDIRS = \
testsuite src
"""

def main(argv):
    """
    """
    res = 1

    try:

        smthng()
        print(re.findall(r"####(.*?)\s(.*?)\s####", string, re.DOTALL))
        
        # Catches testsuite in [SUBDIRS =   testsuite]
        print(re.findall(r'''^SUBDIRS =\s+(.*)''', subdirs_1line, re.MULTILINE))

        # Catches ['SUBDIRS', 'testsuite', 'src'] in [SUBDIRS =   testsuite src]
        print(re.findall(r'''(\w+)\s+''', subdirs_2line, re.MULTILINE))
        for iter in re.finditer(r'''(\w+)\s+''', subdirs_2line, re.MULTILINE | re.VERBOSE):
            print('iter: {}'.format(iter.span()))

        # Catches ['SUBDIRS', 'testsuite', 'src'] in [SUBDIRS =   testsuite src]
        print(re.findall(r'''SUBDIRS\s+=\s+(\w+)\s+''', subdirs_3line))
        for iter in re.finditer(r'''SUBDIRS\s+=\s+(\w+)\s''', subdirs_3line, re.MULTILINE | re.VERBOSE):
            print('iter: {}'.format(iter.group()))
        res = 0
    except Exception, e:
        sys.stderr.write("{}".format(e))
    return 0

if __name__ == "__main__":
    sys.exit(main(sys.argv))
