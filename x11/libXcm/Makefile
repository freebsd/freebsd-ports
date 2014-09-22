# $FreeBSD$

PORTNAME=	libXcm
PORTVERSION=	0.5.3
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/oyranos/${PORTNAME}/${PORTNAME}-${PORTVERSION:C|(.*)\.[0-9]*$|\1|}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	X Colour Management Library

LICENSE=	MIT

XORG_CAT=	lib
USES=		libtool:keepla pathfix pkgconfig
USE_XORG=	xfixes xmu
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
