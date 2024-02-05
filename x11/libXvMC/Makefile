PORTNAME=	libXvMC
PORTVERSION=	1.0.14
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Video Extension Motion Compensation library
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xext xorgproto xv
CPE_VENDOR=	x
CPE_PRODUCT=	libxvmc

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
