PORTNAME=	libfm-qt
PORTVERSION=	1.3.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Qt port of libfm
WWW=		https://github.com/lxqt/libfm-qt

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
		libexif.so:graphics/libexif

USES=	cmake compiler:c++14-lang gettext-runtime lxqt perl5 pkgconfig \
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
