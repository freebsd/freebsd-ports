PORTNAME=	libXrandr
DISTVERSION=	1.5.5
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Xlib Resize, Rotate and Reflection extension library
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxrandr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xext xrender xorgproto
CPE_VENDOR=	x
CPE_PRODUCT=	libxrandr

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
