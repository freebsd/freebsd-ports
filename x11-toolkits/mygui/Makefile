# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mygui
PORTVERSION=	3.2.1.svn20140422
PORTREVISION=	1
CATEGORIES=	x11-toolkits graphics devel
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
#		SF/my-gui/MyGUI/MyGUI_${PORTVERSION}
DISTNAME=	MyGUI_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast, simple and flexible GUI system for Ogre engine

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		libOIS.so:${PORTSDIR}/devel/ois

USES=		cmake pkgconfig zip dos2unix compiler:c++11-lib
CMAKE_ARGS=	-DMYGUI_BUILD_DEMOS=OFF -DMYGUI_BUILD_DOCS=OFF
USE_LDCONFIG=	yes
DOS2UNIX_GLOB=	*.cpp *.h *.cmake

USE_CXXSTD=	c++11
CXXFLAGS+=	-fPIC

post-patch:
	@${REINPLACE_CMD} -e '/install/ s|lib/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMake/ConfigureBuild.cmake

.include <bsd.port.mk>
