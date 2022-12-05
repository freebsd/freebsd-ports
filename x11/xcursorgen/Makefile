PORTNAME=	xcursorgen
PORTVERSION=	1.0.8
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Create an X cursor file from a collection of PNG images

LICENSE=	MIT

LIB_DEPENDS=	libpng.so:graphics/png

EXTRACT_SUFX=	.tar.xz
USES=		xorg xorg-cat:app
USE_XORG=	x11 xcursor xorgproto
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/xcursorgen man/man1/xcursorgen.1.gz

.include <bsd.port.mk>
