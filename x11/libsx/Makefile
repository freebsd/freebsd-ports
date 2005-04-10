# New ports collection makefile for:	libsx
# Date created:			5 December 1996
# Whom:				Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	libsx
PORTVERSION=	1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	libraries
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple X11 library

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

USE_X_PREFIX=	yes
ALL_TARGET=	src freq

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libsx.a  ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/freq/libfreq.a  ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/X11/libsx
	${INSTALL_DATA} ${WRKSRC}/src/libsx.h ${PREFIX}/include/X11/libsx
	${INSTALL_DATA} ${WRKSRC}/freq/freq.h ${PREFIX}/include/X11/libsx

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/libsx
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/libsx
	${GZIP_CMD} ${PREFIX}/share/doc/libsx/*.doc
.endif

.include <bsd.port.mk>
