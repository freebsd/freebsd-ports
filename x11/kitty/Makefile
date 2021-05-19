PORTNAME=	kitty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.3
CATEGORIES=	x11

MAINTAINER=	alexis.praga@free.fr
COMMENT=	Cross-platform, fast, featureful, GPU-based terminal emulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR} \
		wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libwayland-client.so:graphics/wayland \
		libwayland-cursor.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		gettext-runtime gl gmake ncurses:port pkgconfig python:3.5+ \
		shebangfix terminfo xorg
USE_GITHUB=	yes
GH_ACCOUNT=	kovidgoyal
USE_GL=		gl
USE_XORG=	x11 xcb xcursor xi xinerama xrandr

SHEBANG_FILES=	build-terminfo count-lines-of-code mypy-editor-integration \
		update-on-ox update-on-ubuntu
SHEBANG_GLOB=	*.py

TEST_ENV=	PATH="${STAGEDIR}${PREFIX}/bin:${PATH}"
TEST_TARGET=	test

.if exists(/usr/bin/ld.lld) && ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
# --build-id isn't supported by old GNU ld.bfd in base
LDFLAGS+=	-fuse-ld=lld
.endif

BINARY_ALIAS=	python3=${PYTHON_CMD} python=${PYTHON_CMD}

INSTALL_WRKSRC=	${WRKSRC}/linux-package

_STRIP_TARGETS=	lib/kitty/kitty/fast_data_types.so lib/kitty/kitty/glfw-x11.so \
		lib/kitty/kittens/diff/diff_speedup.so \
		lib/kitty/kittens/unicode_input/unicode_names.so \
		lib/kitty/kitty/glfw-wayland.so \
		lib/kitty/kittens/choose/subseq_matcher.so bin/kitty
_EMPTY_DIRS=	kittens/choose kittens/diff kittens/unicode_input kittens kitty

do-build:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py linux-package --update-check-interval 0)
	${FIND} ${INSTALL_WRKSRC} -name __pycache__ -type d -exec ${RM} -r -- {} +

do-install:
	${CP} -a ${INSTALL_WRKSRC}/ ${STAGEDIR}${PREFIX}
	${STRIP_CMD} ${_STRIP_TARGETS:S|^|${STAGEDIR}${PREFIX}/|}
	${INSTALL_DATA} ${WRKSRC}/terminfo/kitty.terminfo \
		${STAGEDIR}${PREFIX}/share/misc/

.include <bsd.port.mk>
