# New ports collection makefile for:	xcalib
# Date created:				5 April 2005
# Whom:					Petr Holub <hopet@ics.muni.cz>
#
# $FreeBSD$
#

PORTNAME=	xcalib
PORTVERSION=	0.5
CATEGORIES=	x11 graphics
MASTER_SITES=	http://www.etg.e-technik.uni-erlangen.de/web/doe/xcalib/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	hopet@ics.muni.cz
COMMENT=	A program for display calibration of X11-Servers with ICC profiles

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_X_PREFIX=	yes
USE_GMAKE=	yes
ALL_TARGET=	icclib_xcalib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcalib ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.icc ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in README README.profilers
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
