# New ports collection makefile for:   libXau
# Date Created:			29 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXau
PORTVERSION=	0.1.p1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~anholt/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Authentication Protocol library for X11

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		${X11BASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-0.1

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
