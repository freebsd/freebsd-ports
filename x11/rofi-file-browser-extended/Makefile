PORTNAME=	rofi-file-browser-extended
DISTVERSION=	1.3.1
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Use rofi to quickly open files
WWW=		https://github.com/marvinkreis/rofi-file-browser-extended

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rofi:x11/rofi
RUN_DEPENDS=	rofi:x11/rofi

USES=		cmake gettext-runtime gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	marvinkreis
USE_GNOME=	cairo glib20

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/man/man1 \
		-DROFI_PLUGINS_DIR=${PREFIX}/lib/rofi

PLIST_FILES=	lib/rofi/filebrowser.so \
		man/man1/rofi-file-browser-extended.1.gz

.include <bsd.port.mk>
