# New ports collection Makefile for:    oooqs
# Date created:                 21 July 2002
# Whom:                         Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	oooqs
PORTVERSION=	2.0
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/segfaultskde/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.R./_rc/}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"Quick launcher for Open Office"

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_KDELIBS_VER=	3

.include <bsd.port.mk>
