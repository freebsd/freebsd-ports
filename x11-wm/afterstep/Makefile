# New ports collection makefile for:	afterstep
# Version required:	1.0
# Date created:		October 29th 1996
# Whom:			jfitz@FreeBSD.ORG
#
# $Id: Makefile,v 1.26 1999/01/17 03:03:38 billf Exp $
#

DISTNAME=	AfterStep-1.0
PKGNAME=	afterstep-1.0
CATEGORIES=	x11-wm afterstep
MASTER_SITES=	ftp://ftp.afterstep.org/stable/archives/ \
		ftp://ftp.digex.net/pub/os/wm/AfterStep/stable/archives/ \
		ftp://ftp.alpha1.net/pub/mirrors/ftp.afterstep.org/stable/archives/ \
		ftp://ftp.starshadow.com/pub/afterstep/stable/archives/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/afterstep/

MAINTAINER=	jfitz@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

NO_LATEST_LINK= yes
USE_X_PREFIX=	yes
INSTALL_TARGET=	install install.man
MANCOMPRESSED=	yes
MAN1=		afterstep.1 asclock.1 Animate.1 Audio.1 Auto.1 Banner.1 Pager.1 Wharf.1

SRCDIRS=	afterstep \
		modules/Animate modules/Audio modules/Auto \
		modules/Banner modules/Pager modules/Wharf \
		modules/Wharf/ASSound

post-patch:
		@ for i in ${SRCDIRS}; do \
			cd ${WRKSRC}/$$i; \
			${MV} Imakefile Imakefile.orig; \
			${SED} -e 's/#ifdef AlphaArchitecture/#if defined(AlphaArchitecture) \&\& !defined(FreeBSDArchitecture)/' < Imakefile.orig  >  Imakefile; \
		done

pre-build:
		@ cd ${WRKSRC}; sh MakeMakefiles

post-install:
		@ ${MKDIR} ${PREFIX}/lib/X11/afterstep/backgrounds/
		${INSTALL_DATA} ${WRKSRC}/backgrounds/* ${PREFIX}/lib/X11/afterstep/backgrounds/
		@ ${MKDIR} ${PREFIX}/lib/X11/afterstep/sounds/
		${INSTALL_DATA} ${WRKSRC}/sounds/* ${PREFIX}/lib/X11/afterstep/sounds/
		@ ${MKDIR} ${PREFIX}/include/X11/pixmaps/
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
		@ ${MKDIR} ${PREFIX}/lib/X11/afterstep/doc/
		@for file in CHANGES CREDITS README README.8bit INSTALL FAQ module-interface.txt; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/lib/X11/afterstep/doc/; \
		done

.include <bsd.port.mk>
