# New ports collection makefile for:	afterstep
# Version required:	1.0
# Date created:		October 29th 1996
# Whom:			jfitz@FreeBSD.ORG
#
# $Id: Makefile,v 1.22 1998/09/17 00:32:56 asami Exp $
#

DISTNAME=	AfterStep-1.0
PKGNAME=	afterstep-1.0
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/X/afterstep/

MAINTAINER=	jfitz@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
INSTALL_TARGET=	install install.man
MANCOMPRESSED=	yes
MAN1=		afterstep.1 asclock.1 Animate.1 Audio.1 Auto.1 Banner.1 Pager.1 Wharf.1

pre-build:
		@ cd ${WRKSRC}; sh MakeMakefiles

post-install:	
		@ ${MKDIR} -p ${PREFIX}/lib/X11/afterstep/backgrounds/
		${INSTALL_DATA} ${WRKSRC}/backgrounds/* ${PREFIX}/lib/X11/afterstep/backgrounds/
		@ ${MKDIR} -p ${PREFIX}/lib/X11/afterstep/sounds/
		${INSTALL_DATA} ${WRKSRC}/sounds/* ${PREFIX}/lib/X11/afterstep/sounds/
		@ ${MKDIR} -p ${PREFIX}/include/X11/pixmaps/
.if defined(USE_HICOLOR_ICONS)
		${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps/
.else
.if !defined(BATCH)
		@echo "===>  Note: to use the hi-color icons,"
		@echo "      reinstall this port with -DUSE_HICOLOR_ICONS"
		@echo "      defined"
.endif
		@for file in AFstep.xpm penguin.xpm monitor_bsd.xpm; do \
			${CP} ${FILESDIR}/$$file ${WRKSRC}/icons/8bit; \
		done
		${INSTALL_DATA} ${WRKSRC}/icons/8bit/*.xpm ${PREFIX}/include/X11/pixmaps/
.endif
		@ ${MKDIR} -p ${PREFIX}/lib/X11/afterstep/doc/
		@for file in CHANGES CREDITS README README.8bit INSTALL FAQ module-interface.txt; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/X11/afterstep/doc/; \
		done

.include <bsd.port.mk>
