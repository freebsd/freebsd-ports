# New ports collection makefile for:	E-Weather 0.2
# Date created:		30 March 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	E-Weather
PORTVERSION=	0.4a
CATEGORIES=	x11
MASTER_SITES=	http://streiff.net/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Weather epplet for Enlightenment similar to wmWeather

RUN_DEPENDS=	GrabWeather:${PORTSDIR}/misc/wmweather
LIB_DEPENDS=	epplet.1:${PORTSDIR}/x11-wm/epplets

USE_GMAKE=	yes
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/E-Weather.epplet ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/E-Weather.icon \
	    ${PREFIX}/share/enlightenment/epplet_icons

.include <bsd.port.mk>
