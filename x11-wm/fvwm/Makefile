# Created by: me
# $FreeBSD$

PORTNAME=	fvwm
PORTVERSION=	1.24r
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-1/
PKGNAMESUFFIX=	1${PKGNAMESUFFIX2}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fvwm window manager

CONFLICTS=	fvwm-2.*

USES=		imake
USE_XORG=	xbitmaps xpm xext x11 xmu

pre-configure:
	${REINPLACE_CMD} -e '/DependSubdirs/y,/*#,   ,' ${WRKSRC}/Imakefile
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/configure.h \
		${WRKSRC}/sample.fvwmrc/system.fvwmrc

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/X11/pixmaps
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xpm \
		${STAGEDIR}${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
