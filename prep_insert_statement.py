#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from re import sub, IGNORECASE
from datetime import  datetime


def conv_date(input_date_str = None, verbose = False):
    """
    """
    #print "dir(datetime):" % (dir(datetime))
    #dt_str="28/11/2012"
    conv_date_str = ''
    try:
        date_obj = datetime.strptime(input_date_str, '%d/%m/%Y')
        if verbose:
            print('try(date_obj): {}'.format(date_obj))
        #print("now() as ISO date: {}".format(datetime(2013, 03, 12).strftime('%F')))
        #print("dt_str as ISO date: {}".format(dt_obj.strftime('%F')))
        conv_date_str = "{}".format(date_obj.strftime('%F'))
        if verbose:
            print('try(conv_date_str): {}'.format(conv_date_str))
    except Exception, error:
        #conv_date_str = None
        pass
    if verbose:
        print('conv_date_str: {}'.format(conv_date_str))
    return conv_date_str

def main(argv):
    """
    Number,Date,Account,Amount,Subcategory,Memo
    ,26/11/2012,20-16-12 30136646,-332.00,PAYMENT,R. W. GENT            RENT               BBP
    """
    verbose = False
    drop_header = True
    res = 1
    table = argv[1]
    try:
        idx = 1
        lines = sys.stdin.readlines()
        #for line in sys.stdin.readline():
        for line in lines:
            line = sub(r'''\x0a$''', "", line )
            line = sub(r'''\x0d$''', "", line )
            fields = line.split(',')
            fields[0] = sub(r'''^\s{1,}$''', "", fields[0])
            if verbose:
                print('Before:try(fields[1]): {}'.format(fields[1]))
            fields[1] = conv_date(fields[1], verbose)
            if verbose:
                print('After: try(fields[1]): {}'.format(fields[1]))
            #fields[5] = "'{}'".format(fields[5])
            fields[5] = sub(r'''\s\xa3''', " GBP ", fields[5])
            fields[5] = sub(r'''\s{2,}''', " ", fields[5])
            fields[5] = sub(r'''( EARNED)''', " EARNED", fields[5], IGNORECASE)
            fields[5] = sub(r'''(LESS TAX)''', " LESS TAX", fields[5], IGNORECASE)
            print("INSERT INTO {} VALUES(DEFAULT,'{}','{}','{}',{},'{}','{}');"\
                .format(table, fields[0], fields[1], \
                    fields[2], fields[3], fields[4], fields[5]
                    )
                )
        res = 0
    except Exception, e:
        sys.stderr.write("*** ERROR {}.\n".format(e))
        res = 1
    return res


if __name__=='__main__':
    #unittest.main()
    sys.exit(main(sys.argv))

