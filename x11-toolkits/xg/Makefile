# New ports collection makefile for:	xg
# Date created:				3 December 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xg
PORTVERSION=	1.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://messners.com/code/ \
		http://www.messners.com/code/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Windows(tm) controls - like widget set for Motif(tm)

WRKSRC=		${WRKDIR}/Xg-${PORTVERSION}
USE_X_PREFIX=	yes
USE_MOTIF=	yes
MAKEFILE=	makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libxg.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/xg
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/xg
	@${MKDIR} ${PREFIX}/share/examples/xg
	${INSTALL_DATA} ${WRKSRC}/testsrc/*.c ${PREFIX}/share/examples/xg
	${INSTALL_DATA} ${WRKSRC}/testsrc/*.xpm ${PREFIX}/share/examples/xg
	${INSTALL_DATA} ${WRKSRC}/testsrc/makefile ${PREFIX}/share/examples/xg/Makefile
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xg
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/xg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xg
.endif

.include <bsd.port.mk>
