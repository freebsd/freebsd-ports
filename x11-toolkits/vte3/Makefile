# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vte
PORTVERSION=	0.48.3
PORTREVISION=	1
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
		libpcre2-8.so:devel/pcre2

PORTSCOUT=	limitw:1,even

USES=		compiler:c++0x gettext gmake gnome gperf libtool localbase \
		pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool referencehack \
		introspection:build
CONFIGURE_ARGS=	--enable-introspection \
		--disable-static
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=2.91

.include <bsd.port.mk>
