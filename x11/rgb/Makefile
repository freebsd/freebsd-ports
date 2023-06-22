PORTNAME=	rgb
PORTVERSION=	1.1.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Uncompile an rgb color-name database
WWW=		https://gitlab.freedesktop.org/xorg/app/rgb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xorgproto

CONFIGURE_ARGS=	--with-rgb-db-dir=${PREFIX}/lib/X11/rgb

PLIST_FILES=	bin/showrgb \
		lib/X11/rgb.txt \
		man/man1/showrgb.1.gz

.include <bsd.port.mk>
