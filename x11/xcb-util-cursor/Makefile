PORTNAME=	xcb-util-cursor
DISTVERSION=	0.1.6
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XCB port of libXcursor
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxcb-cursor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-util.pc:x11/xcb-util \
		${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:x11/xcb-util-renderutil \
		${LOCALBASE}/libdata/pkgconfig/xcb-image.pc:x11/xcb-util-image

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-util.pc:x11/xcb-util \
		${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:x11/xcb-util-renderutil \
		${LOCALBASE}/libdata/pkgconfig/xcb-image.pc:x11/xcb-util-image

USES=		gmake gperf tar:xz xorg xorg-cat:lib
USE_XORG=	xcb
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
