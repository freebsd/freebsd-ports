# New ports collection makefile for:	accessx
# Date created:				January 20 2001
# Whom:					Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	accessx
PORTVERSION=	0.951
PORTREVISION=	5
CATEGORIES=	x11 accessibility
MASTER_SITES=	http://cmos-eng.rehab.uiuc.edu/accessx/software/
DISTNAME=	accessx${PORTVERSION:S/.//g}

MAINTAINER=	stephen@math.missouri.edu
COMMENT=	Customise accessibility features for X

USE_TK=		yes

USE_XORG=	xext
WRKSRC=		${WRKDIR}/accessx

PLIST_FILES=	bin/ax bin/accessx

post-patch:
	${REINPLACE_CMD} \
		-e "s@/usr/local@${PREFIX}@" \
		-e "s@/usr/X11R6/lib@${LOCALBASE}/lib@" \
		-e "s@g\+\+@${CXX} ${CXXFLAGS} -I${LOCALBASE}/include@g" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s@wish -f@${WISH} -f@g" ${WRKSRC}/accessx

post-install:
	${STRIP_CMD} ${PREFIX}/bin/ax

.include <bsd.port.mk>
