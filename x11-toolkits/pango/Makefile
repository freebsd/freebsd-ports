# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pango
PORTVERSION=	1.38.0
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Open-source framework for the layout and rendering of i18n text

USES=		tar:xz

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	fontconfig>=2.10.91:x11-fonts/fontconfig \
		cairo>=1.12.10,2:graphics/cairo
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype \
		${FONTENCOD}:x11-fonts/encodings

PORTSCOUT=	limitw:1,even

USES+=		gettext gmake gnome libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	cairo glib20 introspection:build referencehack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

VERSION=	1.8.0
LIBVERSION=	0.3800.0
PLIST_SUB+=     VERSION=${VERSION} LIBVERSION=${LIBVERSION}

FONTSCALE=	${LOCALBASE}/share/fonts/TTF/luximb.ttf
FONTENCOD=	${LOCALBASE}/share/fonts/encodings/encodings.dir

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG+=	xft xrender
#CONFIGURE_ARGS+=--with-xft
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--without-xft
PLIST_SUB+=	X11="@comment "
.endif

pre-configure:
.if !exists(${LOCALBASE}/libdata/pkgconfig/cairo-gobject.pc)
	@${ECHO_CMD} "${PKGNAME}: Needs cairo with GLIB (GObject) support enabled."
	@${FALSE}
.endif

.include <bsd.port.mk>

.endif
