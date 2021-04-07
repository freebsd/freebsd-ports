PORTNAME=	libXcm
PORTVERSION=	0.5.4
CATEGORIES=	x11

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	X Colour Management Library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	oyranos-cms
GH_PROJECT=	${PORTNAME:tl}

USES=		libtool pathfix pkgconfig xorg
GNU_CONFIGURE=	yes
USE_XORG=	x11 xfixes xmu xt
INSTALL_TARGET=	install-strip
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
