# ex:ts=8
# Ports collection makefile for:	grabc
# Date Created:			Dec 30, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	grabc
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://muquit.com/muquit/software/grabc/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Grab a color from screen

PLIST_FILES=	bin/grabc
USE_XORG=	x11
CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
