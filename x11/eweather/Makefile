# New ports collection makefile for:	E-Weather 0.2
# Date created:		30 March 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	E-Weather
PORTVERSION=	0.4b
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://streiff.net/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Weather epplet for Enlightenment similar to wmWeather

LIB_DEPENDS=	epplet.1:${PORTSDIR}/x11-wm/libepplet
RUN_DEPENDS=	GrabWeather:${PORTSDIR}/misc/wmweather

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="-L${X11BASE}/lib -lepplet ${PTHREAD_LIBS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/E-Weather.epplet ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/enlightenment/epplet_icons
	${INSTALL_DATA} ${WRKSRC}/E-Weather.icon \
		${PREFIX}/share/enlightenment/epplet_icons

.include <bsd.port.mk>
