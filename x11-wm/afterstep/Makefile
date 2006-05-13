# New ports collection makefile for:	afterstep
# Date created:		October 29th 1996
# Whom:			jfitz@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	afterstep
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-wm afterstep
MASTER_SITES=	${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	archives/${PORTVERSION}
DISTNAME=	AfterStep-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Window manager originally based on the Bowman NeXTstep clone

RUN_DEPENDS=	asclock:${PORTSDIR}/x11-clocks/asclock

NO_LATEST_LINK=	yes
USE_XPM=	yes
USE_IMAKE=	yes
INSTALL_TARGET=	install install.man
MANCOMPRESSED=	yes
MAN1=		afterstep.1 Animate.1 Audio.1 Auto.1 Banner.1 Pager.1 Wharf.1
CONFLICTS?=	afterstep-2*

SRCDIRS=	afterstep \
		modules/Animate modules/Audio modules/Auto \
		modules/Banner modules/Pager modules/Wharf \
		modules/Wharf/ASSound

post-patch:
		${REINPLACE_CMD} \
			-e 's|%%PREFIX%%|${PREFIX}|g' \
			${WRKSRC}/configure.h \
			${WRKSRC}/sample.steprc
		@ for i in ${SRCDIRS}; do \
			cd ${WRKSRC}/$$i; \
			${MV} Imakefile Imakefile.orig; \
			${SED} -e 's/#ifdef AlphaArchitecture/#if defined(AlphaArchitecture) \&\& !defined(FreeBSDArchitecture)/' < Imakefile.orig  >  Imakefile; \
		done

pre-build:
		@ cd ${WRKSRC}; ${SH} MakeMakefiles

post-install:
		@ ${MKDIR} ${PREFIX}/lib/X11/afterstep/backgrounds/
		${INSTALL_DATA} ${WRKSRC}/backgrounds/* ${PREFIX}/lib/X11/afterstep/backgrounds/
		@ ${MKDIR} ${PREFIX}/lib/X11/afterstep/sounds/
		${INSTALL_DATA} ${WRKSRC}/sounds/* ${PREFIX}/lib/X11/afterstep/sounds/
		@ ${MKDIR} ${PREFIX}/include/X11/pixmaps/
.if defined(WITH_HICOLOR_ICONS)
		${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/include/X11/pixmaps/
		${INSTALL_DATA} ${FILESDIR}/monitor_bsd.xpm ${PREFIX}/include/X11/pixmaps/
.else
.if !defined(BATCH)
		@${ECHO_MSG} "===>  Note: to use the hi-color icons,"
		@${ECHO_MSG} "      reinstall this port with -DWITH_HICOLOR_ICONS"
		@${ECHO_MSG} "      defined"
.endif
		@for i in AFstep.xpm penguin.xpm monitor_bsd.xpm; do \
			${CP} ${FILESDIR}/$$i ${WRKSRC}/icons/8bit/; \
		done
		${INSTALL_DATA} ${WRKSRC}/icons/8bit/*.xpm ${PREFIX}/include/X11/pixmaps/
		${INSTALL_DATA} ${WRKSRC}/icons/eyecon.xpm ${PREFIX}/include/X11/pixmaps/
.endif
		@ ${MKDIR} ${PREFIX}/lib/X11/afterstep/doc/
		@for i in CHANGES CREDITS README README.8bit INSTALL FAQ module-interface.txt; do \
			${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/lib/X11/afterstep/doc/; \
		done

.include <bsd.port.mk>
