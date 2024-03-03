PORTNAME=	libxcb
PORTVERSION=	1.16.1
CATEGORIES=	x11
MASTER_SITES=	https://xcb.freedesktop.org/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) library
WWW=		https://xcb.freedesktop.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xcb-proto>=1.9:x11/xcb-proto

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-devel-docs --without-doxygen --enable-xinput --enable-xkb

USES=		cpe python:build tar:xz xorg xorg-cat:lib
USE_XORG=	xau xdmcp
INSTALL_TARGET=	install-strip
CPE_VENDOR=	x

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
