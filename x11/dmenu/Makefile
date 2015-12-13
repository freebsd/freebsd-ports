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

LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS_DEFINE=	XINERAMA
OPTIONS_DEFAULT=	XINERAMA

USE_XORG=	x11 xft

PLIST_FILES=	bin/dmenu bin/dmenu_path bin/dmenu_run bin/stest \
		man/man1/dmenu.1.gz man/man1/stest.1.gz

XINERAMA_USE=	XORG=xinerama

post-patch:
	@${GREP} -Rl '%%[[:alpha:]]\+%%' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} \
	         -e "s,%%PREFIX%%,${PREFIX},g" \
	         -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
	         -e "s,%%MANPREFIX%%,${MANPREFIX},g"

post-patch-XINERAMA-off:
	@${REINPLACE_CMD} -e 's,$${XINERAMALIBS},,g' \
	         -e 's,$${XINERAMAFLAGS},,g' ${WRKSRC}/config.mk

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dmenu \
		${STAGEDIR}${PREFIX}/bin/stest

.include <bsd.port.mk>
