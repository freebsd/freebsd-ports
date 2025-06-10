PORTNAME=	xmodmap
DISTVERSION=	1.0.11
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Utility for modifying keymaps and pointer button mappings in X
WWW=		https://gitlab.freedesktop.org/xorg/app/xmodmap

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xorgproto

PLIST_FILES=	bin/xmodmap share/man/man1/xmodmap.1.gz

.include <bsd.port.mk>
