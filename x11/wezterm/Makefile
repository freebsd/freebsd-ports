PORTNAME=	wezterm
DISTVERSION=	20250730-110715
DISTVERSIONSUFFIX=	-6a493f88
CATEGORIES=	x11 wayland

MAINTAINER=	vladislav.movchan@gmail.com
COMMENT=	GPU-accelerated terminal emulator and multiplexer
WWW=		https://wezterm.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libwayland-egl.so:graphics/wayland \
		libssh2.so:security/libssh2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon-x11.so:x11/libxkbcommon \
		libxcb-util.so:x11/xcb-util \
		libxcb-image.so:x11/xcb-util-image

USES=		cargo ssl xorg
USE_GITHUB=	yes
USE_XORG=	x11 xcb
GH_ACCOUNT=	wez vladmovchan:build_docs_offline
GH_PROJECT=	wezterm freebsd-wezterm-port-extra-files:build_docs_offline
GH_TAGNAME=	6a493f88fab06a792308e0c704790390fd3c6232 0cf07e1:build_docs_offline

GH_TUPLE=	freetype:freetype:42608f77f:freetype2/deps/freetype/freetype2 \
		nyorain:dlg:72dfcc858:dlg/deps/freetype/freetype2/subprojects/dlg \
		glennrp:libpng:f5e92d769:libpng/deps/freetype/libpng \
		madler:zlib:51b7f2abd:zlib/deps/freetype/zlib \
		harfbuzz:harfbuzz:33a3f8de6:harfbuzz/deps/harfbuzz/harfbuzz \
		fcitx:xcb-imdkit:30e2f16:xcb_imdkit/../${WRKSRC_crate_xcb-imdkit:T}/deps/xcb-imdkit

PLIST_FILES=	bin/strip-ansi-escapes \
		bin/wezterm \
		bin/wezterm-gui \
		bin/wezterm-mux-server \
		etc/profile.d/wezterm.sh \
		share/applications/org.wezfurlong.wezterm.desktop \
		share/icons/hicolor/128x128/apps/org.wezfurlong.wezterm.png \
		share/icons/hicolor/scalable/apps/org.wezfurlong.wezterm.svg \
		share/metainfo/org.wezfurlong.wezterm.appdata.xml \
		share/nautilus-python/extensions/wezterm-nautilus.py \
		share/bash-completion/completions/wezterm \
		share/fish/completions/wezterm.fish \
		share/zsh/site-functions/_wezterm

# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	${PLIST_FILES:Mbin/*:T}

CARGO_BUILD_ARGS+=	--features=distro-defaults

.if exists(/usr/bin/tic)
PKGMESSAGE=	${NONEXISTENT}
PLIST_FILES+=	share/site-terminfo/w/wezterm
.endif

OPTIONS_DEFINE=	DOCS

DOCS_USES=		python:build
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocs-material>0:textproc/py-mkdocs-material@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mkdocs-macros-plugin>0:textproc/py-mkdocs-macros-plugin@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mkdocs-include-markdown-plugin>0:textproc/py-mkdocs-include-markdown-plugin@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mkdocs-exclude>0:textproc/py-mkdocs-exclude@${PY_FLAVOR}
PORTDOCS=		html

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

post-patch:
# Extract (snapshot) version from the port instead of .tag file
	@${ECHO_CMD} '${DISTVERSIONFULL}' >${WRKSRC}/.tag
# Respect LOCALBASE for cursors
	@${REINPLACE_CMD} 's,/usr/share,${LOCALBASE}/share,' \
		${WRKSRC}/window/src/os/x11/cursor.rs

do-build-DOCS-on:
# Build HTML documentation similar to ci/build-docs.sh
	(cd ${WRKSRC} && ${PYTHON_CMD} ci/generate-docs.py)
	${REINPLACE_CMD} \
		-e 's,/tmp/wezterm.releases.json,${WRKSRC_build_docs_offline}/wezterm.releases.json,' \
		-e 's,/tmp/wezterm.nightly.json,${WRKSRC_build_docs_offline}/wezterm.nightly.json,' \
		${WRKSRC}/ci/subst-release-info.py
	(cd ${WRKSRC} && ${PYTHON_CMD} ci/subst-release-info.py)
	${CP} ${WRKSRC}/assets/icon/terminal.png ${WRKSRC}/docs/favicon.png
	${CP} ${WRKSRC}/assets/icon/wezterm-icon.svg ${WRKSRC}/docs/favicon.svg
	${MKDIR} ${WRKSRC}/docs/fonts
	${CP} ${WRKSRC}/assets/fonts/SymbolsNerdFontMono-Regular.ttf \
		${WRKSRC}/docs/fonts/
	(cd ${WRKSRC} && mkdocs build)

do-install-DOCS-on:
	(cd ${WRKSRC}/gh_pages && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${PORTDOCS} \
		"! -name *\.orig ! -name sitemap\.xml*")

post-install:
# Install assets similar to ci/deploy.sh
	( cd ${STAGEDIR}${PREFIX} && \
		${MKDIR} \
			./etc/profile.d/ \
			./share/applications/ \
			./share/bash-completion/completions/ \
			./share/fish/completions/ \
			./share/icons/hicolor/128x128/apps/ \
			./share/icons/hicolor/scalable/apps/ \
			./share/metainfo/ \
			./share/nautilus-python/extensions/ \
			./share/zsh/site-functions/ \
	)
	${INSTALL_DATA} ${WRKSRC}/assets/wezterm.desktop \
		${STAGEDIR}${PREFIX}/share/applications/org.wezfurlong.wezterm.desktop
	${INSTALL_DATA} ${WRKSRC}/assets/wezterm.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo/org.wezfurlong.wezterm.appdata.xml
	${INSTALL_DATA} ${WRKSRC}/assets/wezterm-nautilus.py \
		${STAGEDIR}${PREFIX}/share/nautilus-python/extensions/
	${INSTALL_DATA} ${WRKSRC}/assets/icon/terminal.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/org.wezfurlong.wezterm.png
	${INSTALL_DATA} ${WRKSRC}/assets/icon/wezterm-icon.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/org.wezfurlong.wezterm.svg
	${INSTALL_DATA} ${WRKSRC}/assets/shell-integration/wezterm.sh \
		${STAGEDIR}${PREFIX}/etc/profile.d/
	${INSTALL_DATA} ${WRKSRC}/assets/shell-completion/bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/wezterm
	${INSTALL_DATA} ${WRKSRC}/assets/shell-completion/fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/wezterm.fish
	${INSTALL_DATA} ${WRKSRC}/assets/shell-completion/zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_wezterm
.if exists(/usr/bin/tic)
	tic -x -o ${STAGEDIR}${PREFIX}/share/site-terminfo \
		${WRKSRC}/termwiz/data/wezterm.terminfo
.endif

.include <bsd.port.post.mk>
