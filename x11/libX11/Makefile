# New ports collection makefile for:   libX11
# Date Created:			28 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libX11
PORTVERSION=	1.1.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library

.if defined(WITH_XCB)
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/xcb-xlib.pc:${PORTSDIR}/x11/libxcb
RUN_DEPENDS=	${BUILD_DEPENDS}
CONFIGURE_ARGS=	--with-xcb=yes
PLIST_SUB+=	XCB=""
.else
CONFIGURE_ARGS=	--with-xcb=no
PLIST_SUB+=	XCB="@comment "
.endif

XORG_CAT=	lib
USE_XORG=	bigreqsproto xau xdmcp xextproto xtrans xcmiscproto kbproto:both \
		inputproto:both xf86bigfontproto xproto:both
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS+=	--enable-xdmauth --datadir=${PREFIX}/lib

.include "${.CURDIR}/manpages"
.include <bsd.port.mk>
