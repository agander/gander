#!/bin/bash

USAGE="$(basename ${0}) -p[--project] projectName -d[--directory] DirectoryForIt -i[--import] -h[--help] -o[--overwrite] Overwrite Makefile.am and configure.ac"

[ -n "${DEBUG}" ] && set -x

if [ ${#} -lt 4 ]
then
   echo "${USAGE}"
   exit 1
fi

declare PROJECT_NAME=""
declare PROJECT_DIR=""
declare -i SVN_IMPORT=0
declare -i OVERWRITE=0

MAKEFILE_AM=Makefile.am
MAKEFILE_CVS=Makefile.cvs
CONFIGURE_AC=configure.ac
CONFIGURE_SCAN=configure.scan
RPMSPEC_IN=skeleton.spec.in
PKGCONFIG_IN=skeleton.pc.in

CWD=${PWD}
ONEUP_WD=$(dirname ${PWD})

while getopts "d:p:iho" OPTION
do
  case ${OPTION} in
    h     ) echo "${USAGE}" && exit 1;;
    d     ) PROJECT_DIR=${OPTARG};;
    p     ) PROJECT_NAME=${OPTARG};;
    i     ) SVN_IMPORT=1;;
    o     ) OVERWRITE=1;;
    *     ) ;;   # DEFAULT
  esac
done

if [ ! -d ${PROJECT_DIR} ]
then
   mkdir -p  ${PROJECT_DIR}
   echo "Created ${PROJECT_DIR}"
   cd ${PROJECT_DIR}
   CWD=${PWD}
   ONEUP_WD=$(dirname ${PWD})
fi

if [ ${PROJECT_DIR} == "." ]
then
   PROJECT_DIR=$(basename ${PWD})
fi

if [ ! -d m4 ]
then
   #echo "Copying the m4 directory"
   #cp -pr ~/PROJ/skeleton/m4/ .
   #[ -d m4/.svn ] && rm -fr  m4/.svn
   echo "Setting up the m4 directory and version to 0.0.1"
   mkdir m4
   echo "m4_define([VERSION_NUMBER],[0.0.1])" > m4/version.m4
   echo "m4_define([RELEASE_NUMBER],[1])" > m4/release.m4
   #cat m4/version.m4
else
   echo "m4 directory exists"
fi

# Run autoscan
if [ ! -s ${CONFIGURE_SCAN} ]
then
   echo "Running autoscan"
   autoscan --include=${PWD}
fi

# Setting up a short header (hpp) file
HPP=${PROJECT_NAME}.hpp
CPP=${PROJECT_NAME}.cpp

if [ ! -s ${HPP} ]
then
    echo "Setting up ${HPP}"
    #echo -e "\n//\$Id: $\n\n#include <iostream>\n\n" > ${HPP}
    cat ~/PROJ/skeleton/skeleton.hpp |
    sed "s/%HEADER_DEF%/${PROJECT_NAME^^*}/g" > ${HPP}
else
    if [ ${OVERWRITE} -eq 1 ]
    then
        echo "Overwriting ${HPP}"
        #echo -e "\n//\$Id: $\n\n#include <iostream>\n\n" > ${HPP}
        cat ~/PROJ/skeleton/skeleton.hpp |
        sed "s/%HEADER_DEF%/${PROJECT_NAME^^*}/g" > ${HPP}
    else
        echo "${HPP} aleady exists. Not overwriting."
    fi
fi


# Setting up a short source (cpp) file
if [ ! -s ${CPP} ]
then
    echo "Setting up ${CPP}"
    #echo -e "\n//\$Id: $\n\n#include \"${HPP}\"\n\n" > ${CPP}
    cat ~/PROJ/skeleton/skeleton.cpp |
    sed "s/%HEADER_FILE%/${PROJECT_NAME}/g" > ${CPP}
