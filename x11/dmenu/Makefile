# New ports collection makefile for:	dmenu
# Date created:				August 4, 2006
# Whom:					Jeroen Schot <schot@a-eskwadraat.nl>
#
# $FreeBSD$
#

PORTNAME=	dmenu
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://code.suckless.org/dl/tools/ \
		http://schot.a-eskwadraat.nl/files/
PATCH_SITES=	http://schot.a-eskwadraat.nl/files/

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	X11 menu application (not only) for the dwm window manager

OPTIONS=	XFT	"XFT support" Off

USE_XORG=	x11 xinerama

MAN1=		dmenu.1
PLIST_FILES=	bin/dmenu bin/dmenu_path bin/dmenu_run

.include <bsd.port.options.mk>

.if defined(WITH_XFT)
PATCHFILES+=	${PORTNAME}-${PORTVERSION}-xft.diff
PATCH_DIST_STRIP=	-p1
USE_XORG+=	xft
.endif

post-patch:
	@${GREP} -Rl '%%[[:alpha:]]\+%%' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} \
	         -e "s,%%PREFIX%%,${PREFIX},g" \
	         -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
	         -e "s,%%MANPREFIX%%,${MANPREFIX}/man,g"

.include <bsd.port.mk>
