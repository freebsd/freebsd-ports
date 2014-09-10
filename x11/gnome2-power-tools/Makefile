# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/gnome2-power-tools/Makefile,v 1.84 2008/09/30 13:18:29 kwm Exp $

PORTREVISION=	5
CATEGORIES=	x11 gnome
PKGNAMESUFFIX=	-power-tools

COMMENT=	The 'Geektoys' for the GNOME 2 power user

RUN_DEPENDS=	${LOCALBASE}/share/epiphany-extensions/adblock-patterns:${PORTSDIR}/www/epiphany-extensions \
		gnome-pkgview:${PORTSDIR}/sysutils/gnome-pkgview \
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
		gtweakui-menus:${PORTSDIR}/deskutils/gtweakui \
		brightside:${PORTSDIR}/x11/brightside \
		evolution-gconf-filter-exchange:${PORTSDIR}/devel/evolution-gconf-tools

MASTERDIR=	${.CURDIR}/../gnome2
GNOME_SLAVE=	yes

DESCR=		${.CURDIR}/pkg-descr
.include "${MASTERDIR}/Makefile"
