# New ports collection makefile for:	gnome2-power-tools
# Date created:				18 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome2-power-tools/Makefile,v 1.84 2008/09/30 13:18:29 kwm Exp $
#

PORTREVISION=	1
CATEGORIES=	x11 gnome
PKGNAMESUFFIX=	-power-tools

COMMENT=	The 'Geektoys' for the GNOME 2 power user

RUN_DEPENDS=	${LOCALBASE}/share/epiphany-extensions/adblock-patterns:${PORTSDIR}/www/epiphany-extensions \
		gnome-pkgview:${PORTSDIR}/sysutils/gnome-pkgview \
		${LOCALBASE}/libexec/netspeed_applet2:${PORTSDIR}/net/netspeed_applet \
		${LOCALBASE}/sbin/gkrellmd:${PORTSDIR}/sysutils/gkrellm2 \
		splashsetter:${PORTSDIR}/deskutils/splashsetter \
		gdesklets:${PORTSDIR}/deskutils/gdesklets \
		cog:${PORTSDIR}/sysutils/cog \
		gnome-blog-poster:${PORTSDIR}/deskutils/gnome-blog \
		gnomesu:${PORTSDIR}/security/libgnomesu \
		bpm:${PORTSDIR}/ports-mgmt/bpm \
		gnome-file-share-properties:${PORTSDIR}/www/gnome-user-share \
		serpentine:${PORTSDIR}/sysutils/serpentine \
		devilspie:${PORTSDIR}/x11-wm/devilspie \
		${LOCALBASE}/lib/nautilus/extensions-2.0/libnautilus-open-terminal.so:${PORTSDIR}/deskutils/nautilus-open-terminal \
		gtweakui-menus:${PORTSDIR}/deskutils/gtweakui \
		gnome-art:${PORTSDIR}/x11-themes/gnome-art \
		brightside:${PORTSDIR}/x11/brightside \
		evolution-gconf-filter-exchange:${PORTSDIR}/devel/evolution-gconf-tools \
		${LOCALBASE}/libexec/quick-lounge-applet:${PORTSDIR}/misc/quick-lounge-applet \
		eiciel:${PORTSDIR}/sysutils/eiciel \
		gtk-send-pr:${PORTSDIR}/sysutils/gtk-send-pr \
		thefish:${PORTSDIR}/sysutils/thefish

MASTERDIR=	${.CURDIR}/../gnome2
GNOME_SLAVE=	yes

DESCR=		${.CURDIR}/pkg-descr
.include "${MASTERDIR}/Makefile"
