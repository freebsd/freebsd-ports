PORTNAME=	wmname
DISTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	nuncupatio@gmail.com
COMMENT=	Prints/sets the window manager name property of the root window
WWW=		https://tools.suckless.org/x/wmname

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		xorg
USE_XORG=	x11 xorgproto

MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC}" \
		X11LIB="${PREFIX}/lib" X11INC="${PREFIX}/include"
PLIST_FILES=	bin/wmname

.include <bsd.port.mk>
