# New ports collection makefile for:   xextensions
# Date Created:			28 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xextensions
PORTVERSION=	1.0.p1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~anholt/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 extension headers

WRKSRC=		${WRKDIR}/${PORTNAME}-${REALVERSION}
USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-1.0

.include <bsd.port.mk>
