# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libfm-qt
PORTVERSION=	0.11.2
CATEGORIES=	x11
#MASTER_SITES=	LXQT/${PORTNAME}
MASTER_SITES=	https://github.com/lxde/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Qt port of libfm

LICENSE=	LGPL21+

LIB_DEPENDS=	libfm.so:x11/libfm \
	libmenu-cache.so:x11/menu-cache

USES=	cmake:outsource compiler:c++11-lib gettext-runtime lxqt pkgconfig \
	tar:xz
USE_QT5=	buildtools_build qmake_build core gui linguisttools widgets \
	x11extras
USE_GNOME=	glib20
USE_XORG=	xcb
USE_LXQT=	buildtools

.include <bsd.port.mk>
