# Ports collection Makefile for:        gbackground
# Date created:                         05/06/2000
# Whom:                                 smoberly@xavier.dyndns.org
#
# $FreeBSD$
#

PORTNAME=	gbackground
PORTVERSION=	1.0.0.b2
CATEGORIES=	x11 gnome
MASTER_SITES=	http://ringer.cs.utsa.edu/~gsalinas/gBackGround/
DISTNAME=	gBackGround-1.0.0-beta2

MAINTAINER=	smoberly@xavier.dyndns.org

LIB_DEPENDS=	panel_applet.4:${PORTSDIR}/x11/gnomecore \
		gnome.4:${PORTSDIR}/x11/gnomelibs

ALL_TARGET=	gBackGround_applet
USE_X_PREFIX=	YES
USE_AUTOCONF=	YES
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.mk>
