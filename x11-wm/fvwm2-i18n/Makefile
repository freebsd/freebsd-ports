# New ports collection makefile for:	Internationalized fvwm2
# Date created:		20 Jan 1996
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	fvwm2-i18n
PORTVERSION=	2.2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/
DISTNAME=	fvwm-${PORTVERSION}

PATCH_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/fvwm-users-jp/I18N_MB/
PATCHFILES=	fvwm-${PORTVERSION}-I18N_MB-${FVWM_PATCHVER}.patch

MAINTAINER=	matusita@FreeBSD.org

.if !defined(WITHOUT_XPM)
USE_XPM=	yes
.endif

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAN1=		fvwm2.1 xpmroot.1 FvwmAnimate.1 FvwmAudio.1 FvwmAuto.1 \
		FvwmBacker.1 FvwmBanner.1 FvwmButtons.1 FvwmCommand.1 \
		FvwmConfig.1 FvwmConsole.1 FvwmConsoleC.pl.1 FvwmCpp.1 \
		FvwmDebug.1 FvwmEvent.1 FvwmForm.1 FvwmGoodStuff.1 \
		FvwmIconBox.1 FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 \
		FvwmPager.1 FvwmRearrange.1 FvwmSave.1 FvwmSaveDesk.1 \
		FvwmScript.1 FvwmScroll.1 FvwmTalk.1 FvwmTaskBar.1 \
		FvwmWharf.1 FvwmWinList.1
MANCOMPRESSED=	no

FVWM_PATCHVER=	1999042001
FVWM_DIR=	lib/X11/fvwm2
RC_FILES=	decor_examples new-features system.fvwm2rc \
		system.fvwm2rc-sample-1 system.fvwm2rc-sample-2

PLIST_SUB=	FVWM_DISTVER=${PORTVERSION} FVWM_DIR=${FVWM_DIR}

CONFIGURE_ARGS+= --enable-extras --enable-kanji
CONFIGURE_ARGS+= --sysconfdir=${PREFIX}/${FVWM_DIR}/${PORTVERSION}
CONFIGURE_ARGS+= --with-iconpath=${PREFIX}/${FVWM_DIR}/pixmaps:/usr/include/X11/bitmaps:/usr/include/X11/pixmaps

pre-configure:
	@${TOUCH} ${WRKSRC}/aclocal.m4
	@${TOUCH} ${WRKSRC}/stamp-h.in
	@find ${WRKSRC} -name Makefile.in -exec ${TOUCH} \{} \;

post-install:
	@${MKDIR} ${PREFIX}/${FVWM_DIR}/${PORTVERSION}
	@for i in ${RC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/sample.fvwmrc/$$i \
				${PREFIX}/${FVWM_DIR}/${PORTVERSION}/$$i; \
	done
	@${MKDIR} ${PREFIX}/${FVWM_DIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${WRKSRC}/icons/*.xbm \
			${WRKSRC}/icons/*.bitmap ${WRKSRC}/icons/*.icon \
		${PREFIX}/${FVWM_DIR}/pixmaps

.include <bsd.port.pre.mk>

.if defined(WITH_RPLAY) || (exists(${LOCALBASE}/lib/librplay.a) && \
    !defined(WITHOUT_RPLAY))
BUILD_DEPENDS=  rplay:${PORTSDIR}/audio/rplay
.endif

.include <bsd.port.post.mk>
