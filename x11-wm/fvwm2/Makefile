# Created by: peter
# $FreeBSD$

PORTNAME=	fvwm
PORTVERSION=	2.6.7
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	https://github.com/fvwmorg/fvwm/releases/download/2.6.7/ \
		http://www.fvwm.org/generated/icon_download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Popular virtual window manager for X

RUN_DEPENDS=	gm4:devel/m4 \
		p5-XML-Parser>=0:textproc/p5-XML-Parser
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

# Other ports this port cannot coexist with
CONFLICTS?=	fvwm-1.* fvwm-2.[457].*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mandoc --without-gnome --disable-gtk
USES=		gmake perl5 pkgconfig gettext readline
USE_XORG=	xcursor xft xinerama xpm xrender x11 ice xext
USE_GNOME=	cairo

OPTIONS_DEFINE=	ICONS ICONV STROKE RPLAY SESSION_MGMT PNG SVG BIDI NLS
OPTIONS_DEFAULT=ICONS ICONV SESSION_MGMT PNG
OPTIONS_SUB=	yes

STROKE_DESC=		support for mouse gestures
RPLAY_DESC=		RPlay support in FvwmEvent
SESSION_MGMT_DESC=	Session Management support
BIDI_DESC=		Asian bi-directional text support

PLIST_SUB=	FVWM_VERSION="${PORTVERSION}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONS}
FVWM_ICONS=	fvwm_icons-20070101
DISTFILES+=	${FVWM_ICONS}.tar.bz2
.endif

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=	--with-iconv-library=${LOCALBASE}/lib \
			--with-iconv-includes=${LOCALBASE}/include \
			--enable-iconv
USES+=			iconv
.else
CONFIGURE_ARGS+=	--disable-iconv
.endif

.if ${PORT_OPTIONS:MSTROKE}
LIB_DEPENDS+=	libstroke.so:devel/libstroke
CONFIGURE_ARGS+=	--with-stroke-library=${LOCALBASE}/lib \
			--with-stroke-includes=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--without-stroke-library
.endif

.if ${PORT_OPTIONS:MRPLAY}
LIB_DEPENDS+=	librplay.so:audio/rplay
CONFIGURE_ARGS+=	--with-rplay-library=${LOCALBASE}/lib \
			--with-rplay-includes=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--without-rplay-library
.endif

.if ${PORT_OPTIONS:MSESSION_MGMT}
USE_XORG+=	sm
.else
CONFIGURE_ARGS+=	--disable-sm
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng.so:graphics/png
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
LIB_DEPENDS+=	libfribidi.so:converters/fribidi
CONFIGURE_ARGS+=	--enable-bidi \
			--with-bidi-bindir=${LOCALBASE}/bin
.else
CONFIGURE_ARGS+=	--disable-bidi
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--with-intl-library=${LOCALBASE}/lib \
			--with-intl-includes=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MICONS}
post-extract:
	@${MKDIR} ${WRKDIR}/icons
	@${TAR} -xzf ${DISTDIR}/${FVWM_ICONS}.tar.bz2 -C ${WRKDIR}/icons
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKSRC}/modules/FvwmM4/FvwmM4.c
	@${REINPLACE_CMD} -e 's,/etc/,${LOCALBASE}/etc/,g' \
		${WRKSRC}/bin/fvwm-menu-desktop.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/system.fvwm2rc \
		${STAGEDIR}${PREFIX}/etc/system.fvwm2rc.dist
.if ${PORT_OPTIONS:MICONS}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fvwm/pixmaps
	${INSTALL_DATA} ${WRKDIR}/icons/${FVWM_ICONS}/*.xpm \
		${STAGEDIR}${PREFIX}/share/fvwm/pixmaps
.endif

.include <bsd.port.post.mk>
