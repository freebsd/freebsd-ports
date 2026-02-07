PORTNAME=	sdl2_pango
PORTVERSION=	2.1.5
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-toolkits

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Graphically rendering internationalized and tagged text in SDL2
WWW=		https://github.com/markuskimius/SDL2_Pango

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pathfix pkgconfig sdl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	markuskimius
GH_PROJECT=	SDL2_Pango

GNU_CONFIGURE=	yes
USE_GNOME=	pango
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
