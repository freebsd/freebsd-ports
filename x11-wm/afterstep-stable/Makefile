# New ports collection makefile for:	afterstep
# Version required:	1.0pre1
# Date created:		October 29th 1996
# Whom:			jfitz@FreeBSD.ORG
#
# $Id: Makefile,v 1.12 1996/10/29 19:50:11 jfitz Exp $
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
.if defined(NOMANCOMPRESS)
		@ for file in afterstep asclock Audio Auto Banner Pager Wharf; do \
			gunzip ${PREFIX}/man/man1/$$file.1.gz; \
		done
.endif

.include <bsd.port.mk>
