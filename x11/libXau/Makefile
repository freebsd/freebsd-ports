PORTNAME=	libXau
DISTVERSION=	1.0.12
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Authentication Protocol library for X11
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:lib
USE_XORG=	xorgproto

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
