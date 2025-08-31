PORTNAME=	kivy
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Kivy-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Python NUI library for rapid application development
WWW=		https://kivy.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
LIB_DEPENDS=	libmtdev.so:devel/libmtdev
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR}

MAKE_ENV=	KIVY_NO_CONFIG=yes KIVY_NO_FILELOG=yes USE_OPENGL_ES2=1 \
		PYTHONPATH=${WRKSRC}

USES=		display:test gl pytest python shebangfix uniquefiles:dirs
USE_GL=		egl gl glesv2
USE_PYTHON=	autoplist concurrent cython distutils
PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS=		--inplace
PYDISTUTILS_EGGINFO=		Kivy-${PORTVERSION}-py${PYTHON_VER}.egg-info
SHEBANG_FILES=	kivy/tools/pep8checker/pre-commit.githook

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	ENCHANT OPENCV PYGAME
OPTIONS_SUB=	yes
OPTIONS_GROUP=	VIDEO AUDIO IMAGE CAMERA SPELLING CLIPBOARD
OPTIONS_MULTI=	WINDOW TEXT
OPTIONS_MULTI_WINDOW=	PYGAME X11 SDL2
OPTIONS_MULTI_TEXT=	PIL PYGAME SDL2
OPTIONS_GROUP_VIDEO=	${_OPTIONS_GROUP_VIDEO_${ARCH}} GSTREAMER
_OPTIONS_GROUP_VIDEO_i386=	PYGLET
OPTIONS_GROUP_AUDIO=	GSTREAMER PYGAME SDL2
OPTIONS_GROUP_IMAGE=	PIL PYGAME SDL2
OPTIONS_GROUP_CAMERA=	OPENCV GSTREAMER
OPTIONS_GROUP_SPELLING=	ENCHANT
OPTIONS_GROUP_CLIPBOARD=	PYGAME

CAMERA_DESC=	Camera support
CLIPBOARD_DESC=	Clipboard support
IMAGE_DESC=	Image support
SPELLING_DESC=	Spell checking support
TEXT_DESC=	Text rendering support (compulsory)
WINDOW_DESC=	Window support (compulsory)

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinxcontrib-jquery>0:textproc/py-sphinxcontrib-jquery@${PY_FLAVOR}
ENCHANT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>0:textproc/py-enchant@${PY_FLAVOR}
GSTREAMER_MAKE_ENV=	USE_GSTREAMER=1
GSTREAMER_MAKE_ENV_OFF=	USE_GSTREAMER=0
GSTREAMER_LIB_DEPENDS=	libgstreamer-1.0.so:multimedia/gstreamer1
GSTREAMER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer1>0:multimedia/py-gstreamer1@${PY_FLAVOR}
GSTREAMER_USES=		gettext-runtime gnome pkgconfig
GSTREAMER_USE=		GNOME=glib20
OPENCV_RUN_DEPENDS=	opencv>0:graphics/opencv
PIL_DESC=		Text and window rendering support via Pillow
PIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}
PYGAME_DESC=		Window, text and image rendering support via PyGame
PYGAME_RUN_DEPENDS=	${PYGAME}
PYGLET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyglet>0:graphics/py-pyglet@${PY_FLAVOR}
SDL2_DESC=		Simple Direct Media Layer v2.0 support
SDL2_MAKE_ENV=		USE_SDL2=1
SDL2_MAKE_ENV_OFF=	USE_SDL2=0
SDL2_USE=		SDL=sdl2,mixer2,image2,ttf2
SDL2_USES=		pkgconfig sdl
X11_MAKE_ENV=		USE_X11=1
X11_MAKE_ENV_OFF=	USE_X11=0
X11_USES=		xorg
X11_USE=		XORG=xrender,x11

post-patch:
	@${REINPLACE_CMD} -e '/GLSHADERSOURCEPTR/s,const GLchar\*,& const ,' \
		${WRKSRC}/kivy/graphics/cgl.pxd
	@${REINPLACE_CMD} -e '/glShaderSource/s,const GLchar\*,& const ,' \
		${WRKSRC}/kivy/graphics/cgl.pxd \
		${WRKSRC}/kivy/graphics/cgl_backend/cgl_gl.pyx \
		${WRKSRC}/kivy/include/common_subset.h
	@${REINPLACE_CMD} -e '/mockShaderSource/s,const GLchar\*,& const,' \
		${WRKSRC}/kivy/graphics/cgl_backend/cgl_mock.pyx
	@${REINPLACE_CMD} -e '/dbgShaderSource/s,const GLchar\*,& const,' \
		${WRKSRC}/kivy/graphics/cgl_backend/cgl_debug.pyx \

post-build-DOCS-on:
	${MKDIR} ${WRKSRC}/doc/build/doctrees ${WRKSRC}/doc/build/html
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} doc/autobuild.py)
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} sphinx-build-${PYTHON_VER} -b html \
			-d ${WRKSRC}/doc/build/doctrees \
			doc/sources ${WRKSRC}/doc/build/html)

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/kivy -name '*.so' | ${XARGS} ${STRIP_CMD}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/build/html; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
