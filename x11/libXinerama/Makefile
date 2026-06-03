PORTNAME=	libXinerama
DISTVERSION=	1.1.6
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 Xinerama extension library
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxinerama

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xext xorgproto
CPE_PRODUCT=	libxinerama
CPE_VENDOR=	x

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
