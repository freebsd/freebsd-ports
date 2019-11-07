# Created by: mwm@mired.org
# $FreeBSD$

PORTNAME=	ratmenu
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.mired.org/downloads/

MAINTAINER=	mwm@mired.org
COMMENT=	Simple menu patterened for use with ratpoison

BROKEN=		unfetchable

USES=		xorg
USE_XORG=	x11
ALL_TARGET=	ratmenu
PLIST_FILES=	bin/ratmenu \
		man/man1/ratmenu.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratmenu ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ratmenu.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
