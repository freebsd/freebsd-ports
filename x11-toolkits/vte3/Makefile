PORTNAME=	vte
PORTVERSION=	0.70.2
PORTREVISION=	5
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/vte/-/commit/
PATCHFILES+=	9b41cd101429.patch:-p1 #https://gitlab.gnome.org/GNOME/vte/-/issues/2618

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal widget with improved accessibility and I18N support
WWW=		https://wiki.gnome.org/Apps/Terminal/VTE

LICENSE=	LGPL21

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libicuuc.so:devel/icu

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang gettext gnome localbase meson \
		pkgconfig python tar:xz vala:build
USE_LDCONFIG=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build

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
FRIBIDI_MESON_OFF=	-Dfribidi=false

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_MESON_OFF=	-Dgnutls=false

GTK4_USE=		GNOME=gtk40
GTK4_MESON_ON=		-Dgtk4=true

.include <bsd.port.mk>
