# New ports collection makefile for:	fvwm95-2
# Date created:		23 Nov 1998
# Whom:			Yoshishige Arai <ryo2@on.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	fvwm95-i18n
PORTVERSION=	2.0.43a
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://mitac11.uia.ac.be/pub/fvwm95/ \
		ftp://ftp.plig.org/pub/fvwm95/ \
		ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/misc/fvwm95/ \
		${MASTER_SITE_PORTS_JP} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada
DISTNAME=	fvwm95-2.0.43a-Autoconf
DISTFILES=	${EXTRACT_ONLY} fvwm95-2.0.43a-FreeBSD.apmpatch.tar.gz

PATCH_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/misc/fvwm95/ \
		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	sada
PATCHFILES=	fvwm95-2.0.43a-Autoconf.I18N.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Win95 lookalike fvwm2 window manager with an I18N patch

BUILD_DEPENDS=	${LOCALBASE}/lib/librplay.a:${PORTSDIR}/audio/rplay
RUN_DEPENDS=	${X11BASE}/icons/chuck.xpm:${PORTSDIR}/x11/fbsd-icons

EXTRACT_ONLY=	${DISTNAME}.tgz ${PKGNAME}-portKit-19981123.tgz
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include \
		--mandir=${MANPREFIX}/man \
		--includedir=${LOCALBASE}/include --libdir=${LOCALBASE}/lib
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}"
MAN1=	fvwm95.1 xpmroot.1 FvwmAudio.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 \
	FvwmButtons.1 FvwmConsole.1 FvwmCpp.1 FvwmDebug.1 FvwmForm.1 \
	FvwmIconBox.1 FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 \
	FvwmSave.1 FvwmSaveDesk.1 FvwmScroll.1 FvwmTalk.1 FvwmTaskBar.1 \
	FvwmWinList.1

SAMPLEDIR=	${PREFIX}/share/examples/fvwm95
KITDIR=		${WRKDIR}/${PKGNAME}-portKit

post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/fvwm95-2.0.43a-FreeBSD.apmpatch.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	${CP} ${WRKDIR}/apmpatch/freebsd-menu.xpm ${WRKSRC}/mini-icons

pre-patch:
.if !defined(BATCH) && !defined(FOR_CDROM) && !defined(WITH_APM)
	@${ECHO} -n "Are you going to use APM handling? (y/n) ==> "
	@(read ans; \
	  case x"$$ans" in \
	    xy*|xY*) \
		${ECHO} "Okay, please rerun make like as \"make WITH_APM=yes\"."; \
		${ECHO} "(Don't worry about the following \"*** Error code 1\"s)"; \
		return 1; \
		;; \
	    *) \
		return 0; \
		;; \
	  esac)
.endif
post-patch:
.if defined(WITH_APM)
	@${CAT} ${WRKDIR}/apmpatch/fvwm95-2.0.43a-Autoconf.I18N.apmpatch \
	| ${PATCH} -d ${WRKSRC}
.endif

post-install:
	@(cd ${WRKSRC} ; ${MAKE} install.man)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${SAMPLEDIR}
	@${INSTALL_DATA} ${WRKSRC}/example.fvwm95rc  ${SAMPLEDIR}
.endif
	@${MKDIR} ${PREFIX}/lib/X11/fvwm95/ja_JP.EUC
	@${INSTALL_DATA} ${KITDIR}/system.fvwm95rc.jp \
		${PREFIX}/lib/X11/fvwm95/ja_JP.EUC/system.fvwm95rc
	@${INSTALL_SCRIPT} ${KITDIR}/fvwm95.find ${PREFIX}/bin

.include <bsd.port.mk>
