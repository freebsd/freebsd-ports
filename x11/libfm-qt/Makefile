PORTNAME=	libfm-qt
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Qt port of libfm
WWW=		https://github.com/lxqt/libfm-qt

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses qt5 switch to qt6 variant x11/libfm-qt6
EXPIRATION_DATE=2026-11-20

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
		libexif.so:graphics/libexif
BUILD_DEPENDS=	lxqt-menu-data>=1.4.1:x11/lxqt-menu-data
RUN_DEPENDS=	lxqt-menu-data>=1.4.1:x11/lxqt-menu-data

USES=	cmake compiler:c++14-lang gettext-runtime lxqt:1 perl5 pkgconfig \
	qt:5 gnome shared-mime-info tar:xz xorg
USE_PERL5=	build
USE_QT=	buildtools:build qmake:build core gui linguisttools widgets \
	x11extras
USE_GNOME=	glib20
USE_XORG=	xcb
USE_LXQT=	buildtools
USE_LDCONFIG=	yes

post-install:
	${RM} -Rf ${STAGEDIR}${PREFIX}/include/${PORTNAME}/tests/

.include <bsd.port.mk>
