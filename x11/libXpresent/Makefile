PORTNAME=	libXpresent
DISTVERSION=	1.0.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Present Extension library
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxpresent

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xfixes xext xorgproto xrandr

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
