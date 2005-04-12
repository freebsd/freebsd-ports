# New ports collection makefile for:   libXrandr
# Date Created:			9 Nov, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXrandr
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/~ajax/xlibs-release/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Resize and Rotate extension library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/xext.pc:${PORTSDIR}/x11/libXext \
		${X11BASE}/libdata/pkgconfig/xrender.pc:${PORTSDIR}/x11/libXrender
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/randr.pc:${PORTSDIR}/x11/randrext \
		${X11BASE}/libdata/pkgconfig/xextensions.pc:${PORTSDIR}/x11/xextensions \
		${X11BASE}/libdata/pkgconfig/render.pc:${PORTSDIR}/x11/renderext \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

CONFLICTS=	XFree86-libraries-* xorg-libraries-*

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
CFLAGS+=	-DMALLOC_0_RETURNS_NULL
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig

.include <bsd.port.mk>
