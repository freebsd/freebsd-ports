# New ports collection makefile for:	gnome2-power-tools
# Date created:				18 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-power-tools
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"Geektoys" for the GNOME 2 power user

RUN_DEPENDS=	${X11BASE}/lib/gnome-vfs-2.0/modules/libsmb.so:${PORTSDIR}/devel/gnomevfs-extras \
		gnome-pkgview:${PORTSDIR}/sysutils/gnome-pkgview \
		${X11BASE}/lib/libquicklounge-applet.so:${PORTSDIR}/misc/quick-lounge-applet \
		gswitchit-plugins-capplet:${PORTSDIR}/x11/gswitchit \
		dasher:${PORTSDIR}/accessibility/dasher \
		${X11BASE}/libexec/netspeed_applet2:${PORTSDIR}/net/netspeed_applet \
		${X11BASE}/lib/gedit-2/plugins/libasciitable.so:${PORTSDIR}/editors/gedit-plugins \
		gdesklets:${PORTSDIR}/deskutils/gdesklets \
		${LOCALBASE}/sbin/gkrellmd:${PORTSDIR}/sysutils/gkrellm2 \
		${X11BASE}/libexec/gnome-netstatus-applet:${PORTSDIR}/net/gnomenetstatus \
		splashsetter:${PORTSDIR}/deskutils/splashsetter \
		gnome-netinfo:${PORTSDIR}/net/gnomenetwork

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
