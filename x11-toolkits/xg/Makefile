# New ports collection makefile for:	xg
# Version required:			1.0
# Date created:				3 December 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	xg
PKGNAME=	xg-1.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://messners.com/code/ \
		http://www.messners.com/code/

MAINTAINER=	andy@icc.surw.chel.su

REQUIRES_MOTIF=	yes
USE_X_PREFIX=	yes
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/Xg-1.0

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/src/libxg.a ${PREFIX}/lib
	@ ${MKDIR} ${PREFIX}/include/xg
	@ ${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/xg
	@ ${MKDIR} ${PREFIX}/share/examples/xg
	@ ${INSTALL_DATA} ${WRKSRC}/testsrc/* ${PREFIX}/share/examples/xg
	@ ${MV} ${PREFIX}/share/examples/xg/makefile ${PREFIX}/share/examples/xg/Makefile
	@ ${RM} ${PREFIX}/share/examples/xg/makefile.orig

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/xg
	@ ${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/xg
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xg
.endif

.include <bsd.port.mk>
