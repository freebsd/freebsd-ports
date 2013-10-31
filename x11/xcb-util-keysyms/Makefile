# $FreeBSD$

PORTNAME=	xcb-util-keysyms
PORTVERSION=	0.3.9
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Standard X key constants and conversion to/from keycodes

LIB_DEPENDS=	libxcb-util.so:${PORTSDIR}/x11/xcb-util

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_XORG=	xcb xorg-macros

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
