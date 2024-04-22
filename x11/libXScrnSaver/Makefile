PORTNAME=	libXScrnSaver
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	The XScrnSaver library
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

EXTRACT_SUFX=	.tar.xz
USES=		xorg xorg-cat:lib
USE_XORG=	x11 xext xorgproto

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
