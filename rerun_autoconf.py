#!/usr/bin/env /usr/bin/python3
# -*- coding: utf-8 -*-

"""
    Pexpect script to run autoconf testsuite
"""
import sys, os, os.path
#import pexpect
import re

#import gobject
from gobject import option
from gobject.option import OptionGroup, OptionParser, make_option

string = '''
####1
ttteest
####1
ttttteeeestt

####2   

ttest
####2'''

def smthng():
    ''''''
    pattern = r'''.*?####(.*?)####'''
    returnmatch = re.compile(pattern, re.MULTILINE).findall(string)
    return returnmatch

subdirs_1line = """
SUBDIRS =   testsuite
"""

subdirs_2line = """
SUBDIRS = testsuite src
"""

subdirs_3line = """
SUBDIRS = \
testsuite src 
"""

subdirs_4line = """
#SUBDIRS = testsuite src 
"""
"""
def pyparsing():
    from pyparsing import makeHTMLTags, SkipTo, htmlComment
    import urllib
    serverListPage = \
    urllib.urlopen( "http://ec2-50-19-170-95.compute-1.amazonaws.com/" )
    htmlText = serverListPage.read()
    serverListPage.close()
    aStart, aEnd = makeHTMLTags("A")
    link = aStart + SkipTo(aEnd).setResultsName("link") + aEnd
    link.ignore(htmlComment)
    for toks, start, end in link.scanString(htmlText):
        print('{} -> {}'.format(toks.link, toks.startA.href))
"""

def main(argv):
    """
    """
    group = OptionGroup("example", "OptionGroup Example", \
        "Shows all example options",
        option_list = [
            make_option("--example",
                        action="store_true",
                        dest="example",
                        help="An example option."),
        ]
    )

    parser = OptionParser("NAMES ...",
        description="A simple gobject.option example.",
        option_list = [
            make_option("--file", "-f",
                        type="filename",
                        action="store",
                        dest="file",
                        help="A filename option"),
            # ...
        ])

    parser.add_option_group(group)

    parser.parse_args()

    print "group: example ", group.values.example
    print "parser: file", parser.values.file

    res = 1

    try:
        #pyparsing()
        #print('{}'.format("pyparsing() done."))
        lun_q = r'''Lun:\s*(\d+(?:\s+\d+)*)'''
        s = '''Lun: 0 1 2 3 295 296 297 298'''

        r = re.search(lun_q, s)
        luns = None
        if r:
            luns = r.group(1).split()

            # optionally, also convert luns from strings to integers
            luns = [int(lun) for lun in luns]
            print('luns: {}'.format(luns))
        else:
            print('{}'.format("Got no Luns"))

        print('smthng: {}'.format(smthng()))
        print(re.findall(r"####(.*?)\s(.*?)\s####", string, re.DOTALL))
        
        # Catches testsuite in [SUBDIRS =   testsuite]
        print('1: {}'.format(re.findall(r'''^SUBDIRS =\s+(.*)''', \
            subdirs_1line, re.MULTILINE)))

        # Catches ['SUBDIRS', 'testsuite', 'src'] in [SUBDIRS =   testsuite src]
        # *** THIS IS THE 1! ***
        # Works for an 
        print('2: {}'.format(re.findall(r'''=\s*(\w+(?:\s+\w+)*)\s*''', \
            subdirs_2line, re.MULTILINE)))
        for iter in re.finditer(r'''(\w+)\s+''', \
            subdirs_2line, re.MULTILINE | re.VERBOSE):
            print('iter: {}'.format(iter.span()))

        # Catches ['SUBDIRS', 'testsuite', 'src'] in [SUBDIRS =   testsuite src]
        print('3: {}'.format(re.findall(
            r'''SUBDIRS\s*=\s*(\w+(?:\s+\w+)*)\s*''', subdirs_3line))
        )
        for iter in re.finditer(r'''SUBDIRS\s*=\s*(\w+(?:\s+\w+)*)\s*''', \
            subdirs_3line, re.MULTILINE | re.VERBOSE):
            print('iter: {}'.format(iter.group()))

        # Catches ['SUBDIRS', 'testsuite', 'src'] in [SUBDIRS =   testsuite src]
        print('4: {}'.format(re.findall(
            r'''^SUBDIRS\s*=\s*(\w+(?:\s+\w+)*)\s*''', subdirs_4line))
        )
        for iter in re.finditer(r'''^SUBDIRS\s*=\s*(\w+(?:\s+\w+)*)\s*''', \
            subdirs_4line, re.MULTILINE | re.VERBOSE):
            print('iter: {}'.format(iter.group()))

        """ Reference: <http://stackoverflow.com/questions/8651347/
        regex-to-match-a-capturing-group-one-or-more-times>

        regx = re.compile('(?:(?<= )|(?<=\A)|(?<=\r)|(?<=\n))'
                  '(\d\d)(\d\d)?(\d\d)?'
                  '(?= |\Z|\r|\n)')

        for s in ('   112233  58975  6677  981  897899\r',
                  '\n123456 4433 789101 41586 56 21365899 362547\n',
                  '0101 456899 1 7895'):
            print repr(s),'\n',regx.findall(s),'\n'
        """
        res = 0
    except Exception, err:
        sys.stderr.write("{}".format(err))
    return res

if __name__ == "__main__":
    sys.exit(main(sys.argv))
