# Created by: Daniel Walter <sahne@0x90.at>
# $FreeBSD$

PORTNAME=	lxde-meta
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	x11

MAINTAINER=	horia@racoviceanu.com
COMMENT=	"meta-port" of the LXDE desktop slimmed down for FreeBSD releases

RUN_DEPENDS=	openbox:${PORTSDIR}/x11-wm/openbox \
		obconf:${PORTSDIR}/x11-wm/obconf \
		lxsession:${PORTSDIR}/x11-wm/lxsession \
		lxpanel:${PORTSDIR}/x11/lxpanel \
		lxinput:${PORTSDIR}/sysutils/lxinput \
		lxtask:${PORTSDIR}/sysutils/lxtask \
		lxterminal:${PORTSDIR}/sysutils/lxterminal \
		pcmanfm:${PORTSDIR}/x11-fm/pcmanfm \
		gpicview:${PORTSDIR}/graphics/gpicview \
		lxde-icon-theme>=0:${PORTSDIR}/x11-themes/lxde-icon-theme \
		lxde-common>=0:${PORTSDIR}/misc/lxde-common

USES=		metaport

.include <bsd.port.mk>
