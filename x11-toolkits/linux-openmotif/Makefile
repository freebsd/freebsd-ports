# $FreeBSD$

PORTNAME=	openmotif
PORTVERSION=	2.2.4
PORTREVISION=	4
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	CRITICAL/rpm
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=	-0.1.i386.rpm
DIST_SUBDIR=	rpm
EXTRACT_ONLY=

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Motif toolkit Linux libraries

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm

CONFLICTS=	linux-f8-openmotif-[0-9]* linux-f10-openmotif-[0-9]*

# EXPIRATION_DATE is the EoL of the last 7.x release
EXPIRATION_DATE=2013-02-28
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	4
NO_BUILD=	yes
SRC_DISTFILES=

EXTRACT_FILES=	./usr/X11R6/lib/libMrm.so.3.0.3 \
		./usr/X11R6/lib/libUil.so.3.0.3 \
		./usr/X11R6/lib/libXm.so.3.0.3

do-install:
	cd ${PREFIX}; \
	    rpm2cpio ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | \
	    ${CPIO} -idum -R ${LIBOWN}:${LIBGRP} ${EXTRACT_FILES}
	chroot ${PREFIX} /sbin/ldconfig

.include <bsd.port.mk>
