PORTNAME=	kitty
DISTVERSION=	0.28.0
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	x11 wayland

MAINTAINER=	alexis.praga@proton.me
COMMENT=	Cross-platform, fast, featureful, GPU-based terminal emulator
WWW=		https://sw.kovidgoyal.net/kitty/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}furo>0:textproc/py-furo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-copybutton>0:textproc/py-sphinx-copybutton@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-inline-tabs>0:textproc/py-sphinx-inline-tabs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxext-opengraph>0:textproc/py-sphinxext-opengraph@${PY_FLAVOR} \
		sphinx-build:textproc/py-sphinx@${PY_FLAVOR} \
		wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libepoll-shim-interpose.so:devel/libepoll-shim \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		librsync.so:net/librsync \
		libwayland-client.so:graphics/wayland \
		libwayland-cursor.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 cpe desktop-file-utils gettext-runtime gl gmake \
		go:modules pkgconfig python:3.5+ shebangfix ssl tar:xz terminfo xorg
CPE_VENDOR=	kitty_project
USE_GL=		gl
USE_XORG=	x11 xcb xcursor xi xinerama xrandr

GO_MODULE=	github.com/kovidgoyal/kitty
SHEBANG_FILES=	build-terminfo count-lines-of-code mypy-editor-integration \
		update-on-ox update-on-ubuntu
SHEBANG_GLOB=	*.py

TEST_ENV=	PATH="${STAGEDIR}${PREFIX}/bin:${PATH}"
TEST_TARGET=	test

CPPFLAGS+=	`pkg-config --cflags epoll-shim-interpose`
LDFLAGS+=	`pkg-config --libs epoll-shim-interpose`

BINARY_ALIAS=	python3=${PYTHON_CMD} python=${PYTHON_CMD}

GH_TUPLE=	\
		ALTree:bigfloat:38c8b72a9924:altree_bigfloat/vendor/github.com/ALTree/bigfloat \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		golang:exp:54bba9f4231b:golang_exp/vendor/golang.org/x/exp \
		golang:image:v0.3.0:golang_image/vendor/golang.org/x/image \
		golang:sys:v0.4.0:golang_sys/vendor/golang.org/x/sys \
		google:go-cmp:v0.5.8:google_go_cmp/vendor/github.com/google/go-cmp \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		jamesruan:go-rfc1924:2767ca7c638f:jamesruan_go_rfc1924/vendor/github.com/jamesruan/go-rfc1924 \
		seancfoley:bintree:v1.2.1:seancfoley_bintree/vendor/github.com/seancfoley/bintree \
		seancfoley:ipaddress-go:v1.5.3:seancfoley_ipaddress_go/vendor/github.com/seancfoley/ipaddress-go

INSTALL_WRKSRC=	${WRKSRC}/linux-package

_STRIP_TARGETS=	lib/kitty/kitty/fast_data_types.so lib/kitty/kitty/glfw-x11.so \
		lib/kitty/kittens/diff/diff_speedup.so \
		lib/kitty/kittens/unicode_input/unicode_names.so \
		lib/kitty/kitty/glfw-wayland.so \
		bin/kitten bin/kitty \
		lib/kitty/kittens/transfer/rsync.so

_EMPTY_DIRS=	kittens/choose kittens/diff kittens/unicode_input kittens kitty

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
CFLAGS+=	-Wno-error=invalid-utf8 -Winvalid-utf8
.endif

.if ${ARCH} == powerpc64 || ${ARCH:Mriscv64*}
MAKE_ENV+=	KITTY_NO_LTO=1
.endif

# ncursesw and tinfo >= 6.1 seem to be neededd
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400035
USES+=		ncurses:port
.else
USES+=		ncurses
.endif

# fix clang static_assert on 12.x releases, https://github.com/kovidgoyal/kitty/pull/5398
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-kitty_data-types.h
.endif

# For librsync, we need to set header and library path
do-build:
	(cd ${WRKSRC} && \
	        ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py linux-package --update-check-interval 0 --extra-include-dirs ${LOCALBASE}/include/ --extra-library-dirs ${LOCALBASE}/lib)
	${FIND} ${INSTALL_WRKSRC} -name __pycache__ -type d -exec ${RM} -r -- {} +

do-install:
	${CP} -a ${INSTALL_WRKSRC}/ ${STAGEDIR}${PREFIX}
	${STRIP_CMD} ${_STRIP_TARGETS:S|^|${STAGEDIR}${PREFIX}/|}
	${INSTALL_DATA} ${WRKSRC}/terminfo/kitty.terminfo \
		${STAGEDIR}${PREFIX}/share/misc/

.include <bsd.port.mk>
