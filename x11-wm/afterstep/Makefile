# New ports collection makefile for:	afterstep
# Version required:	0.98b30
# Date created:		17 July 96
# Whom:			james@bdd.net
#
# $Id: Makefile,v 1.7 1996/08/24 15:19:15 jfitz Exp $
#

DISTNAME=	as-b30
PKGNAME=	afterstep-0.98b30
CATEGORIES+=	x11
MASTER_SITES=	ftp://oak.sfasu.edu/pub/AfterStep/

MAINTAINER=	jfitz@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	fvwm:${PORTSDIR}/x11/fvwm

USE_X11=	yes
WRKSRC=		${WRKDIR}/AfterStep-0.98aBETA30

pre-build:
		@cd ${WRKSRC}; sh MakeMakefiles

post-install:	
		@mkdir -p ${PREFIX}/lib/X11/afterstep/backgrounds/
		${INSTALL_DATA} ${WRKSRC}/backgrounds/* ${PREFIX}/lib/X11/afterstep/backgrounds/
		@mkdir -p ${PREFIX}/lib/X11/afterstep/sounds/
		${INSTALL_DATA} ${WRKSRC}/sounds/* ${PREFIX}/lib/X11/afterstep/sounds/
		${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps/
		${INSTALL_DATA} ${WRKSRC}/icons/8bit/*.xpm ${PREFIX}/include/X11/pixmaps/
		@mkdir -p ${PREFIX}/lib/X11/afterstep/doc/
		for file in CHANGES README README.8bit README.gradient mini-faq; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/X11/afterstep/doc/; \
		done

.include <bsd.port.mk>
