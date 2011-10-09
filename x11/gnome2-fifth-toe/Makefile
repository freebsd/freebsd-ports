# New ports collection makefile for:	gnome2-fifth-toe
# Date created:				20 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome2-fifth-toe/Makefile,v 1.92 2007/10/18 23:45:20 marcus Exp $
#

PORTREVISION=	2
CATEGORIES=	x11 gnome
PKGNAMESUFFIX=	-fifth-toe

COMMENT=	Additional GNOME 2 applications not included in the core desktop

RUN_DEPENDS=	pan:${PORTSDIR}/news/pan \
		xchat:${PORTSDIR}/irc/xchat \
		gimp>0:${PORTSDIR}/graphics/gimp \
		sodipodi:${PORTSDIR}/graphics/sodipodi \
		gthumb:${PORTSDIR}/graphics/gthumb \
		pidgin:${PORTSDIR}/net-im/pidgin \
		tsclient:${PORTSDIR}/net/tsclient \
		${LOCALBASE}/share/icons/Foxtrot/index.theme:${PORTSDIR}/x11-themes/gnome-themes-extras \
		bluefish:${PORTSDIR}/www/bluefish \
		liferea:${PORTSDIR}/net/liferea \
		rhythmbox:${PORTSDIR}/audio/rhythmbox \
		${LOCALBASE}/share/gnome-games/glines/pixmaps/classic.png:${PORTSDIR}/games/gnome-games-extra-data \
		nautilus-sendto:${PORTSDIR}/deskutils/nautilus-sendto \
		inkscape:${PORTSDIR}/graphics/inkscape \
		atomix:${PORTSDIR}/games/atomix \
		${LOCALBASE}/share/gnome/help/gdp-handbook/C/builddocs.xml:${PORTSDIR}/misc/gnome-devel-docs

MASTERDIR=	${.CURDIR}/../gnome2
GNOME_SLAVE=	yes

DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
