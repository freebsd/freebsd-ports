# New ports collection makefile for:   damageext
# Date Created:			29 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	damageext
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Damage extension headers and specification

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/fixesext.pc:${PORTSDIR}/x11/fixesext
BUILD_DEPENDS=	${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}	

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
NO_BUILD=	yes
USE_GNOME=	gnomehack pkgconfig

.include <bsd.port.mk>
