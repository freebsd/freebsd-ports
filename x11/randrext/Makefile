# New ports collection makefile for:   randrext
# Date Created:			24 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	randrext
PORTVERSION=	1.0.p2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~anholt/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Header files and documentation for the X Resize and Rotate extension

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-1.0

.include <bsd.port.mk>
