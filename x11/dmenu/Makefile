# Created by: Jeroen Schot <schot@a-eskwadraat.nl>
# $FreeBSD$

PORTNAME=	dmenu
PORTVERSION=	4.5
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

OPTIONS_DEFINE=	XINERAMA XFT
OPTIONS_DEFAULT=	XINERAMA

USE_XORG=	x11

MAN1=		dmenu.1 stest.1
PLIST_FILES=	bin/dmenu bin/dmenu_run bin/stest

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
.endif

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
PATCHFILES+=	${PORTNAME}-${PORTVERSION}-xft.diff
.endif

post-patch:
	@${GREP} -Rl '%%[[:alpha:]]\+%%' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} \
	         -e "s,%%PREFIX%%,${PREFIX},g" \
	         -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
	         -e "s,%%MANPREFIX%%,${MANPREFIX},g"
.if ! ${PORT_OPTIONS:MXINERAMA}
	@${REINPLACE_CMD} -e 's,$${XINERAMALIBS},,g' \
	         -e 's,$${XINERAMAFLAGS},,g' ${WRKSRC}/config.mk
.endif

.include <bsd.port.mk>
