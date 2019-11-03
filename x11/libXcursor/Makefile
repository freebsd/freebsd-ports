# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXcursor
PORTVERSION=	1.2.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X client-side cursor loading library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe xorg xorg-cat:lib
USE_XORG=	xrender x11 xfixes xorgproto
CPE_VENDOR=	x
CPE_PRODUCT=	libxcursor

CONFIGURE_ARGS=	--with-icondir=${PREFIX}/share/icons
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
