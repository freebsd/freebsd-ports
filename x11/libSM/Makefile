# New ports collection makefile for:   libSM
# Date Created:			09 Nov, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libSM
PORTVERSION=	6.0.2
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Session Management library for X11

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/ice.pc:${PORTSDIR}/x11/libICE \
		${X11BASE}/libdata/pkgconfig/xtrans.pc:${PORTSDIR}/x11/libXtrans
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		${X11BASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

CONFLICTS=	XFree86-libraries-*

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_LIBTOOL_VER=13

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
