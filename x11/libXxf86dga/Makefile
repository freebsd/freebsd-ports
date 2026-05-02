PORTNAME=	libXxf86dga
DISTVERSION=	1.1.7
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Client library for the XFree86-DGA extension
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxxf86dga

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xext xorgproto
CPE_VENDOR=	x
CPE_PRODUCT=	libxxf86dga

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
