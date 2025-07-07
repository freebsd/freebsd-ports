PORTNAME=	mygui
DISTVERSIONPREFIX=	MyGUI
DISTVERSION=	3.4.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits graphics devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT?=	Fast, simple and flexible GUI system for games and 3D applications
WWW=		http://mygui.info/ \
		https://github.com/MyGUI/mygui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.MIT

.if !defined(MASTERDIR)
LIB_DEPENDS=	libfreetype.so:print/freetype2
.else
LIB_DEPENDS+=	libMyGUIEngine.so:x11-toolkits/mygui

BUILD_WRKSRC=	${WRKSRC}/${MYGUI_SUBDIR}
INSTALL_WRKSRC=	${WRKSRC}/${MYGUI_SUBDIR}
.endif

USES+=		cmake:insource compiler:c++11-lib pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	MyGUI
CMAKE_ON=	MYGUI_DONT_USE_OBSOLETE
CMAKE_OFF=	MYGUI_BUILD_DEMOS MYGUI_BUILD_TOOLS MYGUI_BUILD_DOCS
USE_LDCONFIG=	yes

MYGUI_RENDERSYSTEM?=	0

CMAKE_ARGS=	-DMYGUI_RENDERSYSTEM=${MYGUI_RENDERSYSTEM}

PLIST=		${.CURDIR}/pkg-plist

.include <bsd.port.mk>
