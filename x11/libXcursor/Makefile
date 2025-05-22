PORTNAME=	libXcursor
DISTVERSION=	1.2.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X client-side cursor loading library
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	xrender x11 xfixes xorgproto
CPE_VENDOR=	x
CPE_PRODUCT=	libxcursor

CONFIGURE_ARGS=	--with-icondir=${PREFIX}/share/icons \
		--with-cursorpath="~/.local/share/icons:~/.icons:${PREFIX}/share/icons:${PREFIX}/share/pixmaps"
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
