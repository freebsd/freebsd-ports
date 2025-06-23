PORTNAME=	chamfer
DISTVERSION=	s20240928
PORTREVISION=	2
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tiling X11 window manager and Vulkan compositor
WWW=		https://jaelpark.github.io/chamferwm-docs/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR} \
		${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm \
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
		${PYTHON_PKGNAMEPREFIX}python-xlib>0:x11-toolkits/py-python-xlib@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++17-lang meson localbase \
		pkgconfig python xorg
USE_GITHUB=	yes
USE_XORG=	xcb
GH_ACCOUNT=	jaelpark
GH_PROJECT=	${PORTNAME}wm
GH_TAGNAME=	b5bc725

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' \
		${WRKSRC}/src/config.cpp ${WRKSRC}/src/main.cpp
# XXX import('python').find_installation().dependency()
	@${REINPLACE_CMD} -e '/boost/!s/python3/python-${PYTHON_VER}/' \
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
