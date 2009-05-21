# New ports collection makefile for:	gnome2-fifth-toe
# Date created:				20 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome2-fifth-toe/Makefile,v 1.92 2007/10/18 23:45:20 marcus Exp $
#

PORTREVISION=	0
CATEGORIES=	x11 gnome
PKGNAMESUFFIX=	-fifth-toe

COMMENT=	Additional GNOME 2 applications not included in the core desktop

RUN_DEPENDS=	pan:${PORTSDIR}/news/pan \
		xchat:${PORTSDIR}/irc/xchat \
		gimp>0:${PORTSDIR}/graphics/gimp \
		sodipodi:${PORTSDIR}/graphics/sodipodi \
		gnomeicu:${PORTSDIR}/net-im/gnomeicu \
		gthumb:${PORTSDIR}/graphics/gthumb \
		pidgin:${PORTSDIR}/net-im/pidgin \
		tsclient:${PORTSDIR}/net/tsclient \
		galeon:${PORTSDIR}/www/galeon \
		${LOCALBASE}/share/icons/Foxtrot/index.theme:${PORTSDIR}/x11-themes/gnome-themes-extras \
		bluefish:${PORTSDIR}/www/bluefish \
		gossip:${PORTSDIR}/net-im/gossip \
		liferea:${PORTSDIR}/net/liferea \
		rhythmbox:${PORTSDIR}/audio/rhythmbox \
		${LOCALBASE}/share/gnome-games/glines/pixmaps/classic.png:${PORTSDIR}/games/gnome-games-extra-data \
		nautilus-sendto:${PORTSDIR}/deskutils/nautilus-sendto \
		inkscape:${PORTSDIR}/graphics/inkscape \
		atomix:${PORTSDIR}/games/atomix \
		straw:${PORTSDIR}/net/straw \
		${LOCALBASE}/share/gnome/help/gdp-handbook/C/builddocs.xml:${PORTSDIR}/misc/gnome-devel-docs

MASTERDIR=	${.CURDIR}/../gnome2
GNOME_SLAVE=	yes

DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
