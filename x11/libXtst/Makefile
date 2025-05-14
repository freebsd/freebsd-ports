PORTNAME=	libXtst
DISTVERSION=	1.2.5
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Test extension
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxtst

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xext xi xorgproto
CPE_PRODUCT=	libxtst
CPE_VENDOR=	x

CONFIGURE_ARGS+=--disable-specs --without-xmlto

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ \
		s/specs//' ${WRKSRC}/Makefile.in

post-build:
	@${REINPLACE_CMD} -e 's|^\.so |.so man3/|' ${WRKSRC}/man/*.3

.include <bsd.port.mk>
