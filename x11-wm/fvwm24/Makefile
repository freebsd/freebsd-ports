# New ports collection makefile for:	Fvwm2
# Date created:		20 Jan 1996
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	fvwm
PORTVERSION=	2.4.3
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		http://www.fvwm.org/generated/icon_download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fvwm_icons.tgz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	petef@FreeBSD.org

USE_GMAKE=	yes
USE_GTK=	yes
USE_IMLIB=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes

GNU_CONFIGURE=	yes

PLIST_SUB+=	FVWM_VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
PLIST_SUB+=	GNOME=""
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=	GNOME="@comment "
.endif

MAN1=	FvwmAnimate.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 FvwmButtons.1 \
	FvwmCommand.1 FvwmConsole.1 FvwmConsoleC.pl.1 FvwmCpp.1 FvwmDebug.1 \
	FvwmDragWell.1 FvwmEvent.1 FvwmForm.1 FvwmGtk.1 FvwmIconBox.1 \
	FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 FvwmRearrange.1 \
	FvwmSave.1 FvwmSaveDesk.1 FvwmScript.1 FvwmScroll.1 FvwmTaskBar.1 \
	FvwmTheme.1 FvwmWharf.1 FvwmWinList.1 fvwm-menu-desktop.1 \
	fvwm-menu-directory.1 fvwm-menu-headlines.1 fvwm-menu-xlock.1 \
	fvwm2.1 fvwm24_convert.1 fvwmbug.1 fvwmrc_convert.1 xpmroot.1

post-extract:
	@${MKDIR} ${WRKDIR}/icons
	@${TAR} -xzf ${DISTDIR}/fvwm_icons.tgz -C ${WRKDIR}/icons

post-install:
	@${INSTALL_DATA} ${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
		${PREFIX}/etc/system.fvwm2rc.dist
	@if [ ! -e ${PREFIX}/etc/system.fvwm2rc ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
			${PREFIX}/etc/system.fvwm2rc; \
	fi
	@${MKDIR} ${PREFIX}/share/fvwm2/pixmaps
	${INSTALL_DATA} ${WRKDIR}/icons/*.xpm \
		${PREFIX}/share/fvwm2/pixmaps

.include <bsd.port.post.mk>
