# Created by: Dejan Lesjak <lesi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	resourceproto
PORTVERSION=	1.2.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Resource extension headers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

XORG_CAT=	proto

post-patch:
	@${REINPLACE_CMD} '/^install-data-am:/,/^$$/ \
		s/install-dist_docDATA//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
