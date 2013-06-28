# Created by: me
# $FreeBSD$

PORTNAME=	fvwm
PORTVERSION=	1.24r
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-1/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	The fvwm window manager

NO_LATEST_LINK=	yes
MAKE_JOBS_UNSAFE=	yes

USES=		imake
USE_XORG=	xbitmaps xpm xext x11 xmu
# must overwrite the default from bsd.port.mk
ALL_TARGET=	Makefiles all
MAN1=		FvwmAudio.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 FvwmClean.1 \
		FvwmDebug.1 FvwmIconBox.1 FvwmIdent.1 FvwmPager.1 FvwmSave.1 \
		FvwmSaveDesk.1 FvwmScroll.1 FvwmWinList.1 GoodStuff.1 fvwm.1 \
		xpmroot.1

pre-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/configure.h \
		${WRKSRC}/sample.fvwmrc/system.fvwmrc

post-install:
	@${MKDIR} ${PREFIX}/include/X11/pixmaps
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 444 \
	${WRKSRC}/fvwm_icons/*.xpm ${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
