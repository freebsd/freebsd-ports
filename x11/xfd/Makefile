# $FreeBSD$

PORTNAME=	xfd
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Display all characters in an X font

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2
BUILD_DEPENDS=	fc-cache:x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:x11-fonts/fontconfig

XORG_CAT=	app
USE_XORG=	xft xt xaw

BROKEN_aarch64=		Fails to build: exec(xgettext) failed (No such file or directory)

.include <bsd.port.mk>
