# New ports collection makefile for:   libsx
# Version required:    1.1
# Date created:                5 December 1996
# Whom:                        pgiffuni@FPS.biblos.unal.edu.co
#
# $Id$
#

DISTNAME=	libsx
PKGNAME=	libsx-1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	libraries

MAINTAINER=	pgiffuni@FPS.biblos.unal.edu.co

USE_X11=	yes
ALL_TARGET=	src

do-install:
	cp ${WRKSRC}/src/libsx.a  ${PREFIX}/lib
	mkdir -p ${PREFIX}/include/X11
	cp ${WRKSRC}/src/libsx.h  ${PREFIX}/include/X11

post-install:
.if !defined(NOPORTDOCS)
	mkdir -p ${PREFIX}/share/doc/libsx
	cp ${WRKSRC}/docs/* ${PREFIX}/share/doc/libsx
	gzip -9nf  ${PREFIX}/share/doc/libsx/*.doc
.endif

.include <bsd.port.mk>
