#!/bin/sh
#
# $FreeBSD$

# some defs
GENKDMCONF=%%PREFIX%%/bin/genkdmconf
KDMCONFDIR=%%PREFIX%%/share/config/kdm

#first, set a path for an X app
PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin:/usr/X11R6/bin
export PATH

#Configure kdm if needed
if [ ! -r ${KDMCONFDIR}/kdmrc ]; then
	echo "Generating KDM configuration";
	${GENKDMCONF} --in ${KDMCONFDIR};
fi

