PORTNAME=	libXau
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Authentication Protocol library for X11
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:lib
USE_XORG=	xorgproto

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=install-strip

.include <bsd.port.mk>
