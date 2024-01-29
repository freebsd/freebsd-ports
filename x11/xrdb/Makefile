PORTNAME=	xrdb
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X server resource database utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	xmuu x11

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/xrdb share/man/man1/xrdb.1.gz

.include <bsd.port.mk>
