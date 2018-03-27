# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pango
PORTVERSION=	1.42.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Open-source framework for the layout and rendering of i18n text

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfribidi.so:converters/fribidi
RUN_DEPENDS=	xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype \
		${FONTENCOD}:x11-fonts/encodings

PORTSCOUT=	limitw:1,even

USES+=		gettext gmake gnome libtool localbase pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	cairo glib20 introspection:build referencehack
INSTALL_TARGET=	install-strip

VERSION=	1.8.0
LIBVERSION=	0.4200.0
PLIST_SUB+=     VERSION=${VERSION} LIBVERSION=${LIBVERSION}

FONTSCALE=	${LOCALBASE}/share/fonts/TTF/luximb.ttf
FONTENCOD=	${LOCALBASE}/share/fonts/encodings/encodings.dir

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_CONFIGURE_WITH=	xft
X11_USE=	XORG=x11,xft,xrender

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-gobject; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with GLIB (GObject) support enabled."; \
		${FALSE}; \
	fi

.include <bsd.port.mk>

.endif
