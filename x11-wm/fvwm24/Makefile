# New ports collection makefile for:	Fvwm2
# Date created:		20 Jan 1996
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	fvwm
PORTVERSION=	2.4.19
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		http://www.fvwm.org/generated/icon_download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fvwm_icons.tgz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Popular virtual window manager for X

RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

.if defined(WITH_STROKE)
LIB_DEPENDS+=	stroke.0:${PORTSDIR}/devel/libstroke
.endif

# Other ports reference this port's Makefile
.if defined(PKGNAMESUFFIX)
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
.else
LATEST_LINK=	${PORTNAME}2
.endif
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
WANT_GNOME=	yes

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes

.if defined(WITH_STROKE)
CONFIGURE_ARGS+=	--with-stroke --with-stroke-library=${LOCALBASE}/lib \
			--with-stroke-includes=${LOCALBASE}/include
.endif

.if defined(WITHOUT_SESSION_MGMT)
CONFIGURE_ARGS+=	--disable-sm
.endif

.if defined(WITHOUT_SHAPE)
CONFIGURE_ARGS+=	--disable-shape
.endif

.if defined(WITH_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-multibyte
.endif

PLIST_SUB+=	FVWM_VERSION="${PORTVERSION}"

.if ${HAVE_GNOME:Mimlib}!=""
USE_GNOME=	imlib
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-imlib
CONFIGURE_ARGS+=	--with-gnome --enable-gnome-hints \
			--enable-gtktest --enable-imlibtest
PLIST_SUB+=	GTK=""
.else
CONFIGURE_ARGS+=	--without-gnome --disable-gnome-hints \
			--disable-gtktest --disable-imlibtest \
			--with-gtk-prefix=/no/dir --with-imlib-prefix=/no/dir
PLIST_SUB+=	GTK="@comment not installed: "
.endif

MAN1=	FvwmAnimate.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 FvwmButtons.1 \
	FvwmCommand.1 FvwmConsole.1 FvwmConsoleC.pl.1 FvwmCpp.1 FvwmDebug.1 \
	FvwmDragWell.1 FvwmEvent.1 FvwmForm.1 FvwmIconBox.1 \
	FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 FvwmRearrange.1 \
	FvwmSave.1 FvwmSaveDesk.1 FvwmScript.1 FvwmScroll.1 FvwmTaskBar.1 \
	FvwmTheme.1 FvwmWharf.1 FvwmWinList.1 fvwm-menu-desktop.1 \
	fvwm-menu-directory.1 fvwm-menu-headlines.1 fvwm-menu-xlock.1 \
	fvwm2.1 fvwm24_convert.1 fvwmbug.1 fvwmrc_convert.1 xpmroot.1 \
	fvwm-config.1

post-extract:
	@${MKDIR} ${WRKDIR}/icons
	@${TAR} -xzf ${DISTDIR}/fvwm_icons.tgz -C ${WRKDIR}/icons

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKSRC}/modules/FvwmM4/FvwmM4.c

post-install:
	@${INSTALL_DATA} ${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
		${PREFIX}/etc/system.fvwm2rc.dist
	@if [ ! -e ${PREFIX}/etc/system.fvwm2rc ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
			${PREFIX}/etc/system.fvwm2rc; \
	fi
	@${MKDIR} ${PREFIX}/share/fvwm2/pixmaps
	${INSTALL_DATA} ${WRKDIR}/icons/fvwm_icons/*.xpm \
		${PREFIX}/share/fvwm2/pixmaps

.include <bsd.port.post.mk>
