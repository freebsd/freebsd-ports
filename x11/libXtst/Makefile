PORTNAME=	libXtst
PORTVERSION=	1.2.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Test extension
WWW=		https://www.freedesktop.org/Software/xorg

LICENSE=	MIT

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xext xi xorgproto
CPE_PRODUCT=	libxtst
CPE_VENDOR=	x

CONFIGURE_ARGS+=--disable-specs --without-xmlto

post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ \
		s/specs//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
