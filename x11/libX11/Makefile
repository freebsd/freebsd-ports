# New ports collection makefile for:   libX11
# Date Created:			28 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libX11
PORTVERSION=	6.2.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/xau.pc:${PORTSDIR}/x11/libXau \
		${X11BASE}/libdata/pkgconfig/xdmcp.pc:${PORTSDIR}/x11/libXdmcp
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/xextensions.pc:${PORTSDIR}/x11/xextensions \
		${X11BASE}/libdata/pkgconfig/xtrans.pc:${PORTSDIR}/x11/libXtrans \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

CONFLICTS=	XFree86-libraries-* xorg-libraries-*

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
CONFIGURE_ARGS+= --enable-xdmauth
CFLAGS+=	-DMALLOC_0_RETURNS_NULL
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig

.include <bsd.port.mk>
