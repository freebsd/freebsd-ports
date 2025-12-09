PORTNAME=	libfm-qt6
PORTVERSION=	2.3.1
CATEGORIES=	x11
MASTER_SITES=	LXQT/${PORTNAME:S/6//}

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Qt6 port of libfm
WWW=		https://github.com/lxqt/libfm-qt

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
		libexif.so:graphics/libexif
BUILD_DEPENDS=	lxqt-menu-data>=2.0.0:x11/lxqt-menu-data
RUN_DEPENDS=	lxqt-menu-data>=2.0.0:x11/lxqt-menu-data

USES=		cmake compiler:c++20-lang gettext-runtime lxqt:2 perl5 pkgconfig \
		qt:6 gnome shared-mime-info tar:xz xorg
USE_PERL5=	build
USE_QT=		base:run tools:build
USE_GNOME=	glib20
USE_XORG=	xcb
USE_LDCONFIG=	yes
USE_LXQT=	buildtools2

post-install:
	${RM} -Rf ${STAGEDIR}${PREFIX}/include/${PORTNAME}/tests/

.include <bsd.port.mk>
