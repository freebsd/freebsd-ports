PORTNAME=	xbiff
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Mailbox flag for X

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	x11 xaw xbitmaps xext xmu xt
PLIST_FILES=	bin/xbiff share/man/man1/xbiff.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
