# New ports collection makefile for:   libXp
# Date Created:			4 May 2004
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXp
PORTVERSION=	6.0
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~xorg/release/
DISTNAME=	X11R6.7.0-src1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X print library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11 \
		${X11BASE}/include/X11/extensions/Print.h:${PORTSDIR}/x11/printext
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

CONFLICTS=	XFree86-libraries-*

USE_IMAKE=	YES
DIST_SUBDIR=	xorg
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/xc/lib/Xp
EXTRACT_AFTER_ARGS= | ${TAR} -xf - xc/lib/Xp

.include <bsd.port.mk>
