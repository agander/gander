#!/bin/bash

# Set debugging.
[ -n "${DEBUG}" ] && set -x

for DIR in ~/.thumbnails
do
    FILES_FOUND=($(find ${DIR} -name '*' -type f))
    [ -n "${DEBUG}" ]  && find ${DIR} -name '*' -type f
    printf "%s has %d files.\n" ${DIR} ${#FILES_FOUND}
    if [ ${#FILES_FOUND} -gt 0 ]
    then
        find ${DIR} -name '*' -type f -exec rm -f {} \;
    fi
done

for DIR in ~/.macromedia 
do
    #SYS_SOL_FOUND=($(find ${DIR} -name 'settings.sol' -type f | grep -FzZ 'flashplayer/sys/settings.sol'))
    FILES_FOUND=($(find ${DIR} -name '*' -type f))
    SYS_SOL_FOUND="$(locate 'flashplayer/sys/settings.sol')"
    if [ ${#FILES_FOUND} -gt 1 ]
    then
        if [ -n "${SYS_SOL_FOUND}" ]
        then
            SYS_SOL_PATH=$(dirname ${SYS_SOL_FOUND})
            printf "sys/settings.sol: %s.\n" ${SYS_SOL_FOUND}
            CP_FILE="/tmp/${USER}_sys_settings.sol$$"
            cp -p ${SYS_SOL_FOUND} ${CP_FILE}
        fi
        rm -fr ${DIR}
        mkdir --parent ${SYS_SOL_PATH}
        mv ${CP_FILE}  ${SYS_SOL_PATH}/settings.sol
    fi
done

if [ -d /tmp/hsperfdata_gander ]
then
    rm -fr /tmp/hsperfdata_gander
fi

[ -n "${DEBUG}" ] && sleep 10

