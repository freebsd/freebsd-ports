# New ports collection makefile for:	dmenu
# Date created:				August 4, 2006
# Whom:					Jeroen Schot <schot@a-eskwadraat.nl>
#
# $FreeBSD$
#

PORTNAME=	dmenu
PORTVERSION=	4.2.1
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/ \
		http://schot.a-eskwadraat.nl/files/

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	X11 menu application (not only) for the dwm window manager

USE_XORG=	x11 xinerama
USE_GMAKE=	yes

MAN1=		dmenu.1
PLIST_FILES=	bin/dmenu bin/dmenu_path bin/dmenu_run

pre-everything::
	@${ECHO_MSG} "You can build dmenu with your own config.h using the DMENU_CONF knob:"
	@${ECHO_MSG} "make DMENU_CONF=/path/to/dmenu/config.h install clean"

post-patch:
	@${GREP} -Rl '%%[[:alpha:]]\+%%' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} \
	         -e "s,%%PREFIX%%,${PREFIX},g" \
	         -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
	         -e "s,%%MANPREFIX%%,${MANPREFIX}/man,g"

.include <bsd.port.mk>
