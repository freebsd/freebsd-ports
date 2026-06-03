PORTNAME=	libX11
DISTVERSION=	1.8.13
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Core X11 protocol client library
WWW=		https://gitlab.freedesktop.org/xorg/lib/libx11

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	xcb xtrans xorgproto
CPE_VENDOR=	x

CONFIGURE_ARGS+=	--datadir=${PREFIX}/lib \
			--without-xmlto \
			--with-perl=no \
			--disable-specs
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
