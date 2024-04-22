PORTNAME=	zutty
DISTVERSION=	0.15
CATEGORIES=	x11
MASTER_SITES=	https://git.hq.sig7.se/zutty.git/snapshot/7e481c04507e9b5cacfe67fe2b96bdb449b08726?dummy=/

MAINTAINER=	flo@purplekraken.com
COMMENT=	High-end terminal for low-end systems
WWW=		https://tomscii.sig7.se/zutty/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		gl pkgconfig waf xorg
USE_GL=		egl glesv2
USE_XORG=	x11 xmu xt

WRKSRC=		${WRKDIR}/${PORTNAME}-7e481c0

PLIST_FILES=	bin/zutty

pre-install:
	${STRIP_CMD} ${WRKSRC}/build/src/zutty

.include <bsd.port.mk>
