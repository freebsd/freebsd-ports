# New ports collection makefile for:	Fvwm2
# Date created:		20 Jan 1996
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	fvwm
PORTVERSION=	2.3.30
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		http://www.fvwm.org/generated/icon_download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fvwm_icons.tgz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	Cy.Schubert@uumail.gov.bc.ca

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_BZIP2=	yes
WANT_GTK=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_SUB=	VER=${PORTVERSION}
CONFIGURE_ARGS=	--enable-gnome

MAN1=	FvwmAnimate.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 FvwmButtons.1 \
	FvwmCommand.1 FvwmConsole.1 FvwmConsoleC.pl.1 FvwmCpp.1 FvwmDebug.1 \
	FvwmDragWell.1 FvwmEvent.1 FvwmForm.1 FvwmGtk.1 FvwmIconBox.1 \
	FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 FvwmRearrange.1 \
	FvwmSave.1 FvwmSaveDesk.1 FvwmScript.1 FvwmScroll.1 FvwmTaskBar.1 \
	FvwmTheme.1 FvwmWharf.1 FvwmWinList.1 \
	fvwm-menu-desktop.1 fvwm-menu-directory.1 fvwm-menu-headlines.1 \
	fvwm-menu-xlock.1 fvwm2.1 fvwm24_convert.1 fvwmbug.1 fvwmrc_convert.1 \
	xpmroot.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK) && !defined(WITHOUT_GTK)
USE_GTK=	yes
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

post-extract:
	@if ! (cd ${WRKDIR}/${DISTNAME} && ${MKDIR} icons && cd icons && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/fvwm_icons.tgz ${EXTRACT_AFTER_ARGS}); then \
		exit 1; \
	fi

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm \
		${PREFIX}/lib/X11/fvwm2/pixmaps

.include <bsd.port.post.mk>
