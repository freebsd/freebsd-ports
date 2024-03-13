PORTNAME=	rofi-file-browser-extended
DISTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	6f62a2d0784a6937d35ac8f6df2e22c23bbfc8f4.patch:-p1 # Fix function pointer initialization
PATCHFILES+=	4d402e599e209a072492cc8c0e35a5e039e7bfd6.patch:-p1 # Check that 'height' is within INT_MAX

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

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man/man1 \
		-DROFI_PLUGINS_DIR=${PREFIX}/lib/rofi

PLIST_FILES=	lib/rofi/filebrowser.so \
		share/man/man1/rofi-file-browser-extended.1.gz

.include <bsd.port.mk>
