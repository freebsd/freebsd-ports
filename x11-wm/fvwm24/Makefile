# New ports collection makefile for:	Fvwm2
# Version required:	2.2.2
# Date created:		20 Jan 1996
# Whom:			peter
#
# $FreeBSD$
#

DISTNAME=	fvwm-2.2.2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/

MAINTAINER=	jcwells@u.washington.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	FvwmAudio.1 FvwmBacker.1 FvwmBanner.1 FvwmButtons.1 \
	FvwmCpp.1 FvwmEvent.1 FvwmForm.1 FvwmIconMan.1 \
	FvwmIdent.1 FvwmM4.1 FvwmPager.1 FvwmRearrange.1 \
	FvwmSave.1 FvwmSaveDesk.1 FvwmScroll.1 FvwmTalk.1 \
	fvwm2.1 xpmroot.1 FvwmAnimate.1 FvwmAuto.1 \
	FvwmIconBox.1 FvwmWinList.1

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${WRKSRC}/icons/*.xbm \
			${WRKSRC}/icons/*.bitmap ${WRKSRC}/icons/*.icon \
		${PREFIX}/lib/X11/fvwm2/pixmaps
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
