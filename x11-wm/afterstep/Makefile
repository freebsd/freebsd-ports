# Created by: jfitz@FreeBSD.org
# $FreeBSD$

PORTNAME=	afterstep
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	x11-wm afterstep
MASTER_SITES=	LOCAL/dinoex
PKGNAMESUFFIX=	1${PKGNAMESUFFIX2}
DISTNAME=	AfterStep-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Window manager originally based on the Bowman NeXTstep clone

LICENSE=	GPLv2+

RUN_DEPENDS=	asclock:x11-clocks/asclock

CONFLICTS?=	afterstep-2*
PORTSCOUT=	limit:^1\.[0-9.]*$$

USES=		imake xorg
USE_XORG=	xpm xext x11
USE_CSTD=	gnu89
INSTALL_TARGET=	install install.man
CFLAGS+=	-Wno-return-type

SRCDIRS=	afterstep \
		modules/Animate modules/Audio modules/Auto \
		modules/Banner modules/Pager modules/Wharf \
		modules/Wharf/ASSound

OPTIONS_DEFINE=	HICOLOR_ICONS
OPTIONS_DEFAULT=	HICOLOR_ICONS
HICOLOR_ICONS_DESC=	Use hi-color icons

.include <bsd.port.options.mk>

post-patch:
		${REINPLACE_CMD} \
			-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			-e 's|%%PREFIX%%|${PREFIX}|g' \
			${WRKSRC}/configure.h \
			${WRKSRC}/sample.steprc
		@ for i in ${SRCDIRS}; do \
			( cd ${WRKSRC}/$$i; \
			${MV} Imakefile Imakefile.orig; \
			${SED} -e 's/#ifdef AlphaArchitecture/#if defined(AlphaArchitecture) \&\& !defined(FreeBSDArchitecture)/' < Imakefile.orig  >  Imakefile; ) \
		done

pre-build:
		(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} MakeMakefiles)

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/afterstep/backgrounds/
		${INSTALL_DATA} ${WRKSRC}/backgrounds/* ${STAGEDIR}${PREFIX}/lib/X11/afterstep/backgrounds/
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/afterstep/sounds/
		${INSTALL_DATA} ${WRKSRC}/sounds/* ${STAGEDIR}${PREFIX}/lib/X11/afterstep/sounds/
		${MKDIR} ${STAGEDIR}${PREFIX}/include/X11/pixmaps/
.if ${PORT_OPTIONS:MHICOLOR_ICONS}
		${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${STAGEDIR}${PREFIX}/include/X11/pixmaps/
		${INSTALL_DATA} ${FILESDIR}/monitor_bsd.xpm ${STAGEDIR}${PREFIX}/include/X11/pixmaps/
.else
		@for i in AFstep.xpm penguin.xpm monitor_bsd.xpm; do \
			${CP} ${FILESDIR}/$$i ${WRKSRC}/icons/8bit/; \
		done
		${INSTALL_DATA} ${WRKSRC}/icons/8bit/*.xpm ${STAGEDIR}${PREFIX}/include/X11/pixmaps/
		${INSTALL_DATA} ${WRKSRC}/icons/eyecon.xpm ${STAGEDIR}${PREFIX}/include/X11/pixmaps/
.endif
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/afterstep/doc/
		@for i in CHANGES CREDITS README README.8bit INSTALL FAQ module-interface.txt; do \
			${INSTALL_DATA} ${WRKSRC}/$$i ${STAGEDIR}${PREFIX}/lib/X11/afterstep/doc/; \
		done

.include <bsd.port.mk>
