# New ports collection makefile for:   libsx
# Version required:    1.1
# Date created:                5 December 1996
# Whom:                        pgiffuni@FPS.biblos.unal.edu.co
#
# $Id: Makefile,v 1.2 1997/01/13 11:32:25 obrien Exp $
#

DISTNAME=	libsx
PKGNAME=	libsx-1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	libraries
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pgiffuni@FPS.biblos.unal.edu.co

USE_X11=	yes
ALL_TARGET=	src

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libsx.a  ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/X11
	${INSTALL_DATA} ${WRKSRC}/src/libsx.h  ${PREFIX}/include/X11

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/libsx
	${INSTALL_MAN} ${WRKSRC}/docs/* ${PREFIX}/share/doc/libsx
	${GZIP_CMD} ${PREFIX}/share/doc/libsx/*.doc
.endif

.include <bsd.port.mk>
