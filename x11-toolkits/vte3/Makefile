PORTNAME=	vte
PORTVERSION=	0.78.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome

# https://gitlab.gnome.org/GNOME/vte/-issues/2823
PATCH_SITES=	https://gitlab.gnome.org/GNOME/vte/-/commit/
PATCHFILES+=	f6095fca4d1b.patch:-p1 \
		6c2761f51a04.patch:-p1 \
		d09330585e64.patch:-p1 \
		b262c4432b80.patch:-p1 \
		ae2b83c6fc83.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal widget with improved accessibility and I18N support
WWW=		https://wiki.gnome.org/Apps/Terminal/VTE

LICENSE=	LGPL21

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/include/fast_float/fast_float.h:math/fast_float
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		liblz4.so:archivers/liblz4 \
		libicuuc.so:devel/icu

PORTSCOUT=	limitw:1,even

USES=		compiler:c++17-lang gettext gnome localbase meson \
		pkgconfig python tar:xz vala:build
USE_LDCONFIG=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build

# Disable build time flooding.
CFLAGS+=	-Wno-cast-function-type-strict
MESON_ARGS=	-Da11y=true \
		-Dgir=true \
		-Dgtk3=true \
		-Dicu=true \
		-D_systemd=false \
		-Dvapi=true

# shlib version numbers come from gtk3/4 meson options, not from PYTHON_VER
PLIST_SUB=	VERSION=2.91 VER3=3.91

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=	FRIBIDI GNUTLS GTK4
OPTIONS_DEFAULT=FRIBIDI GNUTLS GTK4
OPTIONS_SUB=	yes

FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_MESON_TRUE=	fribidi

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_MESON_TRUE=	gnutls

GTK4_LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene
GTK4_USE=		GNOME=gtk40
GTK4_MESON_TRUE=	gtk4

.include <bsd.port.mk>
