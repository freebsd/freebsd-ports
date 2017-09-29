# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mygui
PORTVERSION=	3.2.2
DISTVERSIONPREFIX=	MyGUI
PORTREVISION?=	3
CATEGORIES=	x11-toolkits graphics devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT?=	Fast, simple and flexible GUI system for games and 3D applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.MIT

BROKEN_powerpc64=	Does not build

.if !defined(MASTERDIR)
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libOIS.so:devel/ois
.else
LIB_DEPENDS+=	libMyGUIEngine.so:x11-toolkits/mygui

BUILD_WRKSRC=	${WRKSRC}/${MYGUI_SUBDIR}
INSTALL_WRKSRC=	${WRKSRC}/${MYGUI_SUBDIR}
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	MyGUI

MYGUI_RENDERSYSTEM?=	0

USES=		cmake compiler:c++11-lib pkgconfig
CMAKE_ARGS=	-DMYGUI_BUILD_DEMOS=FALSE \
		-DMYGUI_BUILD_TOOLS=FALSE \
		-DMYGUI_BUILD_DOCS=FALSE \
		-DMYGUI_RENDERSYSTEM=${MYGUI_RENDERSYSTEM}
USE_LDCONFIG=	yes

USE_CXXSTD=	c++11
CXXFLAGS+=	-fPIC

PLIST=		${.CURDIR}/pkg-plist

post-patch:
	@${REINPLACE_CMD} -e '/install/ s|lib/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMake/ConfigureBuild.cmake
.if defined(MASTERDIR)
	@${REINPLACE_CMD} -e '/add_dependencies/d' ${BUILD_WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/target_link/d' ${BUILD_WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
