# New ports collection makefile for:   fixesext
# Date Created:			29 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fixesext
PORTVERSION=	2.0.p2
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~anholt/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Fixes extension headers and specification

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/xextensions.pc:${PORTSDIR}/x11/xextensions
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-2.0

.include <bsd.port.mk>
