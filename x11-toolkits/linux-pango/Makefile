# New ports collection makefile for:	linux-pango
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	1.10.2
DISTVERSIONSUFFIX=	-1.gst.1.4
PORTREVISION=	4
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	http://gstreamer.freedesktop.org/pkg/%SUBDIR%/ CRITICAL/rpm
MASTER_SITE_SUBDIR=	${LINUX_DIST}/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/RPMS.gst010
MASTER_SITE_SRC_SUBDIR=	${LINUX_DIST}/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/SRPMS.gst010

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux pango binary

CONFLICTS=	linux-f8-pango-[0-9]* linux-f10-pango-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
# these libraries are required by pango-querymodules
USE_LINUX_APPS=	cairo expat fontconfig xorglibs
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin
PLIST_SUB+=	LIBVERSION="1001.1" PORTVERSION="${PORTVERSION}"

post-install:
	@${PREFIX}/usr/bin/pango-querymodules-32 > ${PREFIX}/etc/pango/i686-redhat-linux-gnu/pango.modules

.include <bsd.port.mk>
