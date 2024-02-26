PORTNAME=	libXcm
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Colour Management Library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	oyranos-cms
GH_PROJECT=	${PORTNAME:tl}

USES=		libtool pathfix pkgconfig xorg
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_XORG=	x11 xfixes xmu xt
INSTALL_TARGET=	install-strip
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
