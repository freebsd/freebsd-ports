# Created by: Daniel Walter <sahne@0x90.at>
# $FreeBSD$

PORTNAME=	lxde-meta
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	#none
DISTFILES=	#none

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	"meta-port" of the LXDE desktop slimmed down for FreeBSD releases

RUN_DEPENDS=	openbox:${PORTSDIR}/x11-wm/openbox \
		obconf:${PORTSDIR}/x11-wm/obconf \
		lxsession:${PORTSDIR}/x11-wm/lxsession \
		lxpanel:${PORTSDIR}/x11/lxpanel \
		lxinput:${PORTSDIR}/sysutils/lxinput \
		lxtask:${PORTSDIR}/sysutils/lxtask \
		lxterminal:${PORTSDIR}/sysutils/lxterminal \
		lxshortcut:${PORTSDIR}/deskutils/lxshortcut \
		pcmanfm:${PORTSDIR}/x11-fm/pcmanfm \
		gpicview:${PORTSDIR}/graphics/gpicview \
		lxde-icon-theme>=0:${PORTSDIR}/x11-themes/lxde-icon-theme \
		lxde-common>=0:${PORTSDIR}/misc/lxde-common

DESCR=		${.CURDIR}/pkg-descr

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_MTREE=	yes

NO_STAGE=	yes
do-install:

.include <bsd.port.mk>
