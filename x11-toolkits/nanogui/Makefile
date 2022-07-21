PORTNAME=	nanogui
DISTVERSION=	g20220215
PORTREVISION=	1
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimalistic GUI library for OpenGL

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_riscv64=	ld: error: lto.tmp: cannot link object files with different floating-point ABI

LIB_DEPENDS=	libglfw.so:graphics/glfw
TEST_DEPENDS=	zenity:x11/zenity

USES=		cmake compiler:c++17-lang gl xorg
USE_GL=		gl
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mitsuba-renderer
GH_TAGNAME=	c6505300bb3036ec87ac68f5f1699c434c3d7fc6
GH_TUPLE=	wjakob:nanovg:bf2320d1175122374a9b806d91e9e666c9336375:wjakob_nanovg/ext/nanovg \
		wjakob:nanovg_metal:075b04f16c579728c693b46a2ce408f2325968cf:wjakob_nanovg_metal/ext/nanovg_metal \
		wjakob:glfw:e130e55a990998c78fd323f21076e798e0efe8a4:wjakob_glfw/ext/glfw \
		pybind:pybind11:8de7772cc72daca8e947b79b83fea46214931604:pybind_pybind11/ext/pybind11 \

CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR=${LOCALBASE}/include \
		-DCMAKE_INSTALL_DATAROOTDIR=${LOCALBASE}/lib
CMAKE_OFF=	NANOGUI_BUILD_GLFW NANOGUI_BUILD_EXAMPLES

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	NANOGUI_BUILD_PYTHON
PYTHON_CMAKE_ON=	-DFREEBSD_PYTHON_DISTVERSION=${PYTHON_DISTVERSION}

post-install-PYTHON-on:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nanogui
	${INSTALL_DATA} ${WRKSRC}/nanogui/__init__.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nanogui
	${MV} ${STAGEDIR}${PREFIX}/lib/nanogui*.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nanogui

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DNANOGUI_BUILD_EXAMPLES:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		./example1 && ./example2 && ./example3 && ./example4 && ./example_icons

.include <bsd.port.mk>
