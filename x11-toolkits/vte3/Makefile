# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vte
PORTVERSION=	0.60.3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal widget with improved accessibility and I18N support

LICENSE=	LGPL21

BUILD_DEPENDS=	vapigen:lang/vala \
		bash:shells/bash
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libfribidi.so:converters/fribidi \
		libpcre2-8.so:devel/pcre2

USES=		compiler:c++11-lang gettext gmake gnome gperf libtool localbase \
		meson pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool referencehack \
		introspection:build
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=2.91

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
