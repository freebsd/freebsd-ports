PORTNAME=	xcursorgen
DISTVERSION=	1.0.9
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Create an X cursor file from a collection of PNG images
WWW=		https://gitlab.freedesktop.org/xorg/app/xcursorgen

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

EXTRACT_SUFX=	.tar.xz
USES=		xorg xorg-cat:app
USE_XORG=	x11 xcursor xorgproto
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/xcursorgen share/man/man1/xcursorgen.1.gz

.include <bsd.port.mk>
