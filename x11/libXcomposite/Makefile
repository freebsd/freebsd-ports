PORTNAME=	libXcomposite
PORTVERSION=	0.4.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Composite extension library
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

EXTRACT_SUFX=	.tar.xz
USES=		xorg xorg-cat:lib
USE_XORG=	x11 xfixes xext xorgproto

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
