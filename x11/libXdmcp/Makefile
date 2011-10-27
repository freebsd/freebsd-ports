# New ports collection makefile for:   libXdmcp
# Date Created:			28 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXdmcp
PORTVERSION=	1.1.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Display Manager Control Protocol library

LICENSE=	MIT

XORG_CAT=	lib
USE_XORG=	xproto:both
WITH_FBSD10_FIX=	yes

CONFIGURE_ARGS+=--disable-docs --without-xmlto

post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ \
		s/doc//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
