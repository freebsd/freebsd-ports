# New ports collection makefile for:	accessx
# Date created:				January 20 2001
# Whom:					Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	accessx
PORTVERSION=	0.950
PORTREVISION=	1
CATEGORIES=	x11 accessibility
MASTER_SITES=	http://www.disability.uiuc.edu/accessx/software/
DISTNAME=	accessx${PORTVERSION:S/.//g}

MAINTAINER=	stephen@math.missouri.edu
COMMENT=	Customise accessibility features for X

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/accessx
USE_X_PREFIX=	yes

post-patch:
	${REINPLACE_CMD} \
		-e "s@/usr/local@${PREFIX}@" \
		-e "s@/usr/X11R6/lib@${X11BASE}/lib@" \
		-e "s@g\+\+@${CXX} ${CXXFLAGS} -I${X11BASE}/include@g" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s@wish -f@wish8.2 -f@g" ${WRKSRC}/accessx

post-install:
	${STRIP_CMD} ${PREFIX}/bin/ax

.include <bsd.port.mk>
