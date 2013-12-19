# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXtst
PORTVERSION=	1.2.2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Test extension

LICENSE=	MIT

XORG_CAT=	lib
USE_XORG=	x11 xext recordproto:both xextproto inputproto:both \
		xi
USE_AUTOTOOLS=	libtool

CONFIGURE_ARGS+=--disable-specs --without-xmlto

post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ \
		s/specs//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
