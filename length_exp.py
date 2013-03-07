#!/usr/bin/python

import sys, os, os.path
from pexpect import *
child = spawn('./length', [])
#child.expect ('')
child.sendline('mypassword')
child.expect ('12')


