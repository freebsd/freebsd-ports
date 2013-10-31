# $FreeBSD$

PORTNAME=	xcb-util-wm
PORTVERSION=	0.3.9
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Framework for window manager implementation

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
