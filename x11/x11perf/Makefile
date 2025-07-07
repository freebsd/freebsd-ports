PORTNAME=	x11perf
DISTVERSION=	1.7.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 server performance test program
WWW=		https://gitlab.freedesktop.org/xorg/test/x11perf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cpe tar:xz xorg xorg-cat:test
USE_XORG=	x11 xext xft xmuu xorgproto xrender
CPE_VENDOR=	xfree86

.include <bsd.port.mk>
