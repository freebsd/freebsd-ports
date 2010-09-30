# New ports collection makefile for:	lxde-meta
# Date created:		07.02.2009
# Whom:			Daniel Walter <sahne@0x90.at>
#
# $FreeBSD$
#

PORTNAME=	lxde-meta
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	#none
DISTFILES=	#none

MAINTAINER=	kmoore@freebsd.org
COMMENT=	The "meta-port" of the LXDE desktop slimmed down for FreeBSD releases

RUN_DEPENDS=	openbox:${PORTSDIR}/x11-wm/openbox \
		lxsession:${PORTSDIR}/x11-wm/lxsession \
		lxpanel:${PORTSDIR}/x11/lxpanel \
		lxinput:${PORTSDIR}/sysutils/lxinput \
		lxtask:${PORTSDIR}/sysutils/lxtask \
		lxterminal:${PORTSDIR}/sysutils/lxterminal \
		pcmanfm:${PORTSDIR}/x11-fm/pcmanfm \
		gpicview:${PORTSDIR}/graphics/gpicview \
		lxde-icon-theme>=0:${PORTSDIR}/x11-themes/lxde-icon-theme \
		lxde-common>=0:${PORTSDIR}/misc/lxde-common

DESCR=		${.CURDIR}/pkg-descr

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

do-install:

.include <bsd.port.mk>
