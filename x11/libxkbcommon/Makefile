# $FreeBSD$

PORTNAME=	libxkbcommon
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xkbcommon.org/download/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Keymap handling library for toolkits and window systems

LICENSE=	MIT

XORG_CAT=	lib
USES=		gmake bison tar:xz

USE_XORG=	xcb
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--without-doxygen \
		--with-default-rules="xorg" \
		--with-x-locale-root=${PREFIX}/lib/X11/locale

.include <bsd.port.mk>
