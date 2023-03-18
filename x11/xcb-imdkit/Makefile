PORTNAME=	xcb-imdkit
DISTVERSION=	1.0.5
CATEGORIES=	x11 textproc

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Input method development support for XCB
WWW=		https://github.com/fcitx/xcb-imdkit

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-only.txt

BUILD_DEPENDS=	uthash>=0:devel/uthash
LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
		libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		compiler:c11 cmake pkgconfig kde:5 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

USE_KDE=	ecm
USE_XORG=	xcb

CMAKE_ON=	SYSTEM_USE_UTHASH

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
