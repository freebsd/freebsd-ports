# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kivy
PORTVERSION=	1.7.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	LOCAL/dbn/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Python NUI library for rapid application development

LICENSE=	MIT

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython

MAKE_ENV=	KIVY_NO_CONFIG=yes KIVY_NO_FILELOG=yes PYTHONPATH=${WRKSRC}
MAKE_JOBS_UNSAFE=	yes  # does not (really) use make
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_COMMIT=	f4f6246
USES=		shebangfix
USE_GL=		gl
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS=	--inplace
PYDISTUTILS_EGGINFO=	Kivy-${PORTVERSION}-py${PYTHON_VER}.egg-info
USE_PYTHON=	2
SHEBANG_FILES=	kivy/lib/osc/OSC.py

OPTIONS_DEFINE=	DOCS PDF TEST
OPTIONS_SET=	ENCHANT OPENCV PYGAME
OPTIONS_SUB=	yes
OPTIONS_GROUP=	VIDEO AUDIO IMAGE CAMERA SPELLING CLIPBOARD
OPTIONS_MULTI=	WINDOW TEXT
OPTIONS_MULTI_WINDOW=	PYGAME X11  SDL2
OPTIONS_MULTI_TEXT=	PIL PYGAME SDL2
OPTIONS_GROUP_VIDEO=	GSTREAMER FFMPEG
OPTIONS_GROUP_AUDIO=	GSTREAMER PYGAME SDL2
OPTIONS_GROUP_IMAGE=	PIL PYGAME
OPTIONS_GROUP_CAMERA=	OPENCV GSTREAMER
OPTIONS_GROUP_SPELLING=	ENCHANT
OPTIONS_GROUP_CLIPBOARD=	PYGAME

.if !defined(ARCH)
ARCH!=		uname -p
.endif
.if ${ARCH} == i386
OPTIONS_GROUP_VIDEO+=	PYGLET
.if !defined(WITH_NEW_XORG)
BROKEN=		Does not compile with old libGL on i386: Undefined symbol glBlendEquationSeparate
.endif
.endif

CAMERA_DESC=	Camera support
CLIPBOARD_DESC=	Clipboard support
IMAGE_DESC=	Image support
SPELLING_DESC=	Spell checking support
TEXT_DESC=	Text rendering support (compulsory)
WINDOW_DESC=	Window support (compulsory)

DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
ENCHANT_DESC=		Spell checking support via Enchant
ENCHANT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>=0:${PORTSDIR}/textproc/py-enchant
FFMPEG_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ffmpeg/__init__.py:${PORTSDIR}/multimedia/py-ffmpeg
GSTREAMER_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygst.py:${PORTSDIR}/multimedia/py-gstreamer
OPENCV_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cv.py:${PORTSDIR}/graphics/py-opencv
PDF_DESC=		Build PDF documentation (required TeXLive, DOCS)
PDF_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
PDF_USE=		TEX=texlive,pdftex:build,dvipsk:build
PDF_USES=		gmake
PIL_DESC=		Text and window rendering support via PIL
PIL_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL:${PORTSDIR}/graphics/py-imaging
PYGAME_DESC=		Window, text and image rendering support via PyGame
PYGAME_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame:${PORTSDIR}/devel/py-game
PYGLET_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyglet:${PORTSDIR}/graphics/py-pyglet
SDL2_DESC=		Simple Direct Media Layer v2.0 support
SDL2_MAKE_ENV=		USE_SDL=1
SDL2_USE=		SDL=sdl2,ttf2,mixer2
TEST_BUILD_DEPENDS=	nosetests:${PORTSDIR}/devel/py-nose
TEST_USES=		display:build
X11_MAKE_ENV=		USE_X11=1
X11_USE=		XORG=x11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPDF}
.if empty(PORT_OPTIONS:MDOCS)
IGNORE=		option PDF requires DOCS
.endif
.endif

.if empty(PORT_OPTIONS:MPYGAME)
NOSE_ARGS+=	--exclude=test_fbo_pixels
.endif

.if ${PORT_OPTIONS:MTEST}

post-build: do-test-build

do-test-build:
	@${RM} -rf kivy/tests/build
	@(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} nosetests ${NOSE_ARGS} ${WRKSRC}/kivy/tests)

.endif

.if ${PORT_OPTIONS:MDOCS}

post-build: do-build-docs
	find ${WKRSRC} -name '*.so' | ${XARGS} ${STRIP_CMD}

do-build-docs:
	${MKDIR} ${WRKSRC}/doc/build/doctrees ${WRKSRC}/doc/build/html \
		${WRKSRC}/doc/build/latex-a4 ${WRKSRC}/doc/build/latex-letter
	${REINPLACE_CMD} -i '' -e 's/\(import pygame\.joystick\)/#\1/' \
		${WRKSRC}/kivy/input/providers/androidjoystick.py
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} doc/autobuild.py)
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} sphinx-build -b html \
			-d ${WRKSRC}/doc/build/doctrees \
			doc/sources ${WRKSRC}/doc/build/html)
.if ${PORT_OPTIONS:MPDF}
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} sphinx-build -b latex \
			-d ${WRKSRC}/doc/build/doctrees \
			-D latex_paper=a4 doc/sources ${WRKSRC}/doc/build/latex-a4)
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} sphinx-build -b latex \
			-d ${WRKSRC}/doc/build/doctrees \
			-D latex_paper=letter doc/sources ${WRKSRC}/doc/build/latex-letter)
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/doc/build/latex-a4 \
		all-pdf > /dev/null
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/doc/build/latex-letter \
		all-pdf > /dev/null
.endif
	${REINPLACE_CMD} -i '' -e 's/#\(import pygame\.joystick\)/\1/' \
		${WRKSRC}/kivy/input/providers/androidjoystick.py

post-install: do-install-docs

do-install-docs:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/build/html; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.if ${PORT_OPTIONS:MPDF}
	${INSTALL_DATA} ${WRKSRC}/doc/build/latex-a4/Kivy.pdf \
		${STAGEDIR}${DOCSDIR}/Kivy-a4.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/build/latex-letter/Kivy.pdf \
		${STAGEDIR}${DOCSDIR}/Kivy-letter.pdf
.endif
.endif

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/kivy -name '*.so' | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
