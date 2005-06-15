# New ports collection makefile for:	fvwm
# Date created:		12 May 1995
# Whom:			me
#
# $FreeBSD$
#

PORTNAME=	fvwm
PORTVERSION=	1.24r
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.hpc.uh.edu/pub/fvwm/version-1/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/1.x/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	The fvwm window manager

NO_LATEST_LINK=	yes
USE_IMAKE=	yes
USE_XPM=	yes
# must overwrite the default from bsd.port.mk
XMKMF=		xmkmf
ALL_TARGET=	Makefiles all
MAN1=		FvwmAudio.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 FvwmClean.1 \
		FvwmDebug.1 FvwmIconBox.1 FvwmIdent.1 FvwmPager.1 FvwmSave.1 \
		FvwmSaveDesk.1 FvwmScroll.1 FvwmWinList.1 GoodStuff.1 fvwm.1 \
		xpmroot.1

post-install:
	@${MKDIR} ${PREFIX}/include/X11/pixmaps
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 444 \
	${WRKSRC}/fvwm_icons/*.xpm ${PREFIX}/include/X11/pixmaps

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-4
PLIST_SUB+=	NEWMTREE=""
.else
PLIST_SUB+=	NEWMTREE="@comment "
.endif

.include <bsd.port.post.mk>
