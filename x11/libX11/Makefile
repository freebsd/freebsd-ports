# New ports collection makefile for:   libX11
# Date Created:			28 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libX11
PORTVERSION=	1.2.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/xcb.pc:${PORTSDIR}/x11/libxcb \
		${LOCALBASE}/share/aclocal/xorg-macros.m4:${PORTSDIR}/devel/xorg-macros
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/xcb.pc:${PORTSDIR}/x11/libxcb

XORG_CAT=	lib
USE_XORG=	bigreqsproto xau xcmiscproto xdmcp xextproto xtrans \
		kbproto:both inputproto xf86bigfontproto xproto:both
USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS+=	--datadir=${PREFIX}/lib \
			--with-xcb=yes

.include "${.CURDIR}/manpages"
.include <bsd.port.mk>
