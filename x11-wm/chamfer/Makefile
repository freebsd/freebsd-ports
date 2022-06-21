PORTNAME=	chamfer
DISTVERSION=	s20210622
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tiling X11 window manager with Vulkan compositor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR} \
		spirv-opt:graphics/spirv-tools \
		vulkan-headers>0:graphics/vulkan-headers \
		glslc:graphics/shaderc \
		glm>0:math/glm
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-icccm.so:x11/xcb-util-wm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlib>0:x11-toolkits/py-python-xlib@${PY_FLAVOR}

USES=		compiler:c++17-lang meson localbase pkgconfig python:3.3+ xorg
USE_GITHUB=	yes
USE_XORG=	xcb
GH_ACCOUNT=	jaelpark
GH_PROJECT=	${PORTNAME}wm
GH_TAGNAME=	d0916ee

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' \
		${WRKSRC}/src/config.cpp ${WRKSRC}/src/main.cpp
# XXX import('python').find_installation().dependency()
# XXX https://github.com/mesonbuild/meson/issues/4788
	@${REINPLACE_CMD} -e '/boost/!s/python3/python-${PYTHON_VER}/' \
		-e '/boost/s/python3/python${PYTHON_SUFFIX}/' \
		`if [ ${PYTHON_REL} -lt 30800 ]; then \
			printf "%s %s" -e '/python.*embed/d'; \
		 fi` \
		-e '/boost/s/,/,static:true,/' \
		${WRKSRC}/meson.build

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/shaders
	${INSTALL_DATA} ${INSTALL_WRKSRC}/*.spv \
		${STAGEDIR}${DATADIR}/shaders
	${MKDIR} ${STAGEDIR}${DATADIR}/config
	${INSTALL_DATA} ${WRKSRC}/config/config.py \
		${STAGEDIR}${DATADIR}/config/config.py.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions/
	${INSTALL_DATA} ${WRKSRC}/share/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/xsessions/

.include <bsd.port.mk>
