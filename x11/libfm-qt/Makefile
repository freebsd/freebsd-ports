# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libfm-qt
PORTVERSION=	0.13.0
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Qt port of libfm

LICENSE=	LGPL21+

LIB_DEPENDS=	libfm.so:x11/libfm \
	libmenu-cache.so:x11/menu-cache \
	libexif.so:graphics/libexif

USES=	cmake compiler:c++11-lib gettext-runtime lxqt pkgconfig \
	qt:5 shared-mime-info tar:xz
USE_QT=		buildtools_build qmake_build core gui linguisttools widgets \
	x11extras
USE_GNOME=	glib20
USE_XORG=	xcb
USE_LXQT=	buildtools

post-install:
	${RM} -Rf ${STAGEDIR}${PREFIX}/include/${PORTNAME}/tests/

.include <bsd.port.mk>
