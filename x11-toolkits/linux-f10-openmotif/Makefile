# New ports collection makefile for:   linux-openmotif
# Date created:                2001-09-24
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	openmotif
PORTVERSION=	2.1.30
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	ftp://ftp.redhat.com/pub/%SUBDIR%/ \
		ftp://ftp.sourceforge.net/pub/mirrors/redhat/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.redhat.com/pub/%SUBDIR%/ \
		ftp://ftp.uni-bayreuth.de/pub/redhat.com/%SUBDIR%/
MASTER_SITE_SUBDIR=	contrib/openmotif/linux-rpm
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=	-1_ICS.${MACHINE_ARCH}.rpm
DIST_SUBDIR=	rpm
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motif toolkit Linux libraries

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm

ONLY_FOR_ARCHS=	alpha i386
USE_LINUX_PREFIX=	yes
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}

EXTRACT_FILES=	usr/X11R6/lib/libMrm.so.2.1 \
		usr/X11R6/lib/libUil.so.2.1 \
		usr/X11R6/lib/libXm.so.2.1

do-install:
	cd ${PREFIX}; \
	    rpm2cpio ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | \
	    ${CPIO} -idum -R ${LIBOWN}:${LIBGRP} ${EXTRACT_FILES}
	chroot ${PREFIX} /sbin/ldconfig

.include <bsd.port.mk>
