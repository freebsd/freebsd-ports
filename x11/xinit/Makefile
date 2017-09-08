# $FreeBSD$

PORTNAME=	xinit
PORTVERSION=	1.3.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Window System initializer

LICENSE=	MIT

XORG_CAT=	app
USE_XORG=	x11

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|hexdump|/usr/bin/hexdump|' ${WRKSRC}/startx.cpp
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/man/xinit.man

.include <bsd.port.mk>
