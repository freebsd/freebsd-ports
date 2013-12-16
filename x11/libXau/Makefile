# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXau
PORTVERSION=	1.0.8
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Authentication Protocol library for X11

XORG_CAT=	lib
USE_XORG=	xproto:both

post-install:
	${LN} -sf ${PREFIX}/lib/libXau.so.6 ${STAGEDIR}${PREFIX}/lib/libXau.so.0

.include <bsd.port.mk>
