# New ports collection makefile for:   libXcursor
# Date Created:			22 Nov, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXcursor
PORTVERSION=	1.1.2
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X client-side cursor loading library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11 \
		${X11BASE}/libdata/pkgconfig/xrender.pc:${PORTSDIR}/x11/libXrender \
		${X11BASE}/libdata/pkgconfig/xfixes.pc:${PORTSDIR}/x11/libXfixes
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto \
		${X11BASE}/libdata/pkgconfig/render.pc:${PORTSDIR}/x11/renderext \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

CONFLICTS=	XFree86-libraries-* xorg-libraries-*

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
CFLAGS+=	-DMALLOC_0_RETURNS_NULL
MAN3=		Xcursor.3
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig

.include <bsd.port.mk>
