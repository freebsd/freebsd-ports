# New ports collection makefile for:	afterstep
# Version required:	0.98b23a
# Date created:		17 July 96
# Whom:			james@bdd.net
#
# $Id: Makefile,v 1.5 1996/08/17 05:06:16 jfitz Exp $
#

DISTNAME=	as-b24a
PKGNAME=	afterstep-0.98b24a
CATEGORIES+=	x11
MASTER_SITES=	ftp://oak.sfasu.edu/pub/AfterStep/

MAINTAINER=	jfitz@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	fvwm:${PORTSDIR}/x11/fvwm

USE_X11=	yes
WRKSRC=		${WRKDIR}/AfterStep-0.98aBETA24a

pre-build:
		@cd ${WRKSRC}; sh MakeMakefiles

post-install:	
		@mkdir -p ${PREFIX}/include/X11/pixmaps
		@cp ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps
		@cp ${WRKSRC}/icons/8bit/*.xpm ${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
