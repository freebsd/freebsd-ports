PORTNAME=	libXxf86vm
DISTVERSION=	1.1.7
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Extension library for the XFree86-VidMode X extension
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxxf86vm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	xorgproto x11 xext
CPE_PRODUCT=	libxxf86vm
CPE_VENDOR=	x

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
