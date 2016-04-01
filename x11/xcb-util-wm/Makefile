# $FreeBSD$

PORTNAME=	xcb-util-wm
PORTVERSION=	0.4.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Framework for window manager implementation

LICNESE=	MIT

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

XORG_CAT=	lib
USES=		gmake
USE_XORG=	xcb

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
