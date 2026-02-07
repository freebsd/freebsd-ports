PORTNAME=	zutty
DISTVERSION=	0.16
CATEGORIES=	x11
MASTER_SITES=	https://git.hq.sig7.se/zutty.git/snapshot/${ZUTTY_COMMIT}?dummy=/

MAINTAINER=	flo@purplekraken.com
COMMENT=	High-end terminal for low-end systems
WWW=		https://tomscii.sig7.se/zutty/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		gl pkgconfig waf xorg
USE_GL=		egl glesv2
USE_XORG=	x11 xmu xt

WRKSRC=		${WRKDIR}/${PORTNAME}-70150aa
ZUTTY_COMMIT=	70150aa6d5eb93d0e9c5696f5ab101a523354298

PLIST_FILES=	bin/zutty

pre-install:
	${STRIP_CMD} ${WRKSRC}/build/src/zutty

.include <bsd.port.mk>
