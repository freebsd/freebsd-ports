# New ports collection makefile for:   libICE
# Date Created:			09 Nov, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libICE
PORTVERSION=	6.3.1.p2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~anholt/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Inter Client Exchange library for X11

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		${X11BASE}/libdata/pkgconfig/xtrans.pc:${PORTSDIR}/x11/libXtrans \
		${X11BASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-6.3.1

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
