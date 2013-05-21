# $FreeBSD$

PORTNAME=	xdpyinfo
PORTVERSION=	1.3.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Display information utility for X

LICENSE=	MIT

XORG_CAT=	app
LIB_DEPENDS=	xcb:${PORTSDIR}/x11/libxcb
USE_XORG=	dmx x11 xcomposite xext xinerama xorg-macros xproto xrender \
		xtst xxf86dga xxf86misc xxf86vm

PLIST_FILES=	bin/xdpyinfo

MAN1=		xdpyinfo.1

.include <bsd.port.mk>
