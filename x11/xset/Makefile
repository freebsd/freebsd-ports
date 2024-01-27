PORTNAME=	xset
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	User preference utility for X

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

EXTRACT_SUFX=	.tar.xz
USES=		xorg xorg-cat:app
USE_XORG=	xmuu x11 xext

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--without-xf86misc \
		--without-fontcache

PLIST_FILES=	bin/xset share/man/man1/xset.1.gz
.include <bsd.port.mk>
