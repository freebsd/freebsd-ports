PORTNAME=	xwininfo
DISTVERSION=	1.1.6
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Window information utility for X
WWW=		https://gitlab.freedesktop.org/xorg/app/xwininfo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv tar:xz xorg xorg-cat:app
USE_XORG=	x11 xcb xorgproto

LIB_DEPENDS=	libxcb-errors.so:x11/xcb-util-errors \
		libxcb-icccm.so:x11/xcb-util-wm

CONFIGURE_ARGS=	--with-xcb-errors --with-xcb-icccm

PLIST_FILES=	bin/xwininfo share/man/man1/xwininfo.1.gz

.include <bsd.port.mk>
