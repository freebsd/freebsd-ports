# New ports collection makefile for:   xrender
# Date Created:			2 Jul, 2003
# Whom:				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXrender
PORTVERSION=	0.8.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/
DISTNAME=	xrender-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XRender extension for XFree86

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/ice.pc:${PORTSDIR}/x11/xextensions
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		${X11BASE}/libdata/pkgconfig/render.pc:${PORTSDIR}/x11-toolkits/render \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
CFLAGS+=	-DMALLOC_0_RETURNS_NULL

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
