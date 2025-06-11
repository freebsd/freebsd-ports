PORTNAME=	pangomm
PORTVERSION=	2.56.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome
PKGNAMESUFFIX=	24

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ bindings for Pango
WWW=		https://gtkmm.gnome.org/

LICENSE=	LGPL21+

USES+=		compiler:c++17-lang gnome libtool localbase meson \
		pkgconfig python:build tar:xz
USE_CXXSTD=	c++17
USE_GNOME=	cairomm11 glibmm26 pango libxslt
USE_LDCONFIG=	yes
MESON_ARGS=	-Dmaintainer-mode=false \
		-Dbuild-documentation=false
BINARY_WRAPPERS=	gm4

PLIST_SUB=	API_VERSION="2.48"

.include <bsd.port.mk>
