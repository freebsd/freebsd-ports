PORTNAME=	libXrandr
PORTVERSION=	1.5.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Resize and Rotate extension library
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xext xrender xorgproto
CPE_VENDOR=	x
CPE_PRODUCT=	libxrandr

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
