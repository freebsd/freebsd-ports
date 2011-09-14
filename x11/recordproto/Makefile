# New ports collection makefile for:	recordproto
# Date Created:				06 Feb 2006
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	recordproto
PORTVERSION=	1.14.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	RECORD extension headers

XORG_CAT=	proto

CONFIGURE_ARGS+=--disable-specs --without-xmlto

post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS/,/&$$/ \
		s/specs//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
