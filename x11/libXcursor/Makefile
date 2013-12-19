# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXcursor
PORTVERSION=	1.1.14
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X client-side cursor loading library

LICENSE=	MIT

XORG_CAT=	lib
USE_XORG=	xrender x11 xfixes fixesproto xproto:both \
		xextproto

CONFIGURE_ARGS=	--with-icondir=${PREFIX}/lib/X11/icons

.include <bsd.port.mk>
