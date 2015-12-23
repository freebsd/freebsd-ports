# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mygui
PORTVERSION=	3.2.2
DISTVERSIONPREFIX=	MyGUI
CATEGORIES=	x11-toolkits graphics devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast, simple and flexible GUI system for games and 3D applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.MIT

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libOIS.so:${PORTSDIR}/devel/ois

USE_GITHUB=	yes
GH_ACCOUNT=	MyGUI

USES=		cmake:outsource compiler:c++11-lib ninja pkgconfig
CMAKE_ARGS+=	-DMYGUI_BUILD_DEMOS=FALSE \
		-DMYGUI_BUILD_TOOLS=FALSE \
		-DMYGUI_BUILD_DOCS=FALSE \
		-DMYGUI_RENDERSYSTEM=1 # Dummy
USE_LDCONFIG=	yes

USE_CXXSTD=	c++11
CXXFLAGS+=	-fPIC

post-patch:
	@${REINPLACE_CMD} -e '/install/ s|lib/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMake/ConfigureBuild.cmake

.include <bsd.port.mk>
