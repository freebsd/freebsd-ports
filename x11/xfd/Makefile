# $FreeBSD$

PORTNAME=	xfd
PORTVERSION=	1.1.2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Display all characters in an X font

LICENSE=	MIT

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

XORG_CAT=	app
USE_XORG=	xft xt xaw

MAN1=		xfd.1

.include <bsd.port.mk>
