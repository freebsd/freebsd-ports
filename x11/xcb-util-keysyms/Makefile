PORTNAME=	xcb-util-keysyms
PORTVERSION=	0.4.1
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Standard X key constants and conversion to/from keycodes
WWW=		https://xcb.freedesktop.org/

LICENSE=	MIT

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

USES=		gmake tar:xz xorg xorg-cat:lib
USE_XORG=	xcb

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
