# New ports collection makefile for:	gnome2-fifth-toe
# Date created:				20 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-fifth-toe
PORTVERSION=	2.8.2
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional GNOME 2 applications not included in the core desktop

RUN_DEPENDS=	pan:${PORTSDIR}/news/pan2 \
		xchat:${PORTSDIR}/irc/xchat2 \
		gimp-2.0:${PORTSDIR}/graphics/gimp \
		sodipodi:${PORTSDIR}/graphics/sodipodi \
		gnomeicu:${PORTSDIR}/net/gnomeicu2 \
		gthumb:${PORTSDIR}/graphics/gthumb2 \
		${X11BASE}/lib/gaim/docklet.so:${PORTSDIR}/net/gaim \
		tsclient:${PORTSDIR}/net/tsclient \
		galeon:${PORTSDIR}/www/galeon \
		seahorse:${PORTSDIR}/security/seahorse \
		${X11BASE}/lib/gtk-2.0/2.4.0/engines/libindustrial.so:${PORTSDIR}/x11-themes/gnome-themes-extras \
		bluefish:${PORTSDIR}/www/bluefish-devel \
		gossip:${PORTSDIR}/net/gossip \
		inkscape:${PORTSDIR}/graphics/inkscape \
		straw:${PORTSDIR}/net/straw \
		liferea:${PORTSDIR}/net/liferea \
		gnotime:${PORTSDIR}/deskutils/gnotime \
		sound-juicer:${PORTSDIR}/audio/sound-juicer \
		rhythmbox:${PORTSDIR}/audio/rhythmbox \
		jamboree:${PORTSDIR}/audio/jamboree \
		${X11BASE}/share/gnome/pixmaps/glines/classic.png:${PORTSDIR}/games/gnomegames2-extra-data

.if !defined(PACKAGE_BUILDING) && !defined(PARALLEL_PACKAGE_BUILD)
RUN_DEPENDS+=	totem:${PORTSDIR}/multimedia/totem
.endif

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
