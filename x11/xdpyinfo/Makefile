PORTNAME=	xdpyinfo
PORTVERSION=	1.3.2
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Display information utility for X

LICENSE=	MIT

USES=		xorg xorg-cat:app
USE_XORG=	dmx x11 xcb xcomposite xext xinerama xorgproto xrender \
		xtst xxf86dga xxf86vm

CONFIGURE_ARGS=	--without-xf86misc

PLIST_FILES=	bin/xdpyinfo man/man1/xdpyinfo.1.gz

.include <bsd.port.mk>
