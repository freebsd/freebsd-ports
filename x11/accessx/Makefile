# New ports collection makefile for:	accessx
# Date created:				January 20 2001
# Whom:					Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	accessx
PORTVERSION=	0.950
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.rehab.uiuc.edu/accessx/software/
DISTNAME=	accessx${PORTVERSION:S/.//g}

MAINTAINER=	stephen@math.missouri.edu

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/accessx
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

pre-build:
	${REINPLACE_CMD} -e "s@g\+\+@${CXX} ${CXXFLAGS} -I${X11BASE}/include@g" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s@wish -f@wish8.2 -f@g" ${WRKSRC}/accessx

post-install:
	strip ${PREFIX}/bin/ax

.include <bsd.port.mk>
