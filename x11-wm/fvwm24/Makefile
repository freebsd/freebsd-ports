# New ports collection makefile for:	Internationalized fvwm2
# Version required:	2.0.46
# Date created:		20 Jan 1996
# Whom:			peter
#
# $Id: Makefile,v 1.12 1997/10/11 10:42:43 jkh Exp $
#

DISTNAME=	fvwm-2.0.46
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/fvwm-users-jp/kits/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/fvwm-users-jp/kits/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fvwm-users-jp-kits.97Oct04.tar.gz

MAINTAINER=	matusita@jp.freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
MAN1= 		FvwmAudio.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 \
		FvwmButtons.1 FvwmCascade.1 FvwmCpp.1 FvwmForm.1 \
		FvwmIconBox.1 FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 \
		FvwmSave.1 FvwmSaveDesk.1 FvwmScroll.1 FvwmTalk.1 FvwmTile.1 \
		FvwmWinList.1 fvwm2.1 xpmroot.1
MANCOMPRESSED=	yes

# filenames.
PATCH_FIXIT=	kits/patch/fix-2.0.46
PATCH_I18N=	kits/patch/PATCH.I18N
USE_PATCHFILES=	${PATCH_FIXIT} ${PATCH_I18N}

pre-patch:
	@for i in ${USE_PATCHFILES}; do \
		${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/$$i; \
	 done;

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${WRKSRC}/icons/*.xbm \
			${WRKSRC}/icons/*.bitmap ${WRKSRC}/icons/*.icon \
		${PREFIX}/lib/X11/fvwm2/pixmaps
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
