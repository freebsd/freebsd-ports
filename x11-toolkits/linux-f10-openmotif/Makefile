# New ports collection makefile for:   linux-openmotif
# Date created:                2001-09-24
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	openmotif
PORTVERSION=	2.2.4
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	ftp://ftp.ics.com/pub/Products/Motif/%SUBDIR%/
MASTER_SITE_SUBDIR=	om2.2.4/redhat-7.3
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=	-0.1.${MACHINE_ARCH}.rpm
DIST_SUBDIR=	rpm
EXTRACT_ONLY=

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Motif toolkit Linux libraries

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_LINUX_PREFIX=	yes
USE_XLIB=	yes
NO_BUILD=	yes
MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}

EXTRACT_FILES=	./usr/X11R6/lib/libMrm.so.3.0.3 \
		./usr/X11R6/lib/libUil.so.3.0.3 \
		./usr/X11R6/lib/libXm.so.3.0.3

do-install:
	cd ${PREFIX}; \
	    rpm2cpio ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | \
	    ${CPIO} -idum -R ${LIBOWN}:${LIBGRP} ${EXTRACT_FILES}
	chroot ${PREFIX} /sbin/ldconfig

.include <bsd.port.mk>
