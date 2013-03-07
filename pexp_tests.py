#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
    Pexpect script to run autoconf testsuite
"""
import sys, os, os.path
import pexpect

def main(argv):
    """"""
    cmd ='./length'
    child = pexpect.spawn(cmd, args=[], timeout=1)
    #child.expect([pexpect.EOF])
    child.expect([])
    length = child.sendline('12')
    return 0

if __name__ == "__main__":
    sys.exit(main(sys.argv))
