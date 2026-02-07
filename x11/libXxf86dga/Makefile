PORTNAME=	libXxf86dga
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X DGA Extension
WWW=		https://www.freedesktop.org/Software/xorg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

EXTRACT_SUFX=	.tar.xz
USES=		cpe xorg xorg-cat:lib
USE_XORG=	x11 xext xorgproto
CPE_VENDOR=	x
CPE_PRODUCT=	libxxf86dga

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
