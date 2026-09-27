PORTNAME=	nanogui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimalistic GUI library for OpenGL
WWW=		https://github.com/mitsuba-renderer/nanogui

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_riscv64=	ld: error: lto.tmp: cannot link object files with different floating-point ABI

LIB_DEPENDS=	\
		libdbus-1.so:devel/dbus
TEST_DEPENDS=	zenity:x11/zenity

USES=		cmake compiler:c++17-lang gl pkgconfig xorg
USE_GL=		gl
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mitsuba-renderer
GH_TUPLE=	wjakob:nanovg:0319c43:wjakob_nanovg/ext/nanovg \
		wjakob:nanovg_metal:1e42439:wjakob_nanovg_metal/ext/nanovg_metal \
		wjakob:glfw:22fc9e2:wjakob_glfw/ext/glfw \
		wjakob:nanobind:1bd3139:nanobind/ext/nanobind \
			Tessil:robin-map:4ec1bf1:nanobind_robin_map/ext/nanobind/ext/robin_map \
		mitsuba-renderer:nativefiledialog-extended:bd3d51b:nativefiledialog_extended/ext/nativefiledialog-extended

CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR=${LOCALBASE}/include \
		-DCMAKE_INSTALL_DATAROOTDIR=${LOCALBASE}/lib
CMAKE_ON=	NANOGUI_BUILD_GLFW
CMAKE_OFF=	NANOBIND_GENERATE_STUBS \
		NANOGUI_BUILD_EXAMPLES \
		NFD_WAYLAND \
		NB_SPLIT_MODE \
		GLFW_BUILD_WAYLAND

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	#PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	NANOGUI_BUILD_PYTHON
PYTHON_CMAKE_ON=	-DFREEBSD_PYTHON_DISTVERSION=${PYTHON_DISTVERSION}
PYTHON_BROKEN=		NANOGUI_BUILD_GLFW=ON required by the Python option installs conflicting headers, see https://github.com/mitsuba-renderer/nanogui/issues/197

CONFLICTS=	glfw # see https://github.com/mitsuba-renderer/nanogui/issues/197 (build picks up the system glfw headers instead of the bundled ones, then nanogui installs conflicting headers)

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
