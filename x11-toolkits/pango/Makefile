# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/pango/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	pango
PORTVERSION=	1.34.1
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open-source framework for the layout and rendering of i18n text

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	fontconfig>=2.10.91:${PORTSDIR}/x11-fonts/fontconfig
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		freetype:${PORTSDIR}/print/freetype2 \
		harfbuzz:${PORTSDIR}/print/harfbuzz \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${FONTSCALE}:${PORTSDIR}/x11-fonts/xorg-fonts-truetype \
		${FONTENCOD}:${PORTSDIR}/x11-fonts/encodings

USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20 ltverhack referencehack introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="1.8.0"

FONTSCALE=	${LOCALBASE}/lib/X11/fonts/TTF/luximb.ttf
FONTENCOD=	${LOCALBASE}/lib/X11/fonts/encodings/encodings.dir

MAN1=		pango-view.1 pango-querymodules.1

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG+=	xft xrender
#CONFIGURE_ARGS=--with-xft
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
