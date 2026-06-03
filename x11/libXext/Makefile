PORTNAME=	libXext
DISTVERSION=	1.3.7
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Xlib-based library for common extensions to the X11 protocol
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxext

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xau xorgproto
CPE_VENDOR=	x
CPE_PRODUCT=	libxext

CONFIGURE_ARGS+=--disable-specs --without-xmlto
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
