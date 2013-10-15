# $FreeBSD$

PORTNAME=	xcursorgen
PORTVERSION=	1.0.5
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Create an X cursor file from a collection of PNG images

LICENSE=	MIT

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

XORG_CAT=	app
USE_XORG=	x11 xcursor xextproto

PLIST_FILES=	bin/xcursorgen man/man1/xcursorgen.1.gz
.include <bsd.port.mk>
