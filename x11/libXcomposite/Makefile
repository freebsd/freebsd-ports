PORTNAME=	libXcomposite
PORTVERSION=	0.4.6
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

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
