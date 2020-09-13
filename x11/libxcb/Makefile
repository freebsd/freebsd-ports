# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	libxcb
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	https://xcb.freedesktop.org/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xcb-proto>=1.9:x11/xcb-proto \
		${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs

CONFIGURE_ARGS=	--disable-devel-docs --without-doxygen --enable-xinput --enable-xkb

USES=		cpe python:build tar:xz xorg xorg-cat:lib
USE_XORG=	xau xdmcp
INSTALL_TARGET=	install-strip
CPE_VENDOR=	x

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
