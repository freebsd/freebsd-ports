PORTNAME=	pangomm
PORTVERSION=	2.46.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Pango
WWW=		https://www.gtkmm.org/

LICENSE=	LGPL21

USES=		compiler:c++11-lang gnome localbase meson pkgconfig \
		python:build tar:xz
USE_GNOME=	cairomm glibmm pango

USE_LDCONFIG=	yes
MESON_ARGS=	-Ddefault_library=both
BINARY_ALIAS=	python3=${PYTHON_CMD}

# 2.48 and later are incompatible
PORTSCOUT=	limit:^2\.46
PLIST_SUB=	API_VERSION=1.4

.include <bsd.port.mk>
