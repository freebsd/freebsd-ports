PORTNAME=	rgb
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Uncompile an rgb color-name database

CONFIGURE_ARGS=	--with-rgb-db-dir=${PREFIX}/lib/X11/rgb

USES=		xorg xorg-cat:app
USE_XORG=	x11 xorgproto

PLIST_FILES=	bin/showrgb lib/X11/rgb.txt man/man1/showrgb.1.gz

.include <bsd.port.mk>
