# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libfm-qt
PORTVERSION=	0.14.1
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Qt port of libfm

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
		libexif.so:graphics/libexif

USES=	cmake compiler:c++14-lang gettext-runtime lxqt pkgconfig \
	qt:5 gnome shared-mime-info tar:xz xorg
USE_QT=	buildtools_build qmake_build core gui linguisttools widgets \
	x11extras
USE_GNOME=	glib20
USE_XORG=	xcb
USE_LXQT=	buildtools
USE_LDCONFIG=	yes

post-install:
	${RM} -Rf ${STAGEDIR}${PREFIX}/include/${PORTNAME}/tests/

.include <bsd.port.mk>
