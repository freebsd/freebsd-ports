# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thingylaunch
PORTVERSION=	2.0.3
PORTREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://gahr.ch/thingylaunch/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Lightweight launcher for X

LICENSE=	MIT BSD2CLAUSE
LICENSE_COMB=	multi

OPTIONS_SINGLE=		X11
OPTIONS_SINGLE_X11=	LIBX11 LIBXCB
LIBX11_DESC=		Build against libX11
LIBXCB_DESC=		Build against libXCB
OPTIONS_DEFAULT=	LIBX11

USE_XORG=	xorgproto
USE_CXXSTD=	c++11
USES=		cmake compiler:c++11-lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBX11}
USE_XORG+=	x11
.endif

.if ${PORT_OPTIONS:MLIBXCB}
USE_XORG+=	xcb
LIB_DEPENDS+=	libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms
CMAKE_ARGS+=	-DUSE_XCB:BOOL=ON
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	gahr

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
