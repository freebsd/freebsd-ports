# New ports collection makefile for:   libXext
# Date Created:			29 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXfixes
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Fixes extension library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/fixesext.pc:${PORTSDIR}/x11/fixesext \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CFLAGS+=	-DMALLOC_0_RETURNS_NULL
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig

BROKEN=		Does not compile

.include <bsd.port.mk>
