# New ports collection makefile for:	Fvwm2
# Date created:		20 Jan 1996
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	fvwm
PORTVERSION=	2.2.4
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		http://www.fvwm.org/generated/icon_download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fvwm_icons.tgz

MAINTAINER=	jcwells@u.washington.edu

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-extras --prefix=${PREFIX}
USE_GMAKE=	yes

MAN1=	FvwmAnimate.1 FvwmAudio.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 \
	FvwmButtons.1 FvwmCommand.1 FvwmConfig.1 FvwmConsole.1 \
	FvwmCpp.1 FvwmDebug.1 FvwmEvent.1 FvwmForm.1 FvwmGoodStuff.1 \
	FvwmIconBox.1 FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 \
	FvwmRearrange.1 FvwmSave.1 FvwmSaveDesk.1 FvwmScript.1 FvwmScroll.1 \
	FvwmTalk.1 FvwmTaskBar.1 FvwmWharf.1 FvwmWinList.1 fvwm2.1 xpmroot.1 \
	FvwmConsoleC.pl.1

post-install:
	@${MKDIR} ${PREFIX}/icons
	${INSTALL_DATA} ${WRKDIR}/*.xpm ${PREFIX}/icons
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
