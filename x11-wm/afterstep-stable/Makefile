# New ports collection makefile for:	afterstep
# Version required:	0.98b27
# Date created:		17 July 96
# Whom:			james@bdd.net
#
# $Id: Makefile,v 1.6 1996/08/20 10:57:38 jfitz Exp $
#

DISTNAME=	as-b27
PKGNAME=	afterstep-0.98b27
CATEGORIES+=	x11
MASTER_SITES=	ftp://oak.sfasu.edu/pub/AfterStep/

MAINTAINER=	jfitz@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	fvwm:${PORTSDIR}/x11/fvwm

USE_X11=	yes
WRKSRC=		${WRKDIR}/AfterStep-0.98aBETA27

pre-build:
		@cd ${WRKSRC}; sh MakeMakefiles

post-install:	
		@mkdir -p ${PREFIX}/include/X11/pixmaps
		@cp ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps
		@cp ${WRKSRC}/icons/8bit/*.xpm ${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
