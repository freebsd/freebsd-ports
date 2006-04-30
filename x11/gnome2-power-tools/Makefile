# New ports collection makefile for:	gnome2-power-tools
# Date created:				18 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome2-power-tools/Makefile,v 1.69 2006/04/24 02:51:14 mezz Exp $
#

PORTREVISION=	0
CATEGORIES=	x11 gnome
PKGNAMESUFFIX=	-power-tools

COMMENT=	"Geektoys" for the GNOME 2 power user

RUN_DEPENDS=	${X11BASE}/lib/epiphany/2.14/extensions/libgesturesextension.so:${PORTSDIR}/www/epiphany-extensions \
		gnome-pkgview:${PORTSDIR}/sysutils/gnome-pkgview \
		${X11BASE}/libexec/netspeed_applet2:${PORTSDIR}/net/netspeed_applet \
		${LOCALBASE}/sbin/gkrellmd:${PORTSDIR}/sysutils/gkrellm2 \
		splashsetter:${PORTSDIR}/deskutils/splashsetter \
		gdesklets:${PORTSDIR}/deskutils/gdesklets \
		cog:${PORTSDIR}/sysutils/cog \
		gnome-blog-poster:${PORTSDIR}/deskutils/gnomeblog \
		gnomesu:${PORTSDIR}/security/libgnomesu \
		bpm:${PORTSDIR}/sysutils/bpm \
		gnome-file-share-properties:${PORTSDIR}/www/gnome-user-share \
		serpentine:${PORTSDIR}/sysutils/serpentine \
		devilspie:${PORTSDIR}/x11-wm/devilspie \
		${X11BASE}/lib/nautilus/extensions-1.0/libnautilus-open-terminal.so:${PORTSDIR}/deskutils/nautilus-open-terminal \
		gtweakui-menus:${PORTSDIR}/deskutils/gtweakui \
		gnome-art:${PORTSDIR}/x11-themes/gnome-art \
		brightside:${PORTSDIR}/x11/brightside \
		evolution-gconf-filter-exchange:${PORTSDIR}/devel/evolution-gconf-tools \
		${X11BASE}/libexec/quick-lounge-applet:${PORTSDIR}/misc/quick-lounge-applet \
		eiciel:${PORTSDIR}/sysutils/eiciel \
		gtk-send-pr:${PORTSDIR}/sysutils/gtk-send-pr \
		thefish:${PORTSDIR}/sysutils/thefish \
		bpm:${PORTSDIR}/sysutils/bpm \
		pbrowser:${PORTSDIR}/sysutils/portbrowser

MASTERDIR=	${.CURDIR}/../gnome2
GNOME_SLAVE=	yes

DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
