# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libfm-qt
PORTVERSION=	0.12.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt port of libfm

LICENSE=	LGPL21+

LIB_DEPENDS=	libfm.so:x11/libfm \
	libmenu-cache.so:x11/menu-cache \
	libexif.so:graphics/libexif

USES=	cmake:outsource compiler:c++11-lib gettext-runtime lxqt pkgconfig \
	shared-mime-info tar:xz
USE_QT5=	buildtools_build qmake_build core gui linguisttools widgets \
	x11extras
USE_GNOME=	glib20
USE_XORG=	xcb
USE_LXQT=	buildtools

post-install:
	${RM} -Rf ${STAGEDIR}${PREFIX}/include/${PORTNAME}/tests/

.include <bsd.port.mk>
