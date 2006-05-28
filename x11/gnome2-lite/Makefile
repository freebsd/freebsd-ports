# New ports collection makefile for:	gnome2-lite
# Date created:		30 November 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome2-lite/Makefile,v 1.45 2005/11/17 23:20:32 marcus Exp $
#

PORTREVISION=	0
CATEGORIES=	x11 gnome
PKGNAMESUFFIX=	-lite

COMMENT=	The "meta-port" of the GNOME desktop slimmed down for FreeBSD releases

RUN_DEPENDS=	${X11BASE}/libexec/gweather-applet-2:${PORTSDIR}/x11/gnomeapplets2 \
		gnome-cd:${PORTSDIR}/audio/gnome-media \
	 	gnome-dictionary:${PORTSDIR}/deskutils/gnome-utils \
		eog:${PORTSDIR}/graphics/eog \
		gedit:${PORTSDIR}/editors/gedit \
		gnome-terminal:${PORTSDIR}/x11/gnometerminal \
		gnome-session:${PORTSDIR}/x11/gnomesession \
		gnome-system-monitor:${PORTSDIR}/sysutils/gnome-system-monitor \
		nautilus:${PORTSDIR}/x11-fm/nautilus2 \
		yelp:${PORTSDIR}/x11/yelp \
		${X11BASE}/share/gnome/help/user-guide/C/user-guide.xml:${PORTSDIR}/misc/gnome-user-docs \
		${X11BASE}/share/gnome/sounds/question.wav:${PORTSDIR}/audio/gnome-audio \
		file-roller:${PORTSDIR}/archivers/file-roller \
		${X11BASE}/share/themes/HighContrast/gtk-2.0/gtkrc:${PORTSDIR}/x11-themes/gnome-themes \
		evince:${PORTSDIR}/graphics/evince \
		gcalctool:${PORTSDIR}/math/gcalctool \
		gucharmap:${PORTSDIR}/deskutils/gucharmap \
		${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		gconf-editor:${PORTSDIR}/sysutils/gconf-editor \
		gnome-control-center:${PORTSDIR}/sysutils/gnome-control-center \
		totem:${PORTSDIR}/multimedia/totem-gstreamer

MASTERDIR=	${.CURDIR}/../gnome2
CONFLICTS=	gnome2-[0-9]*

DESCR=		${.CURDIR}/pkg-descr
PKGMESSAGE=	${.CURDIR}/pkg-message

.include "${MASTERDIR}/Makefile"
