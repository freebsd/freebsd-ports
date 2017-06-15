# $FreeBSD$

PORTNAME=	libXcm
PORTVERSION=	0.5.4
CATEGORIES=	x11

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	X Colour Management Library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	oyranos-cms
GH_PROJECT=	${PORTNAME:tl}

USES=		libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_XORG=	x11 xfixes xmu xt
INSTALL_TARGET=	install-strip
PORTDOCS=	*

.include <bsd.port.mk>
