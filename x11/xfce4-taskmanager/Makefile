# New ports collection makefile for:	xfce4-taskbar-plugin
# Date created:		5 May 2005
# Whom:			DaJoob
#
# $FreeBSD$
#

PORTNAME=	xfce4-taskmanager
PORTVERSION=	0.2.1
CATEGORIES=	x11 xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/

MAINTAINER=	DaJoob@dajoob.com
COMMENT=	A task manager for XFCE

BUILD_DEPENDS=	xfwm4:${PORTSDIR}/x11-wm/xfce4-wm

USE_AUTOMAKE_VER=	19
USE_AUTOCONF_VER=	259

pre-configure:
	@cd ${WRKSRC} && ${PATCH} -pl < ${FILESDIR}/b4-conf.diff

.include <bsd.port.mk>
