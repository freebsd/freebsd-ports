# New ports collection makefile for:   libXext
# Date Created:			29 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXres
PORTVERSION=	1.0.1.p1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~anholt/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Resource usage library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		${X11BASE}/libdata/pkgconfig/resourceext.pc:${PORTSDIR}/x11/resourceext \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL=	yes
CFLAGS+=	-DMALLOC_0_RETURNS_NULL
WRKSRC=		${WRKDIR}/${PORTNAME}-1.0.1
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
