# New ports collection makefile for:   libXv
# Date Created:			13 Nov, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXv
PORTVERSION=	2.2.1.p1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/dist/
DISTNAME=	${PORTNAME}-${REALVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 Extension library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		${X11BASE}/libdata/pkgconfig/xextensions.pc:${PORTSDIR}/x11/xextensions \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CFLAGS+=	-DMALLOC_0_RETURNS_NULL
WRKSRC=		${WRKDIR}/${PORTNAME}-2.2.1
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
