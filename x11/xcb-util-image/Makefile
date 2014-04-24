# $FreeBSD$

PORTNAME=	xcb-util-image
PORTVERSION=	0.3.9
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A port of Xlib's XImage and XShmImage functions

LIB_DEPENDS=	libxcb-util.so:${PORTSDIR}/x11/xcb-util

XORG_CAT=	lib
USES=		gmake
USE_XORG=	xcb

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
