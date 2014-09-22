# $FreeBSD$

PORTNAME=	libXcm
PORTVERSION=	0.5.3
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	SF/oyranos/${PORTNAME}/${PORTNAME}-${PORTVERSION:C|(.*)\.[0-9]*$|\1|}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	X Colour Management Library

LICENSE=	MIT

USES=		libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_XORG=	xfixes xmu
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
