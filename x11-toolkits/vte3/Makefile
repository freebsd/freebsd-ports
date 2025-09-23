PORTNAME=	vte
PORTVERSION=	0.80.4
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal widget with improved accessibility and I18N support
WWW=		https://gitlab.gnome.org/GNOME/vte

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/include/fast_float/fast_float.h:math/fast_float
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		liblz4.so:archivers/liblz4 \
		libicuuc.so:devel/icu

PORTSCOUT=	limitw:1,even

USES=		compiler:c++20-lang gettext-tools gnome localbase meson \
		pkgconfig python:build tar:xz vala:build
USE_LDCONFIG=	yes
USE_GNOME=	cairo gdkpixbuf gtk30 introspection:build

# Disable build time flooding.
CFLAGS+=	-Wno-cast-function-type-strict
MESON_ARGS=	-Da11y=true \
		-Dgir=true \
		-Dgtk3=true \
		-Dicu=true \
		-D_systemd=false \
		-Dglade=false \
		-Dvapi=true

# VTE API minor version
PLIST_SUB=	API_VER=91

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
