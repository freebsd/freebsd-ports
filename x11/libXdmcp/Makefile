# New ports collection makefile for:   libXdmcp
# Date Created:			28 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXdmcp
PORTVERSION=	0.1.p1
CATEGORIES=	x11
MASTER_SITES=	http://people.freebsd.org/~anholt/X/files/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Display Manager Control Protocol library

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-0.1
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
