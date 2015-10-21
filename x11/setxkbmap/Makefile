# $FreeBSD$

PORTNAME=	setxkbmap
PORTVERSION=	1.3.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Set the keyboard using the X Keyboard Extension

XORG_CAT=	app
USE_XORG=	xkbfile x11

CONFIGURE_ARGS=	--with-xkb-config-root=${LOCALBASE}/share/X11/xkb

PLIST_FILES=	bin/setxkbmap man/man1/setxkbmap.1.gz

.include <bsd.port.mk>
