PORTNAME=	xcalc
PORTVERSION=	1.1.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Scientific calculator for X

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	font-misc-misc>=1.1.2:x11-fonts/font-misc-misc \
		font-adobe-100dpi>=1.0.3:x11-fonts/font-adobe-100dpi \
		font-alias>=1.0.3:x11-fonts/font-alias \
		xbitmaps>=1.1.0:x11/xbitmaps

USES=		xorg xorg-cat:app
USE_XORG=	x11 xaw xt

.include <bsd.port.mk>
