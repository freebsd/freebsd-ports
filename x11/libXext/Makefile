# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXext
PORTVERSION=	1.3.3
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 Extension library

LICENSE=	MIT

XORG_CAT=	lib
USE_XORG=	xproto x11 xextproto:both xau
CONFIGURE_ARGS+=--disable-specs --without-xmlto
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
