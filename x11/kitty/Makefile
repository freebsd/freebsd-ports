PORTNAME=	kitty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31.0
PORTREVISION=	2
CATEGORIES=	x11 wayland

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Cross-platform, fast, featureful, GPU-based terminal emulator
WWW=		https://sw.kovidgoyal.net/kitty/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}furo>0:textproc/py-furo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-copybutton>0:textproc/py-sphinx-copybutton@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-inline-tabs>0:textproc/py-sphinx-inline-tabs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxext-opengraph>0:textproc/py-sphinxext-opengraph@${PY_FLAVOR} \
		roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf \
		sphinx-build:textproc/py-sphinx@${PY_FLAVOR} \
		wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libdbus-1.so:devel/dbus \
		libepoll-shim-interpose.so:devel/libepoll-shim \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		librsync.so:net/librsync \
		libwayland-client.so:graphics/wayland \
		libwayland-cursor.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libxxhash.so:devel/xxhash

USES=		compiler:c11 cpe desktop-file-utils gettext-runtime gl gmake \
		go:1.21,modules magick pkgconfig python shebangfix ssl tar:xz \
		terminfo xorg
CPE_VENDOR=	kitty_project
GH_TUPLE=	ALTree:bigfloat:38c8b72a9924:altree_bigfloat/vendor/github.com/ALTree/bigfloat \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		golang:exp:54bba9f4231b:golang_exp/vendor/golang.org/x/exp \
		golang:image:v0.3.0:golang_image/vendor/golang.org/x/image \
		golang:sys:v0.4.0:golang_sys/vendor/golang.org/x/sys \
		google:go-cmp:v0.5.8:google_go_cmp/vendor/github.com/google/go-cmp \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		jamesruan:go-rfc1924:2767ca7c638f:jamesruan_go_rfc1924/vendor/github.com/jamesruan/go-rfc1924 \
		seancfoley:bintree:v1.2.1:seancfoley_bintree/vendor/github.com/seancfoley/bintree \
		seancfoley:ipaddress-go:v1.5.3:seancfoley_ipaddress_go/vendor/github.com/seancfoley/ipaddress-go

USE_GL=		gl
USE_XORG=	x11 xcb xcursor xi xinerama xrandr

SHEBANG_FILES=	build-terminfo count-lines-of-code mypy-editor-integration \
		update-on-ox
SHEBANG_GLOB=	*.py

GO_MODULE=	github.com/kovidgoyal/kitty

MAKE_ENV=	PYTHONDONTWRITEBYTECODE=1
TEST_ENV=	PATH="${STAGEDIR}${PREFIX}/bin:${PATH}"
TEST_TARGET=	test

CPPFLAGS+=	`pkg-config --cflags epoll-shim-interpose`
LDFLAGS+=	`pkg-config --libs epoll-shim-interpose`

BINARY_ALIAS=	python3=${PYTHON_CMD} python=${PYTHON_CMD}

BUILD_DIR=	${WRKSRC}/${OPSYS:tl}-package

INSTALL_WRKSRC=	${WRKSRC}/linux-package

_STRIP_TARGETS=	kitty/fast_data_types.so kitty/glfw-x11.so \
		kitty/glfw-wayland.so kittens/transfer/rsync.so

_EMPTY_DIRS=	kittens/choose kittens/diff kittens/unicode_input kittens kitty

OPTIONS_DEFINE=	DOCS
DOCS_MAKE_ENV=	BUILD_DOCS=yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1400079 || (${OSVERSION} >= 1302505 && \
	${OSVERSION} < 1400000))
CFLAGS+=	-Wno-error=invalid-utf8 -Winvalid-utf8
.endif

.if ${ARCH:Mriscv64*}
MAKE_ENV+=	KITTY_NO_LTO=1
.endif

# ncursesw and tinfo >= 6.1 seem to be neededd
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400035
USES+=		ncurses:port
.else
USES+=		ncurses
.endif

post-patch:
	${REINPLACE_CMD} -i.bak -e "s:'go':'${GO_CMD}':1" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -i.bak -e "s:%%DATADIR%%:${DATADIR}:1" \
		${WRKSRC}/shell-integration/fish/vendor_conf.d/kitty-shell-integration.fish

# For librsync, we need to set header and library path
do-build:
	(cd ${WRKSRC} && \
	        ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} -OO setup.py \
			--extra-include-dirs ${LOCALBASE}/include \
			--extra-library-dirs ${LOCALBASE}/lib \
			--libdir-name share \
			--prefix ${BUILD_DIR:T} \
			--update-check-interval 0 \
			linux-package)

do-install:
	cd ${BUILD_DIR} && \
		${INSTALL_PROGRAM} bin/kitty bin/kitten ${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_DATA} share/applications/* ${STAGEDIR}${DESKTOPDIR} && \
	cd ${BUILD_DIR}/share/icons/hicolor && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/hicolor
	cd ${BUILD_DIR}/share/kitty && \
	       	${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/terminfo/kitty.terminfo \
		${STAGEDIR}${PREFIX}/share/misc/
	${INSTALL_MAN} ${BUILD_DIR}/share/man/man1/kitty.1 ${STAGEDIR}${MANPREFIX}/share/man/man1
	${INSTALL_MAN} ${BUILD_DIR}/share/man/man5/kitty.conf.5 ${STAGEDIR}${MANPREFIX}/share/man/man5
	${STRIP_CMD} ${_STRIP_TARGETS:S|^|${STAGEDIR}${DATADIR}/|}

do-install-DOCS-on:
	cd ${BUILD_DIR}/share/doc/kitty/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
