PORTNAME=	libXdmcp
PORTVERSION=	1.1.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Display Manager Control Protocol library

LICENSE=	MIT

USES=		cpe xorg xorg-cat:lib
USE_XORG=	xorgproto:both

CPE_VENDOR=	x.org

CONFIGURE_ARGS+=--disable-docs --without-xmlto

post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ \
		s/doc//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
