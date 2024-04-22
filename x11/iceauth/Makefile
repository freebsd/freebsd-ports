PORTNAME=	iceauth
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	ICE authority file utility for X

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	xorgproto ice

GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/iceauth share/man/man1/iceauth.1.gz

.include <bsd.port.mk>
