PORTNAME=	wezterm
DISTVERSION=	20240203-110809-5046fc22
PORTREVISION=	2
CATEGORIES=	x11 wayland

MAINTAINER=	vladislav.movchan@gmail.com
COMMENT=	GPU-accelerated terminal emulator and multiplexer
WWW=		https://wezfurlong.org/wezterm/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libwayland-egl.so:graphics/wayland \
		libssh2.so:security/libssh2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon-x11.so:x11/libxkbcommon \
		libxcb-util.so:x11/xcb-util \
		libxcb-image.so:x11/xcb-util-image

USES=		cargo desktop-file-utils ssl xorg
USE_GITHUB=	yes
USE_GITLAB=	nodefault
USE_XORG=	x11 xcb
GH_ACCOUNT=	wez
GH_TUPLE=	harfbuzz:harfbuzz:63973005b:harfbuzz/deps/harfbuzz/harfbuzz \
		glennrp:libpng:v1.6.36-805-g8439534da:libpng/deps/freetype/libpng \
		madler:zlib:v1.2.11:zlib/deps/freetype/zlib \
		fcitx:xcb-imdkit:1.0.3:xcb_imdkit/../${WRKSRC_crate_xcb-imdkit:T}/deps/xcb-imdkit \
		freetype:freetype:e4586d960:freetype2/deps/freetype/freetype2
PLIST_FILES=	bin/strip-ansi-escapes \
		bin/${PORTNAME} \
		bin/${PORTNAME}-gui \
		bin/${PORTNAME}-mux-server \
		etc/profile.d/${PORTNAME}.sh \
		share/applications/org.wezfurlong.wezterm.desktop \
		share/icons/hicolor/128x128/apps/org.wezfurlong.wezterm.png \
		share/icons/hicolor/scalable/apps/org.wezfurlong.wezterm.svg \
		share/metainfo/org.wezfurlong.wezterm.appdata.xml \
		share/nautilus-python/extensions/${PORTNAME}-nautilus.py \
		${NULL}

# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	${PLIST_FILES:Mbin/*:T}

.if exists(/usr/bin/tic)
PKGMESSAGE=	${NONEXISTENT}
PLIST_FILES+=	share/site-terminfo/${PORTNAME:C,^.,&/&,}
.endif

OPTIONS_DEFINE=	DOCS

DOCS_USES=		python:build
DOCS_BUILD_DEPENDS=	mdbook:textproc/mdbook \
			mdbook-linkcheck:textproc/mdbook-linkcheck \
			mdbook-mermaid:textproc/mdbook-mermaid
PORTDOCS=		html

post-patch:
# Extract (snapshot) version from the port instead of .tag file
	@${ECHO_CMD} '${DISTVERSIONFULL}' >${WRKSRC}/.tag
# Respect LOCALBASE for cursors
	@${REINPLACE_CMD} 's,/usr/share,${LOCALBASE}/share,' \
		${WRKSRC}/window/src/os/x11/cursor.rs

do-build-DOCS-on:
# Build HTML documentation similar to ci/build-docs.sh
	(cd ${WRKSRC} && ${PYTHON_CMD} ci/generate-docs.py)
	mdbook-mermaid install ${WRKSRC}/docs
	mdbook build ${WRKSRC}/docs
	${CP} ${WRKSRC}/assets/icon/terminal.png \
		${WRKSRC}/gh_pages/html/favicon.png
	${CP} ${WRKSRC}/assets/icon/${PORTNAME}-icon.svg \
		${WRKSRC}/gh_pages/html/favicon.svg
	${RMDIR} ${WRKSRC}/gh_pages/html/install

do-install-DOCS-on:
	(cd ${WRKSRC}/gh_pages && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

post-install:
# Install assets similar to ci/deploy.sh
.for f in ${PORTNAME}.desktop ${PORTNAME}.appdata.xml ${PORTNAME}-nautilus.py \
	icon/terminal.png icon/${PORTNAME}-icon.svg shell-integration/${PORTNAME}.sh
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}:H}
	${INSTALL_DATA} ${WRKSRC}/assets/${f:R}.${f:E} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}}
.endfor
.if exists(/usr/bin/tic)
	tic -x -o ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*terminfo*:[1]:H:H} \
		${WRKSRC}/termwiz/data/${PORTNAME}.terminfo
.endif

.include <bsd.port.mk>
