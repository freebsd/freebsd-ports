# New ports collection makefile for:	Fvwm2
# Version required:	2.2
# Date created:		20 Jan 1996
# Whom:			peter
#
# $Id: Makefile,v 1.15 1998/09/17 00:32:57 asami Exp $
#

DISTNAME=	fvwm-2.2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/

MAINTAINER=	jcwells@u.washington.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		FvwmAnimate.1 FvwmAudio.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 \
		FvwmButtons.1 FvwmCpp.1 FvwmEvent.1 FvwmForm.1 FvwmIconBox.1 \
		FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 FvwmRearrange.1 \
		FvwmSave.1 FvwmSaveDesk.1 FvwmScroll.1 FvwmTalk.1 \
		FvwmWinList.1 fvwm2.1 xpmroot.1

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${WRKSRC}/icons/*.xbm \
			${WRKSRC}/icons/*.bitmap ${WRKSRC}/icons/*.icon \
		${PREFIX}/lib/X11/fvwm2/pixmaps
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
