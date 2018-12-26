# $FreeBSD$

PORTNAME=	nanogui
DISTVERSION=	g20180413
PORTREVISION=	2
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimalistic GUI library for OpenGL

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libglfw.so:graphics/glfw

USES=		cmake compiler:c++14-lang eigen:3,build,run
USE_GITHUB=	yes
GH_ACCOUNT=	wjakob
GH_TAGNAME=	885e4fc
GH_TUPLE=	wjakob:nanovg:ab38df8:nanovg/ext/nanovg
USE_GL=		gl
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm
USE_LDCONFIG=	yes
CMAKE_OFF=	NANOGUI_BUILD_EXAMPLE GLFW_BUILD_EXAMPLES

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=	yes

PYTHON_CMAKE_BOOL=	NANOGUI_BUILD_PYTHON
PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	${LOCALBASE}/include/pybind11/pybind11.h:devel/pybind11
PYTHON_RUN_DEPENDS=	pybind11>0:devel/pybind11

post-install:
	${INSTALL_DATA} ${WRKSRC}/ext/nanovg/src/*.h ${STAGEDIR}${PREFIX}/include/nanogui/  # bundled dependency headers aren't installed

post-install-PYTHON-on:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${MV} ${STAGEDIR}${PREFIX}/lib/nanogui.so ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
