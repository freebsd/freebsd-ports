# New ports collection makefile for:	afterstep
# Version required:	0.98b33
# Date created:		17 July 96
# Whom:			james@bdd.net
#
# $Id: Makefile,v 1.10 1996/09/30 20:29:12 jfitz Exp $
#

DISTNAME=	as-b33
PKGNAME=	afterstep-0.98b33
CATEGORIES+=	x11
MASTER_SITES=	ftp://oak.sfasu.edu/pub/AfterStep/

MAINTAINER=	jfitz@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
WRKSRC=		${WRKDIR}/AfterStep-0.98aBETA33

pre-build:
		@ cd ${WRKSRC}; sh MakeMakefiles

post-install:	
		@ ${MKDIR} -p ${PREFIX}/lib/X11/afterstep/backgrounds/
		${INSTALL_DATA} ${WRKSRC}/backgrounds/* ${PREFIX}/lib/X11/afterstep/backgrounds/
		@ ${MKDIR} -p ${PREFIX}/lib/X11/afterstep/sounds/
		${INSTALL_DATA} ${WRKSRC}/sounds/* ${PREFIX}/lib/X11/afterstep/sounds/
		@ ${MKDIR} -p ${PREFIX}/include/X11/pixmaps/
		${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps/
		${INSTALL_DATA} ${WRKSRC}/icons/8bit/*.xpm ${PREFIX}/include/X11/pixmaps/
		@ ${MKDIR} -p ${PREFIX}/lib/X11/afterstep/doc/
		@for file in CHANGES README README.8bit README.gradient afterstep.faq; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/X11/afterstep/doc/; \
		done

.include <bsd.port.mk>
