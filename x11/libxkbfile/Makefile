# New ports collection makefile for:   libxkbfile
# Date Created:			7 May 2004
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxkbfile
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/X11R6.7.0/src/ \
		${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R6.7/tars
DISTNAME=	X11R6.7.0-src1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XKB file library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/xextensions.pc:${PORTSDIR}/x11/xextensions \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

CONFLICTS=	XFree86-libraries-* xorg-libraries-*

USE_IMAKE=	yes
USE_X_PREFIX=	no
PREFIX?=	${X11BASE}
DIST_SUBDIR=	xorg
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/xc/lib/xkbfile
EXTRACT_AFTER_ARGS= | ${TAR} -xf - xc/lib/xkbfile

post-patch:
	${LN} -s ${WRKSRC}/exports/include/X11 ${WRKSRC}/

.include <bsd.port.mk>
