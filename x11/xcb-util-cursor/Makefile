PORTNAME=	xcb-util-cursor
PORTVERSION=	0.1.5
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
MAINTAINER=	x11@FreeBSD.org
COMMENT=	XCB cursor library
WWW=		https://xcb.freedesktop.org/
PATCH_SITES= 	https://gitlab.freedesktop.org/xorg/lib/libxcb-cursor/-/commit/
PATCHFILES=	d28a3227eb9e4bdeeb4dd93017c298808bbe62ee.patch:-p1
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-util.pc:x11/xcb-util \
		${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:x11/xcb-util-renderutil \
		${LOCALBASE}/libdata/pkgconfig/xcb-image.pc:x11/xcb-util-image

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-util.pc:x11/xcb-util \
		${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:x11/xcb-util-renderutil \
		${LOCALBASE}/libdata/pkgconfig/xcb-image.pc:x11/xcb-util-image

USES=		autoreconf gmake gperf tar:xz xorg xorg-cat:lib
USE_XORG=	xcb
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
