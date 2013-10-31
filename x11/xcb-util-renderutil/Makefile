# $FreeBSD$

PORTNAME=	xcb-util-renderutil
PORTVERSION=	0.3.8
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Convenience functions for the Render extension

LIB_DEPENDS=	libxcb-util.so:${PORTSDIR}/x11/xcb-util

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_XORG=	xcb xorg-macros
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
