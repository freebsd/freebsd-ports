# $FreeBSD$

PORTNAME=	xbacklight
PORTVERSION=	1.2.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Program to adjust backlight brightness

LICENSE=	MIT

LIB_DEPENDS=	libxcb-util.so:${PORTSDIR}/x11/xcb-util

XORG_CAT=	app
USE_XORG=	x11 xrender xrandr xcb

PLIST_FILES=	bin/xbacklight man/man1/xbacklight.1.gz

.include <bsd.port.mk>
