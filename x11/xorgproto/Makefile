# $FreeBSD$

PORTNAME=	xorgproto
PORTVERSION=	2020.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Window System unified protocol definitions

USES=		xorg-cat:proto

CONFIGURE_ARGS= --without-fop \
		--without-xmlto \
		--without-xsltproc \
		--disable-specs

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${MKDIR} ${WRKSRC}/man

.include <bsd.port.mk>
