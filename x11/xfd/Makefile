# $FreeBSD$

PORTNAME=	xfd
PORTVERSION=	1.1.2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Display all characters in an X font

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

XORG_CAT=	app
USE_XORG=	xft xt xaw
.include <bsd.port.mk>
