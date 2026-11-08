PORTNAME=	tabby
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.238
CATEGORIES=	x11

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Highly configurable terminal emulator with SSH and serial support
WWW=		https://tabby.sh/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	the bundled russh library provides no native module \
			for other architectures

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libsecret-1.so:security/libsecret

USES=		cargo desktop-file-utils electron:43 gmake nodejs:24,build \
		npm:yarn1 pkgconfig python:build

USE_GITHUB=	yes
GH_ACCOUNT=	Eugeny
GH_TUPLE=	Eugeny:russh-napi:4b226ea:russh/russh

NPM_CACHE_SETUP_CMD=	${SH} -c 'echo yarn-offline-mirror \"$$(pwd)/${NPM_MODULE_CACHE}\" > .yarnrc'

USE_ELECTRON=	appbuilder:devel rebuild build:builder
ELECTRON_REBUILD_WRKSRC_ELECTRON=	${WRKSRC}/app

CARGO_CARGOTOML=${WRKSRC}/russh/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/russh/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	ARCH=${ELECTRON_ARCH} TABBY_VERSION=${DISTVERSION}

BINARY_ALIAS=	python3=${PYTHON_CMD}
SUB_FILES=	${PORTNAME}

PLIST_SUB=	ELECTRON_ARCH=${ELECTRON_ARCH}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

TABBY_PLUGINS=	tabby-auto-sudo-password tabby-community-color-schemes \
		tabby-core tabby-electron tabby-linkifier tabby-local \
		tabby-plugin-manager tabby-serial tabby-settings tabby-ssh \
		tabby-telnet tabby-terminal tabby-web

TABBY_PRUNE=	extras \
		builtin-plugins/*/src \
		builtin-plugins/*/tsconfig.json \
		builtin-plugins/tabby-ssh/node_modules/winston/test \
		app.asar.unpacked/node_modules/@serialport/bindings-cpp/prebuilds \
		app.asar.unpacked/node_modules/glasstron/native \
		app.asar.unpacked/node_modules/node-pty/prebuilds \
		app.asar.unpacked/node_modules/russh/russh.darwin-*.node \
		app.asar.unpacked/node_modules/russh/russh.linux-*.node \
		app.asar.unpacked/node_modules/russh/russh.win32-*.node

post-extract:
	${CP} ${FILESDIR}/freebsd.cc \
		${WRKSRC}/app/node_modules/native-process-working-directory/src
	${REINPLACE_CMD} -e 's|"1.0.0-alpha.1"|"${DISTVERSION}"|' \
		${WRKSRC}/app/package.json

pre-build:
	cd ${WRKSRC}/russh && \
		${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${CARGO} build \
		--manifest-path ${CARGO_CARGOTOML} --release
	${CP} ${CARGO_TARGET_DIR}/release/librussh_napi.so \
		${WRKSRC}/app/node_modules/russh/russh.freebsd-${ELECTRON_ARCH}.node
.for plugin in ${TABBY_PLUGINS}
	${LN} -sf ../${plugin} ${WRKSRC}/node_modules/${plugin}
.endfor
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} node scripts/build-typings.mjs
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} node scripts/build-modules.mjs
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} \
		node scripts/prepackage-plugins.mjs
	${LN} -sf ../../node_modules/electron ${WRKSRC}/app/node_modules

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
.for size in 16 32 64 128 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/build/icons/${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/dist/${ELECTRON_BUILDER_APP_OUT_DIR} && \
		${COPYTREE_SHARE} resources ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${DATADIR}/resources && ${RM} -r ${TABBY_PRUNE}
	${FIND} ${STAGEDIR}${DATADIR}/resources -name '*.map' -delete
	${FIND} ${STAGEDIR}${DATADIR}/resources/app.asar.unpacked -type f \
		\( -name '*.cc' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \
		-o -name '*.mm' \) -delete
	${FIND} ${STAGEDIR}${DATADIR}/resources -type d -empty -delete
	${FIND} ${STAGEDIR}${DATADIR}/resources -type f -exec ${FILE} {} ';' | \
		${GREP} 'ELF.*FreeBSD' | ${AWK} -F ': ' '{print $$1}' | ${XARGS} ${STRIP_CMD}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
