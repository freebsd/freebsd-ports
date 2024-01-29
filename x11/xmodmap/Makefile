PORTNAME=	xmodmap
PORTVERSION=	1.0.10
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Utility for modifying keymaps and pointer button mappings in X

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	x11

PLIST_FILES=	bin/xmodmap share/man/man1/xmodmap.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
