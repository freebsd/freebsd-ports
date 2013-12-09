# Created by: peter
# $FreeBSD$

PORTNAME=	fvwm
PORTVERSION=	2.6.5
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		http://www.fvwm.org/generated/icon_download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Popular virtual window manager for X

RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

# Other ports this port cannot coexist with
CONFLICTS?=	fvwm-1.* fvwm-2.[457].*
NO_LATEST_LINK=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X_CFLAGS=-I${LOCALBASE}/include
CONFIGURE_ARGS= --mandir=${MANPREFIX}/man
USE_AUTOTOOLS=	autoconf
USES=		gmake pkgconfig
USE_XORG=	xpm xft
USE_BZIP2=	yes
WANT_GNOME=	yes

OPTIONS_DEFINE=	ICONS ICONV STROKE RPLAY SESSION_MGMT PNG SVG BIDI NLS IMLIB
OPTIONS_DEFAULT=	ICONV ICONV PNG
STROKE_DESC=		support for mouse gestures
RPLAY_DESC=		RPlay support in FvwmEvent
SESSION_MGMT_DESC=	Session Management support
BIDI_DESC=		Asian bi-directional text support
IMLIB_DESC=		imlib library (requires gtk12)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONS}
FVWM_ICONS=	fvwm_icons-20070101
DISTFILES+=	${FVWM_ICONS}.tar.bz2
.endif

.if ! ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=	--disable-iconv
.else
USES+=			iconv
CONFIGURE_ARGS+=	--with-iconv-library=${ICONV_PREFIX}/lib \
			--with-iconv-includes=${ICONV_PREFIX}/include
.endif

.if ${PORT_OPTIONS:MSTROKE}
LIB_DEPENDS+=	stroke.0:${PORTSDIR}/devel/libstroke
CONFIGURE_ARGS+=	--with-stroke-library=${LOCALBASE}/lib \
			--with-stroke-includes=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--without-stroke-library
.endif

.if ${PORT_OPTIONS:MRPLAY}
LIB_DEPENDS+=	rplay.1:${PORTSDIR}/audio/rplay
CONFIGURE_ARGS+=	--with-rplay-library=${LOCALBASE}/lib \
			--with-rplay-includes=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--without-rplay-library
.endif

.if ! ${PORT_OPTIONS:MSESSION_MGMT}
CONFIGURE_ARGS+=	--disable-sm
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-png-includes=${LOCALBASE}/include \
			--with-png-library=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-png-library
.endif

.if ${PORT_OPTIONS:MSVG}
USE_GNOME+=	librsvg2
.else
CONFIGURE_ARGS+=	--disable-rsvg
.endif

.if ${PORT_OPTIONS:MBIDI}
LIB_DEPENDS+=	fribidi.3:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=	--enable-bidi \
			--with-bidi-bindir=${LOCALBASE}/bin
.else
CONFIGURE_ARGS+=	--disable-bidi
.endif

PLIST_SUB+=	FVWM_VERSION="${PORTVERSION}"

.if ${PORT_OPTIONS:MIMLIB} && !defined(WITHOUT_GTK)
USE_GNOME+=	imlib
CONFIGURE_ARGS+=	--enable-gtktest --enable-imlibtest
PLIST_SUB+=	GTK=""
MAN1+=		FvwmGtk.1
.else
CONFIGURE_ARGS+=	--disable-gtktest --disable-imlibtest \
			--with-gtk-prefix=/no/dir --with-imlib-prefix=/no/dir
PLIST_SUB+=	GTK="@comment not installed: "
WITHOUT_GNOME=	true
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--with-intl-library=${LOCALBASE}/lib \
			--with-intl-includes=${LOCALBASE}/include
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment not installed: "
.endif

CONFIGURE_ARGS+=	--without-gnome

MAN1+=	FvwmAnimate.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 FvwmButtons.1 \
	FvwmCommand.1 FvwmConsole.1 FvwmConsoleC.pl.1 FvwmCpp.1 FvwmDebug.1 \
	FvwmDragWell.1 FvwmEvent.1 FvwmForm.1 FvwmIconBox.1 \
	FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 FvwmRearrange.1 \
	FvwmSave.1 FvwmSaveDesk.1 FvwmScript.1 FvwmScroll.1 FvwmTaskBar.1 \
	FvwmTheme.1 FvwmWharf.1 FvwmWinList.1 fvwm-menu-desktop.1 \
	fvwm-menu-directory.1 fvwm-menu-headlines.1 fvwm-menu-xlock.1 \
	fvwm.1 fvwm-root.1 fvwm-config.1 fvwm-bug.1 \
	fvwm-convert-2.4.1 fvwm-convert-2.6.1 \
	FvwmPerl.1 fvwm-perllib.1 FvwmProxy.1 FvwmTabs.1 FvwmWindowMenu.1 \
	FvwmGtkDebug.1

MLINKS=	fvwm.1 fvwm2.1 \
	fvwm-root.1 xpmroot.1

.if ${PORT_OPTIONS:MICONS}
PLIST_SUB+=	ICONS=""
post-extract:
	@${MKDIR} ${WRKDIR}/icons
	@${TAR} -xzf ${DISTDIR}/${FVWM_ICONS}.tar.bz2 -C ${WRKDIR}/icons
.else
PLIST_SUB+=	ICONS="@comment not installed: "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKSRC}/modules/FvwmM4/FvwmM4.c \
		${WRKSRC}/configure

post-install:
	@${INSTALL_DATA} ${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
		${PREFIX}/etc/system.fvwm2rc.dist
	@if [ ! -e ${PREFIX}/etc/system.fvwm2rc ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
			${PREFIX}/etc/system.fvwm2rc; \
	fi

.if ${PORT_OPTIONS:MICONS}
	@${MKDIR} ${PREFIX}/share/fvwm/pixmaps
	${INSTALL_DATA} ${WRKDIR}/icons/${FVWM_ICONS}/*.xpm \
		${PREFIX}/share/fvwm/pixmaps
.endif

.include <bsd.port.mk>
