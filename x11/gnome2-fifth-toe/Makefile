# New ports collection makefile for:	gnome2-fifth-toe
# Date created:				20 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-fifth-toe
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for the GNOME 2 "Fifth-Toe" extra package set

RUN_DEPENDS=	gnumeric:${PORTSDIR}/math/gnumeric2 \
		AbiWord-2.0:${PORTSDIR}/editors/AbiWord2 \
		pan:${PORTSDIR}/news/pan2 \
		xchat:${PORTSDIR}/irc/xchat2 \
		balsa:${PORTSDIR}/mail/balsa2 \
		gimp-1.3:${PORTSDIR}/graphics/gimp-devel \
		sodipodi:${PORTSDIR}/graphics/sodipodi \
		gnomeicu:${PORTSDIR}/net/gnomeicu2 \
		gthumb:${PORTSDIR}/graphics/gthumb2 \
		mergeant:${PORTSDIR}/databases/mergeant \
		ghex2:${PORTSDIR}/editors/ghex2 \
		glade-2:${PORTSDIR}/devel/glade2 \
		gob2:${PORTSDIR}/devel/gob2 \
		gtetrinet:${PORTSDIR}/games/gtetrinet \
		${X11BASE}/lib/gaim/docklet.so:${PORTSDIR}/net/gaim \
		sawfish:${PORTSDIR}/x11-wm/sawfish2 \
		dia:${PORTSDIR}/graphics/dia \
		mrproject:${PORTSDIR}/deskutils/mrproject \
		tsclient:${PORTSDIR}/net/tsclient \
		regexxer:${PORTSDIR}/devel/regexxer \
		streamtuner:${PORTSDIR}/audio/streamtuner \
		meld:${PORTSDIR}/textproc/meld \
		gcompris:${PORTSDIR}/games/gcompris2 \
		galeon:${PORTSDIR}/www/galeon2 \
		gswitchit-properties-capplet:${PORTSDIR}/x11/gswitchit \
		seahorse:${PORTSDIR}/security/seahorse \
		workrave:${PORTSDIR}/x11/workrave \
		gnotime:${PORTSDIR}/deskutils/gnotime

.if !defined(PACKAGE_BUILDING) && !defined(PARALLEL_PACKAGE_BUILD)
RUN_DEPENDS+=	totem:${PORTSDIR}/multimedia/totem
.endif

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
