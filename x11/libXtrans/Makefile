# New ports collection makefile for:   libXtrans
# Date Created:			28 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXtrans
PORTVERSION=	0.1.p1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~anholt/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	network API translation layer for X applications and libraries

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-0.1

.include <bsd.port.mk>
