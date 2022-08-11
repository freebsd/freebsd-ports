PORTNAME=	xcb-imdkit
DISTVERSION=	1.0.3
CATEGORIES=	x11 textproc

MAINTAINER=	khng300@gmail.com
COMMENT=	Input method development support for XCB

LICENSE=	LGPL21+

BUILD_DEPENDS=	uthash>=0:devel/uthash
LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
		libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		compiler:c11 cmake pkgconfig kde:5 xorg

PLIST_SUB=	VER=${PORTVERSION}

CMAKE_ON=	SYSTEM_USE_UTHASH

USE_KDE=	ecm
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

.include <bsd.port.mk>
