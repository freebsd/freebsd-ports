# New ports collection makefile for:	afterstep
# Version required:	1.0pre1
# Date created:		October 29th 1996
# Whom:			jfitz@FreeBSD.ORG
#
# $Id: Makefile,v 1.13 1996/11/18 11:42:39 asami Exp $
#

DISTNAME=	as-10pre1
PKGNAME=	afterstep-1.0pr1
CATEGORIES=	x11
MASTER_SITES=	ftp://oak.sfasu.edu/pub/AfterStep/

MAINTAINER=	jfitz@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
WRKSRC=		${WRKDIR}/AfterStep-1.0pre1
INSTALL_TARGET=	install install.man
MANCOMPRESSED=	yes
MAN1=		afterstep.1 asclock.1 Audio.1 Auto.1 Banner.1 Pager.1 Wharf.1

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
		@for file in CHANGES NEW README README.8bit afterstep.faq; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/X11/afterstep/doc/; \
		done

.include <bsd.port.mk>
