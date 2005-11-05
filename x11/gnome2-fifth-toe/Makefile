# New ports collection makefile for:	gnome2-fifth-toe
# Date created:				20 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome2-fifth-toe/Makefile,v 1.73 2005/08/26 03:21:23 marcus Exp $
#

PORTREVISION=	0
CATEGORIES=	x11 gnome
PKGNAMESUFFIX=	-fifth-toe

COMMENT=	Additional GNOME 2 applications not included in the core desktop

RUN_DEPENDS=	pan:${PORTSDIR}/news/pan2 \
		xchat:${PORTSDIR}/irc/xchat2 \
		gimp-2.2:${PORTSDIR}/graphics/gimp \
		sodipodi:${PORTSDIR}/graphics/sodipodi \
		gnomeicu:${PORTSDIR}/net/gnomeicu2 \
		gthumb:${PORTSDIR}/graphics/gthumb \
		${X11BASE}/lib/gaim/docklet.so:${PORTSDIR}/net/gaim \
		tsclient:${PORTSDIR}/net/tsclient \
		galeon:${PORTSDIR}/www/galeon \
		seahorse:${PORTSDIR}/security/seahorse \
		${X11BASE}/share/gnome/themes/Gorilla/metacity-1/metacity-theme-1.xml:${PORTSDIR}/x11-themes/gnome-themes-extras \
		bluefish:${PORTSDIR}/www/bluefish \
		gossip:${PORTSDIR}/net/gossip \
		straw:${PORTSDIR}/net/straw \
		liferea:${PORTSDIR}/net/liferea \
		gnotime:${PORTSDIR}/deskutils/gnotime \
		rhythmbox:${PORTSDIR}/audio/rhythmbox \
		jamboree:${PORTSDIR}/audio/jamboree \
		${X11BASE}/share/gnome/pixmaps/glines/classic.png:${PORTSDIR}/games/gnomegames2-extra-data \
		nautilus-sendto:${PORTSDIR}/deskutils/nautilus-sendto \
		goobox:${PORTSDIR}/audio/goobox \
		inkscape:${PORTSDIR}/graphics/inkscape \
		gpdf:${PORTSDIR}/graphics/gpdf \
		ggv:${PORTSDIR}/print/ggv

MASTERDIR=	${.CURDIR}/../gnome2
GNOME_SLAVE=	yes

DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
