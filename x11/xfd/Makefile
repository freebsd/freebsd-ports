# $FreeBSD$

PORTNAME=	xfd
PORTVERSION=	1.1.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Display all characters in an X font

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2
BUILD_DEPENDS=	fc-cache:x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:x11-fonts/fontconfig

XORG_CAT=	app
USE_XORG=	x11 xft xkbfile xmu xrender xt xaw

BROKEN_aarch64=		Fails to build: exec(xgettext) failed (No such file or directory)

.include <bsd.port.mk>