else
    if [ ${OVERWRITE} -eq 1 ]
    then
        echo "Overwriting ${CPP}"
        #echo -e "\n//\$Id: $\n\n#include \"${HPP}\"\n\n" > ${CPP}
        #echo -e "\n//\$Id: $\n\n#include \"faCpp.hpp\"\n\nint main( int argc, char** argv )\n{\n   return 0;\n}\n" > ${CPP}
        cat ~/PROJ/skeleton/skeleton.cpp |
        sed "s/%HEADER_FILE%/${PROJECT_NAME}/g" > ${CPP}
    else
        echo "${CPP} aleady exists. Not overwriting."
    fi
fi



# Setting up Makefile.cvs

if [ ! -s ${MAKEFILE_CVS} ]
then
   echo "Setting up ${MAKEFILE_CVS}"
   cp ~/PROJ/skeleton/${MAKEFILE_CVS} .
else
   echo "${MAKEFILE_CVS} aleady exists. Not overwriting."
fi


# Setting up Makefile.am

if [ ! -s ${MAKEFILE_AM} ]
then
   echo "Setting up ${MAKEFILE_AM}"
   cat ~/PROJ/skeleton/${MAKEFILE_AM} |
   sed "s/%PROGRAM%/${PROJECT_NAME}/g" |
   sed "s/%EMAIL%/agander@gmail.com/g" > ${MAKEFILE_AM}
else
   if [ ${OVERWRITE} -eq 1 ]
   then
      echo "Overwriting ${MAKEFILE_AM}"
      cat ~/PROJ/skeleton/${MAKEFILE_AM} |
      sed "s/%PROGRAM%/${PROJECT_NAME}/g" |
      sed "s/%EMAIL%/agander@gmail.com/g" > ${MAKEFILE_AM}
   else
      echo "${MAKEFILE_AM} aleady exists. Not overwriting."
   fi
fi


# Setting up configure.ac

if [ ! -s ${CONFIGURE_AC} ]
then
   echo "Setting up ${CONFIGURE_AC}"
   cat ~/PROJ/skeleton/${CONFIGURE_AC} |
   sed "s/%PROGRAM%/${PROJECT_NAME}/g" |
   sed "s/%EMAIL%/agander@gmail.com/g" > ${CONFIGURE_AC}
else
   if [ ${OVERWRITE} -eq 1 ]
   then
      echo "Overwriting ${CONFIGURE_AC}"
      cat ~/PROJ/skeleton/${CONFIGURE_AC} |
      sed "s/%PROGRAM%/${PROJECT_NAME}/g" |
      sed "s/%EMAIL%/agander@gmail.com/g" > ${CONFIGURE_AC}
   else
      echo "${CONFIGURE_AC} aleady exists. Not overwriting."
   fi
fi


# Setting up skeleton.spec.in

# Setting up skeleton.pc.in


# Checkin to svn

if [ ${SVN_IMPORT} -eq 1 ]
then
    if [ "$(hostname)" =~ "^agander" ]
    then
        echo "Import of ${PROJECT_NAME} requested"
        if [ $(svn info >/dev/null 2>&1; echo "${?}") -gt 0 ]
        then
            svn mkdir svn://agander/PROJ/${PROJECT_NAME} -m "Base dir of ${PROJECT_NAME}."
            if [ ${?} -eq 0 ]
            then
                #cd ${ONEUP_WD}
                #svn import ${PROJECT_NAME} \
                svn import . \
                    svn://agander/PROJ/${PROJECT_NAME}/trunk \
                    -m "Initial import of ${PROJECT_NAME}."
                if [ ${?} -eq 0 ]
                then
                    #mv ${PROJECT_DIR} ${PROJECT_DIR}.orig
                     svn co --force svn://agander/PROJ/${PROJECT_NAME}/trunk .
                fi
                #cd ${PROJECT_NAME}
             else
                 echo "Unable to do: 'svn mkdir \"svn://agander/PROJ/${PROJECT_NAME}'. It already exists.\""
             fi
        else
            echo "Cannot import. svn project already exists: "
            echo "$(svn info ${PROJECT_NAME} | grep URL|sed 's/URL: //g')"
        fi

    fi
else
    echo "!!! WARNING - svn import not implemented on this machine at this time!"
fi


exit 0

