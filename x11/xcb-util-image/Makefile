# $FreeBSD$

PORTNAME=	xcb-util-image
PORTVERSION=	0.3.9
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A port of Xlib's XImage and XShmImage functions

LIB_DEPENDS=	libxcb-util.so:${PORTSDIR}/x11/xcb-util

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_LDCONFIG=	yes
USE_XORG=	xcb xorg-macros

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
