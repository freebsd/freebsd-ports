# Ports collection Makefile for:        gbackground
# Date created:                         05/06/2000
# Whom:                                 smoberly@xavier.dyndns.org
#
# $FreeBSD$
#

PORTNAME=	gbackground
PORTVERSION=	1.0.0.b2
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://gBackGround.sourceforge.net/
DISTNAME=	gBackGround-1.0.0-beta2

MAINTAINER=	ports@FreeBSD.org

USE_GNOME=	gnomelibs libpanel
USE_GNOMENG=	yes
ALL_TARGET=	gBackGround_applet
USE_X_PREFIX=	YES
USE_AUTOCONF=	YES
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.mk>
