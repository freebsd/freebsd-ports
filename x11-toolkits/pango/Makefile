# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/pango/Makefile 19817 2014-08-17 13:21:16Z gusi $

PORTNAME=	pango
PORTVERSION=	1.36.6
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Open-source framework for the layout and rendering of i18n text

USES=		tar:xz

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	fontconfig>=2.10.91:${PORTSDIR}/x11-fonts/fontconfig \
		cairo>=1.12.10,2:${PORTSDIR}/graphics/cairo
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libharfbuzz.so:${PORTSDIR}/print/harfbuzz \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${FONTSCALE}:${PORTSDIR}/x11-fonts/xorg-fonts-truetype \
		${FONTENCOD}:${PORTSDIR}/x11-fonts/encodings

USES+=		gettext gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	cairo glib20 introspection:build referencehack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

VERSION=	1.8.0
LIBVERSION=     0.3600.6
PLIST_SUB+=     VERSION=${VERSION} LIBVERSION=${LIBVERSION}

FONTSCALE=	${LOCALBASE}/lib/X11/fonts/TTF/luximb.ttf
FONTENCOD=	${LOCALBASE}/lib/X11/fonts/encodings/encodings.dir

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

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pango/

.include <bsd.port.mk>

.endif
