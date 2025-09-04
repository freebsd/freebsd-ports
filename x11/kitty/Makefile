PORTNAME=	kitty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.42.1
PORTREVISION=	3
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
		nerd-fonts>=3.1.1:x11-fonts/nerd-fonts \
		roboto-fonts-ttf>=2.134:x11-fonts/roboto-fonts-ttf \
		simde>=0.7.6:devel/simde \
		sphinx-build:textproc/py-sphinx@${PY_FLAVOR} \
		urw-base35-fonts>=20200910:x11-fonts/urw-base35-fonts \
		wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libcanberra.so:audio/libcanberra \
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
		go:1.24,modules magick pkgconfig python shebangfix ssl tar:xz \
		terminfo xorg
CPE_VENDOR=	kitty_project

USE_GL=		gl
USE_XORG=	x11 xcb xcursor xi xinerama xrandr

SHEBANG_FILES=	build-terminfo count-lines-of-code update-on-ox
SHEBANG_GLOB=	*.py

GO_MODULE=	github.com/kovidgoyal/kitty

MAKE_ENV=	PYTHONDONTWRITEBYTECODE=1
TEST_ENV=	PATH="${STAGEDIR}${PREFIX}/bin:${PATH}"
TEST_TARGET=	test

CPPFLAGS+=	`pkg-config --cflags epoll-shim-interpose`
LDFLAGS+=	`pkg-config --libs epoll-shim-interpose`

PIE_UNSAFE=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD} python=${PYTHON_CMD}

BUILD_DIR=	${WRKSRC}/${OPSYS:tl}-package

INSTALL_WRKSRC=	${WRKSRC}/linux-package

_STRIP_TARGETS=	kitty/fast_data_types.so kitty/glfw-x11.so \
		kitty/glfw-wayland.so kittens/transfer/rsync.so

_EMPTY_DIRS=	kittens/choose kittens/diff kittens/unicode_input kittens kitty

OPTIONS_DEFINE=	DOCS
DOCS_MAKE_ENV=	BUILD_DOCS=yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
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
	${REINPLACE_CMD} -E \
		-e "s:'go':'${GO_CMD}':1" \
		-e "s:(dirs_exist_ok=True):\1, ignore=shutil.ignore_patterns('*.orig', '*.bak'):1" \
		${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:1" \
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
	${STRIP_CMD} ${_STRIP_TARGETS:S|^|${STAGEDIR}${DATADIR}/|}
	${INSTALL_MAN} ${BUILD_DIR}/share/man/man1/kitty.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${BUILD_DIR}/share/man/man5/kitty.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5

do-install-DOCS-on:
	cd ${BUILD_DIR}/share/doc/kitty/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"-not ( -name .buildinfo -or -name .nojekyll )"

.include <bsd.port.mk>
