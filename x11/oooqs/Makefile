# New ports collection Makefile for:    oooqs
# Date created:                 21 July 2002
# Whom:                         Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	oooqs
PORTVERSION=	1.0.R.3
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/segfaultskde/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.R./_rc/}

MAINTAINER=	arved@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_KDELIBS_VER=	3

post-install:
	@${LN} -s ${PREFIX}/share/doc/HTML/en/common ${PREFIX}/share/doc/HTML/en/oooqs/common

.include <bsd.port.mk>
