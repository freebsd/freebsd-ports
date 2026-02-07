PORTNAME=	libXv
DISTVERSION=	1.0.13
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Video Extension library
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

EXTRACT_SUFX=	.tar.xz
USES=		cpe xorg xorg-cat:lib
USE_XORG=	x11 xext xorgproto
CPE_PRODUCT=	libxv
CPE_VENDOR=	x

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
