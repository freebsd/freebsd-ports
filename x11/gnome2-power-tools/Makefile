# New ports collection makefile for:	gnome2-power-tools
# Date created:				18 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-power-tools
PORTVERSION=	2.6.0
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"Geektoys" for the GNOME 2 power user

RUN_DEPENDS=	${X11BASE}/lib/epiphany/extensions/libgesturesextension.so:${PORTSDIR}/www/epiphany-extensions \
		gnome-pkgview:${PORTSDIR}/sysutils/gnome-pkgview \
		${X11BASE}/libexec/quick-lounge-applet:${PORTSDIR}/misc/quick-lounge-applet \
		${X11BASE}/libexec/netspeed_applet2:${PORTSDIR}/net/netspeed_applet \
		${LOCALBASE}/sbin/gkrellmd:${PORTSDIR}/sysutils/gkrellm2 \
		splashsetter:${PORTSDIR}/deskutils/splashsetter \
		gnome-netinfo:${PORTSDIR}/net/gnomenetwork \
		gdesklets:${PORTSDIR}/deskutils/gdesklets

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
