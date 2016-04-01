# Created by: Jeroen Schot <schot@a-eskwadraat.nl>
# $FreeBSD$

PORTNAME=	dmenu
PORTVERSION=	4.6
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/ \
		http://schot.a-eskwadraat.nl/files/

PATCH_SITES=	http://tools.suckless.org/dmenu/patches/ \
		http://schot.a-eskwadraat.nl/files/
PATCH_DIST_STRIP=-p1

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	X11 menu application designed for the dwm window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

OPTIONS_DEFINE=	XINERAMA
OPTIONS_DEFAULT=	XINERAMA

USE_XORG=	x11 xft
MAKE_ARGS=	CC="${CC}" PREFIX="${PREFIX}" MANPREFIX="${MANPREFIX}/man" \
		X11INC="${LOCALBASE}/include" X11LIB="${LOCALBASE}/lib"

PLIST_FILES=	bin/dmenu bin/dmenu_path bin/dmenu_run bin/stest \
		man/man1/dmenu.1.gz man/man1/stest.1.gz

XINERAMA_USE=	XORG=xinerama
XINERAMA_MAKE_ARGS_OFF=	XINERAMAFLAGS= XINERAMALIBS=

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dmenu \
		${STAGEDIR}${PREFIX}/bin/stest

.include <bsd.port.mk>
