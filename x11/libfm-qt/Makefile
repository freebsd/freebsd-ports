# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libfm-qt
PORTVERSION=	0.11.1
CATEGORIES=	x11
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Qt port of libfm

LICENSE=	LGPL21+

LIB_DEPENDS=	libfm.so:x11/libfm \
	libmenu-cache.so:x11/menu-cache

USES=	cmake:outsource compiler:c++11-lib gettext-runtime lxqt pkgconfig \
	tar:xz
USE_QT5=	buildtools_build qmake_build core gui widgets \
	x11extras
USE_GNOME=	glib20
USE_XORG=	xcb
USE_LXQT=	lxqt

.include <bsd.port.mk>
