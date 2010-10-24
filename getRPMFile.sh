#!/bin/sh

# whatprovides

# Leonard den Ottolander, 2003

#alias sysrpm='rpm --dbpath /var/lib/rpm '

if [ "$1" = '' ]; then
  #echo "empty search value";
  echo "$(basename ${0}) <search value>";
  exit 1;
fi

[ -n "${DEBUG}" ] && echo "\"$1\" found in:";

#rpm -qal | grep "${1}" |
locate "${1}" |

xargs -i rpm --dbpath /var/lib/rpm -q --whatprovides {} | 

sort -u # |

#sort -u

# end of whatprovides
