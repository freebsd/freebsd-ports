# New ports collection makefile for:   libXdamage
# Date Created:			13 Nov, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXdamage
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Damage extension library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/xfixes.pc:${PORTSDIR}/x11/libXfixes
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/damageext.pc:${PORTSDIR}/x11/damageext \
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

.include <bsd.port.mk>
