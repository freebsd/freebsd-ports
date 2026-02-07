PORTNAME=	xzoom
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	x11 accessibility
MASTER_SITES=	http://www.linklevel.net/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Magnify, rotate, mirror the image on the X11 screen

USES=		imake xorg
USE_XORG=	x11 xext
PLIST_FILES=	bin/xzoom share/man/man1/xzoom.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xzoom ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xzoom.man ${STAGEDIR}${PREFIX}/share/man/man1/xzoom.1

.include <bsd.port.mk>
