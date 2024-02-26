PORTNAME=	xscope
PORTVERSION=	1.4.1
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Window Protocol Viewer
WWW=		https://www.x.org/releases/X11R7.6/doc/man/man1/xscope.1.xhtml

LICENSE=	MIT

USES=		xorg xorg-cat:app
USE_XORG=	xorgproto x11 xext

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/xscope share/man/man1/xscope.1.gz

.include <bsd.port.mk>
