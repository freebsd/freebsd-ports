# New ports collection makefile for:	fvwm95-2
# Date created:		23 Nov 1998
# Whom:			Yoshishige Arai <ryo2@on.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	fvwm95-i18n
PORTVERSION=	2.0.43a
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	SF/fvwm95/fvwm95/${PORTVERSION}
DISTNAME=	fvwm95-2.0.43a-Autoconf
DISTFILES=	${EXTRACT_ONLY} fvwm95-2.0.43a-FreeBSD.apmpatch.tar.gz

PATCH_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/misc/fvwm95/ \
		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	sada
PATCHFILES=	fvwm95-2.0.43a-Autoconf.I18N.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Win95 lookalike fvwm2 window manager with an I18N patch

DEPRECATED=	Depends on x11/fbsd-icons, which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

LIB_DEPENDS=	rplay.1:${PORTSDIR}/audio/rplay
RUN_DEPENDS=	${LOCALBASE}/icons/chuck.xpm:${PORTSDIR}/x11/fbsd-icons

EXTRACT_ONLY=	${DISTNAME}.tgz ${PORTNAME}-${PORTVERSION}-portKit-19981123.tgz

USE_XORG=	xbitmaps x11 xpm xmu xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--x-includes=${LOCALBASE}/include \
		--includedir=${LOCALBASE}/include --libdir=${LOCALBASE}/lib
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}"
MAN1=	fvwm95.1 xpmroot.1 FvwmAudio.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 \
	FvwmButtons.1 FvwmConsole.1 FvwmCpp.1 FvwmDebug.1 FvwmForm.1 \
	FvwmIconBox.1 FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 \
	FvwmSave.1 FvwmSaveDesk.1 FvwmScroll.1 FvwmTalk.1 FvwmTaskBar.1 \
	FvwmWinList.1

EXAMPLESDIR=	${PREFIX}/share/examples/fvwm95
KITDIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-portKit

OPTIONS=	APM "Build APM support (i386 only)" off

.include <bsd.port.pre.mk>

.if defined(WITH_APM)
ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	apm.h is only in i386 system
.endif

post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/fvwm95-2.0.43a-FreeBSD.apmpatch.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	${CP} ${WRKDIR}/apmpatch/freebsd-menu.xpm ${WRKSRC}/mini-icons

post-patch:
.if defined(WITH_APM)
	@${CAT} ${WRKDIR}/apmpatch/fvwm95-2.0.43a-Autoconf.I18N.apmpatch \
	| ${PATCH} -d ${WRKSRC}
.endif

post-install:
	@(cd ${WRKSRC} ; ${MAKE} install.man)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/example.fvwm95rc  ${EXAMPLESDIR}
	@${MKDIR} ${PREFIX}/lib/X11/fvwm95/ja_JP.EUC
	@${INSTALL_DATA} ${KITDIR}/system.fvwm95rc.jp \
		${PREFIX}/lib/X11/fvwm95/ja_JP.EUC/system.fvwm95rc
	@${INSTALL_SCRIPT} ${KITDIR}/fvwm95.find ${PREFIX}/bin

.include <bsd.port.post.mk>
