# New ports collection makefile for:	xcmiscproto
# Date Created:				08 Aug 2005
# Whom:					Dejan Lesjak <lesi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcmiscproto
PORTVERSION=	1.2.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XCMisc extension headers

XORG_CAT=	proto

CONFIGURE_ARGS+=--disable-specs --without-xmlto

post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS =/,/^$$/ s/specs//' \
		${WRKSRC}/Makefile.in

#SUBDIRS= specs

.include <bsd.port.mk>
