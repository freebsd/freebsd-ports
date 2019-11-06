# $FreeBSD$

PORTNAME=	xorgproto
PORTVERSION=	2019.2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	xorg protocol headers

USES=		xorg-cat:proto

CONFIGURE_ARGS= --without-fop \
		--without-xmlto \
		--without-xsltproc \
		--disable-specs

pre-patch:
	@${MKDIR} ${WRKSRC}/man

.include <bsd.port.mk>
