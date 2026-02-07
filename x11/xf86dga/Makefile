PORTNAME=	xf86dga
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Test program for the XFree86-DGA extension

LICENSE=	MIT

USES=		xorg xorg-cat:app
USE_XORG=	x11 xxf86dga xt xaw7 xmu

PLIST_FILES=	bin/dga share/man/man1/dga.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
