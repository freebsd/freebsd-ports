PORTNAME=	xdpyinfo
DISTVERSION=	1.3.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Display information utility for X
WWW=		https://gitlab.freedesktop.org/xorg/app/xdpyinfo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xcb xcomposite xext xi xinerama xorgproto xrender \
		xtst xxf86dga xxf86vm

PLIST_FILES=	bin/xdpyinfo share/man/man1/xdpyinfo.1.gz

.include <bsd.port.mk>
