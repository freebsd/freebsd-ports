# Created by: Jeroen Schot <schot@a-eskwadraat.nl>
# $FreeBSD$

PORTNAME=	dmenu
DISTVERSION=	4.9
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/ \
		http://schot.a-eskwadraat.nl/files/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	X11 menu application designed for the dwm window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

OPTIONS_DEFINE=	XINERAMA
OPTIONS_DEFAULT=	XINERAMA

USES=		xorg
USE_XORG=	x11 xft
MAKE_ARGS=	CC="${CC}" PREFIX="${PREFIX}" MANPREFIX="${MANPREFIX}/man" \
		X11INC="${LOCALBASE}/include" X11LIB="${LOCALBASE}/lib" \
		FREETYPEINC="${LOCALBASE}/include/freetype2"

PLIST_FILES=	bin/dmenu bin/dmenu_path bin/dmenu_run bin/stest \
		man/man1/dmenu.1.gz man/man1/stest.1.gz

XINERAMA_USE=	XORG=xinerama
XINERAMA_MAKE_ARGS_OFF=	XINERAMAFLAGS= XINERAMALIBS=

post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|(CFLAGS[[:space:]]*)= |\1+= |" \
		-e "s|(CPPFLAGS[[:space:]]*)= |\1+= |" \
		-e "s|(LDFLAGS[[:space:]]*)= |\1+= |" \
		${WRKSRC}/config.mk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dmenu \
		${STAGEDIR}${PREFIX}/bin/stest

.include <bsd.port.mk>
