PORTNAME=	libXpresent
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Present Extension library
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxpresent

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:lib
USE_XORG=	x11 xfixes xext xorgproto xrandr

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
