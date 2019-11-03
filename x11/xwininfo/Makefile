# $FreeBSD$

PORTNAME=	xwininfo
PORTVERSION=	1.1.5
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Window information utility for X

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv xorg xorg-cat:app
USE_XORG=	x11 xcb xorgproto

LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm

CONFIGURE_ARGS=	--with-xcb-icccm

PLIST_FILES=	bin/xwininfo man/man1/xwininfo.1.gz

.include <bsd.port.mk>
