PORTNAME=	setxkbmap
DISTVERSION=	1.3.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Set the keyboard using the X Keyboard Extension
WWW=		https://gitlab.freedesktop.org/xorg/app/setxkbmap

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xkbfile xorgproto xrandr

CONFIGURE_ARGS=	--with-xkb-config-root=${LOCALBASE}/share/X11/xkb

PLIST_FILES=	bin/setxkbmap share/man/man1/setxkbmap.1.gz

.include <bsd.port.mk>
