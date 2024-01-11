PORTNAME=	wmname
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	nuncupatio@gmail.com
COMMENT=	Prints/sets the window manager name property of the root window
WWW=		https://tools.suckless.org/x/wmname

USES=		xorg
USE_XORG=	x11 xorgproto

PLIST_FILES=	bin/wmname
MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC}" \
		X11LIB="${PREFIX}/lib" X11INC="${PREFIX}/include"

.include <bsd.port.mk>
