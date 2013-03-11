# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libX11
PORTVERSION=	1.4.4
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library

LICENSE=	MIT

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/xcb.pc:${PORTSDIR}/x11/libxcb
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/xcb.pc:${PORTSDIR}/x11/libxcb

XORG_CAT=	lib
USE_XORG=	bigreqsproto xau xcmiscproto xdmcp xextproto xtrans \
		kbproto:both inputproto xf86bigfontproto xproto:both \
		xorg-macros

CONFIGURE_ARGS+=	--datadir=${PREFIX}/lib \
			--without-xmlto \
			--disable-specs
CONFIGURE_ENV+=	ac_cv_path_PS2PDF=""

.include "${.CURDIR}/manpages"

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/^install-data-am:/,/^$$/ \
		s/install-specDATA//' ${WRKSRC}/nls/Makefile.in

.include <bsd.port.mk>
