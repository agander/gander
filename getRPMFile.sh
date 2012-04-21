#!/bin/bash

# whatprovides

# Leonard den Ottolander, 2003

# Set debugging.
[[ -n "${DEBUG}" ]] && set -x

#alias sysrpm='rpm --dbpath /var/lib/rpm '

get_rpm()
{
    # ${1}: The name of the object you want rpm to do a 'whatprovides' on.
    # ${2}: The assoc. array you want to add to

    local -a RESULTS_LIST=( "$(echo "${1}" |
                            xargs -i rpm --dbpath /var/lib/rpm -q --whatprovides --queryformat="%{NAME}" {})" \
                           )
    local ITEM=""
    for ITEM in ${RESULTS_LIST[@]}
    do
        if [[ ! "${ITEM}" =~ "-debuginfo-" ]]
        then
            if [[ -n "${DEBUG}" ]]
            then
                tput bold
                printf "D:35:=%s\n" ${ITEM}
                tput sgr0
            fi
            RPMS[${ITEM}]+=1
        fi
    done

}

if [[ "${1}" = '' ]]
then
    echo "$(basename ${0}) <search value>";
    exit 1;
else
    if [[ -n "${DEBUG}" ]]
    then
        tput bold
        printf "D:57:Number of args=%d\n" ${#}
        tput sgr0
    fi

fi

declare -iA RPMS
declare -i ARGS_COUNT=${#}
declare -i IDX=0
for ARG in ${*}
do
    get_rpm  ${ARG} ${RPMS}
    if [[ -n "${DEBUG}" ]]
    then
        tput bold
        printf "D:72:get_rpm %s %s\n" "${ARG}" "${RPMS}"
        tput sgr0
    fi

done

if [[ -n "${DEBUG}" ]]
then
    tput bold
    printf "D:77:Number of RPM's found = %d\n" ${#RPMS[@]}
    printf "They are:\n"
    #set | egrep RPMS
    echo ${RPMS[*]}
    tput sgr0

fi

if [[ -n "${DEBUG}" ]]
then
    IDX=0
    for IDX in ${#RPMS[@]}
    do
        printf "%s(%d)\n" "${!RPMS[${IDX}]}"  ${RPMS[${IDX}]} 
    done
fi

echo ${!RPMS[*]}


