# Notes for port maintainer(s)
#
# Before copying package.json and package-lock.json to ${PKGJSONSDIR},
# do the following steps:
# 1. Add node-addon-api and node-gyp to devDependencies in ${WRKSRC}
#    $ npm install --save-dev --ignore-scripts node-addon-api node-gyp
# This is required for building sharp node module from source.
# https://sharp.pixelplumbing.com/install/#building-from-source
# 2. Generate package.json and package-lock.json in ${WRKSRC}/tsunami/template
#    $ cd tsunami/templates && cp package.json.tmpl package.json && npm install --ignore-scripts

PORTNAME=	waveterm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.1
CATEGORIES=	x11
DISTFILES=	tsunami/go.mod:prefetch

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Open source, AI-native terminal that sees your entire workspace
WWW=		https://www.waveterm.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	task:devel/task
LIB_DEPENDS=	libvips.so:graphics/vips

USES=		cargo electron:40 gmake go:1.25+,modules,no_targets \
		nodejs:24,build python:build

USE_GITHUB=	yes
GH_ACCOUNT=	wavetermdev
GH_TUPLE=	swc-project:swc:v1.15.11:swc/swc

CARGO_CARGOTOML=${WRKSRC}/swc/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/swc/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_ENV+=	CARGO_FEATURE_LOCAL_DYNAMIC_TLS=1

GO_MOD_DIST=	github
GO_MODULE=	github.com/wavetermdev/waveterm

BINARY_ALIAS=	python3=${PYTHON_CMD}
SUB_FILES=	${PORTNAME}

PLIST_SUB=	ARCH=${ARCH:S/aarch64/arm64/:S/amd64/x64/} \
		DISTVERSION=${DISTVERSION}
PORTDOCS=	CONTRIBUTING.md README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

USE_ELECTRON=	npm:npm appbuilder:devel prefetch extract rebuild build:builder

ELECTRON_MAKE_FLAGS+=	-c electron-builder.config.cjs

pre-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}/tsunami
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/tsunami/go.mod ]; then \
		${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
			https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/tsunami/go.mod \
			-o ${DISTDIR}/${DIST_SUBDIR}/tsunami/go.mod; \
	fi

pre-build:
	cd ${WRKSRC}/swc && \
	${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${CARGO} build \
		--manifest-path ${CARGO_CARGOTOML} \
		--package binding_core_node --release --verbose --verbose
	${CP} ${CARGO_TARGET_DIR}/*/libbinding_core_node.so \
		${WRKSRC}/node_modules/@swc/core/swc.freebsd-${ELECTRON_ARCH}.node
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} task --verbose build:backend
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} task --verbose build:tsunamiscaffold
.for mod in lqip-loader plugin-ideal-image
	cd ${WRKSRC}/node_modules/@docusaurus/${mod}/node_modules/sharp && \
		${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} npm run install
.endfor
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm run build:prod
	# generate icon files
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} app-builder icon \
		--input=icon.icns --out=icons --format=set --root=build
.for size in 16 48
	${MV} ${WRKSRC}/icons/icon_${size}x${size}.png ${WRKSRC}/icons/icon_${size}.png
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
.for size in 16 32 48 64 128 256 512 1024
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/icons/icon_${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/make/${ELECTRON_BUILDER_APP_OUT_DIR} && \
		${COPYTREE_SHARE} resources ${STAGEDIR}${DATADIR}
	${FIND} ${STAGEDIR}${DATADIR}/resources -type f -exec ${FILE} {} ';' | \
		${GREP} 'ELF.*FreeBSD' | ${AWK} -F ': ' '{print $$1}' | ${XARGS} ${STRIP_CMD}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} npm run test

.include <bsd.port.mk>
