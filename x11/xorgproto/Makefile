# $FreeBSD$

PORTNAME=	xorgproto
PORTVERSION=	2018.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	xorg protocol headers

XORG_CAT=	proto

CONFIGURE_ARGS= --without-fop \
		--without-xmlto \
		--without-xsltproc \
		--enable-legacy

pre-patch:
	@${MKDIR} ${WRKSRC}/man

.include <bsd.port.mk>
