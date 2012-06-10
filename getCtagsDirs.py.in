#!/usr/bin/python -O
""" """

from __future__ import with_statement
import sys, os, os.path
from re import sub

def increment(x):
    """ """
    return x + 1

def chop_after_include(path, debug):
    """
        Chop off everything after the name include.
        i.e. /home/gander/d/gdc024/include/d/4.3.1/tango/math
        becomes /home/gander/d/gdc024/include
    """
    sub('\n$', '', path)
    #parts = path.split('/')
    #sys.stderr.write("D:20:%s\n" % (parts))
    #up_to_include = ""
    #for part in parts:
    #    up_to_include.join("/" + part)
    #    if part == 'include': break
    #sys.stderr.write("D:25:path.find(\"include/\"): %s\n" \
    #                 % (path.find("include/")))
    #sys.stderr.write("D:27:path.find(\"include/\"): %s\n" \
    #                 % (path.find("/include/")))
    #cut_off = (path.rfind("/include/") + 8)
    cut_off = path.index("/include/")
    cut_off = cut_off + 8
    if debug:
        sys.stderr.write("D:30:path[ :%d ]%s\n" % (cut_off, path[ :cut_off ]))
    return path[ :cut_off ]
    #return up_to_include

def main(argv):
    """ """
    debug_request = 1 if len(argv) > 2 else None
    dirnames = {}
    recsRead = 0
    # Compile the regex
    #chop_re = compile(
    #with (sys.stdin.read()) as line:
    #for line in sys.stdin:
    #with (sys.stdin.read()) as line:
    stream = argv[1] if len(argv) > 1 else sys.stdin
    for line in stream:
        line = line[:(len(line))]
        recsRead += 1
        #rfind
        incl_dir = chop_after_include(line, debug_request)
        #sys.stderr.write("D:46:%s\n" % incl_dir)
        #re.sub('\/include\/')
        if not dirnames.has_key( incl_dir ):
            dirnames[ incl_dir ] = 1
        else:
            dirnames[ incl_dir ] \
                = increment( dirnames[ incl_dir ] )

    sys.stderr.write("recs read: %d; include dirs collected: %d\n" \
            % ( recsRead, len(dirnames)) )
    # Spit 'em out
    for incl_dir, count in dirnames.iteritems():
        sys.stdout.write("%s\n" % (incl_dir))

if __name__ == "__main__":
    sys.exit(main(sys.argv))

