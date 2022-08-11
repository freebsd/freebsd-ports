PORTNAME=	leftwm
DISTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	x11-wm

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Tiling window manager for Adventurers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo xorg
USE_XORG=	xinerama xrandr
USE_GITHUB=	yes

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		anyhow-1.0.56 \
		anymap2-0.13.0 \
		arc-swap-1.5.0 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		block-buffer-0.7.3 \
		block-buffer-0.9.0 \
		block-padding-0.1.5 \
		byte-tools-0.3.1 \
		byteorder-1.4.3 \
		bytes-1.1.0 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		cpufeatures-0.2.1 \
		crossbeam-channel-0.5.2 \
		crossbeam-utils-0.8.7 \
		crypto-mac-0.11.1 \
		digest-0.8.1 \
		digest-0.9.0 \
		dirs-4.0.0 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.6 \
		dirs-sys-next-0.1.2 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		fake-simd-0.1.2 \
		fastrand-1.7.0 \
		futures-0.3.21 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-macro-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		generic-array-0.12.4 \
		generic-array-0.14.5 \
		getrandom-0.2.5 \
		git-version-0.3.5 \
		git-version-macro-0.3.5 \
		hermit-abi-0.1.19 \
		hmac-0.11.0 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-1.0.1 \
		kstring-1.0.6 \
		lazy_static-1.4.0 \
		libc-0.2.119 \
		libsystemd-0.4.1 \
		liquid-0.24.0 \
		liquid-core-0.24.0 \
		liquid-derive-0.24.0 \
		liquid-lib-0.24.0 \
		log-0.4.14 \
		maplit-1.0.2 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		mio-0.8.0 \
		miow-0.3.7 \
		nix-0.23.1 \
		ntapi-0.3.7 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		num_threads-0.1.3 \
		once_cell-1.10.0 \
		opaque-debug-0.2.3 \
		opaque-debug-0.3.0 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		pin-project-lite-0.2.8 \
		pin-utils-0.1.0 \
		pkg-config-0.3.24 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.36 \
		proc-quote-0.4.0 \
		proc-quote-impl-0.3.2 \
		quote-1.0.15 \
		redox_syscall-0.2.11 \
		redox_users-0.4.0 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rustversion-1.0.6 \
		ryu-1.0.9 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		sha-1-0.8.2 \
		sha2-0.9.9 \
		shellexpand-2.1.0 \
		signal-hook-0.3.13 \
		signal-hook-registry-1.4.0 \
		slab-0.4.5 \
		slog-2.7.0 \
		slog-async-2.7.0 \
		slog-envlogger-2.2.0 \
		slog-journald-2.2.0 \
		slog-scope-4.4.0 \
		slog-stdlog-4.1.0 \
		slog-term-2.9.0 \
		socket2-0.4.4 \
		strsim-0.8.0 \
		subtle-2.4.1 \
		syn-1.0.86 \
		take_mut-0.2.2 \
		tempfile-3.3.0 \
		term-0.7.0 \
		textwrap-0.11.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		thread_local-1.1.4 \
		time-0.3.7 \
		time-macros-0.2.3 \
		tokio-1.17.0 \
		tokio-macros-1.7.0 \
		toml-0.5.8 \
		typenum-1.15.0 \
		ucd-trie-0.1.3 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		uuid-0.8.2 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x11-dl-2.19.1 \
		xdg-2.4.1

OPTIONS_DEFINE=	DOCS THEMES
OPTIONS_DEFAULT=	THEMES
OPTIONS_SUB=	yes

THEMES_DESC=	LeftWM Basic Themes

CARGO_INSTALL_PATH=	./leftwm

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for l in CHANGELOG CONTRIBUTING.md README.md
	${INSTALL_MAN} ${WRKSRC}/${l} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-THEMES-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} themes \
		${STAGEDIR}${DATADIR}

post-install:
.for l in leftwm-state leftwm-worker leftwm-check \
	leftwm-command leftwm
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/xsessions
	(cd ${WRKSRC} && ${INSTALL_DATA} leftwm.desktop \
		${STAGEDIR}${LOCALBASE}/share/xsessions/)

.include <bsd.port.mk>
