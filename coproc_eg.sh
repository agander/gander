#!/bin/bash
# A coprocess communicates with a while-read loop.


coproc { cat coproc_eg.txt; }
#                         ^^^^^^^
# Try running this without "sleep 2" and see what happens.

while read -u ${COPROC[0]} LINE    #  ${COPROC[0]} is the
do                                 #+ file descriptor of the coprocess.
  echo "${LINE}" | sed -e 's/line/NOT-ORIGINAL-TEXT/'
done

#kill -9 ${COPROC_PID}                   #  No longer need the coprocess,
                                   #+ so kill its PID.
