PORTNAME=	leftwm
DISTVERSION=	0.2.7-37
DISTVERSIONSUFFIX=	-gb0b14f0
CATEGORIES=	x11-wm

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Tiling window manager for Adventurers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo xorg
USE_XORG=	xinerama xrandr

USE_GITHUB=	yes
GH_TAGNAME=	b0b14f0cf3e575a9d5c36e13fc5c34204688a8e9

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		anymap-0.12.1 \
		arc-swap-1.2.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		byte-tools-0.3.1 \
		byteorder-1.4.3 \
		bytes-1.0.1 \
		cc-1.0.67 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		crossbeam-channel-0.5.1 \
		crossbeam-utils-0.8.4 \
		digest-0.8.1 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		fake-simd-0.1.2 \
		futures-0.3.14 \
		futures-channel-0.3.14 \
		futures-core-0.3.14 \
		futures-executor-0.3.14 \
		futures-io-0.3.14 \
		futures-macro-0.3.14 \
		futures-sink-0.3.14 \
		futures-task-0.3.14 \
		futures-util-0.3.14 \
		generic-array-0.12.4 \
		getrandom-0.2.2 \
		git-version-0.3.4 \
		git-version-macro-0.3.4 \
		hermit-abi-0.1.18 \
		itertools-0.10.0 \
		itoa-0.4.7 \
		kstring-1.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.94 \
		libsystemd-sys-0.2.2 \
		liquid-0.22.0 \
		liquid-core-0.22.0 \
		liquid-derive-0.22.0 \
		liquid-lib-0.22.0 \
		log-0.4.14 \
		maplit-1.0.2 \
		maybe-uninit-2.0.0 \
		memchr-2.4.0 \
		mio-0.7.11 \
		miow-0.3.7 \
		nix-0.20.0 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		once_cell-1.7.2 \
		opaque-debug-0.2.3 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		pin-project-lite-0.2.6 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.10 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.7 \
		proc-macro2-1.0.26 \
		proc-quote-0.3.2 \
		proc-quote-impl-0.3.2 \
		quote-1.0.9 \
		rand-0.8.3 \
		rand_chacha-0.3.0 \
		rand_core-0.6.2 \
		rand_hc-0.3.0 \
		redox_syscall-0.2.8 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rustversion-1.0.4 \
		ryu-1.0.5 \
		serde-1.0.125 \
		serde_derive-1.0.125 \
		serde_json-1.0.64 \
		sha-1-0.8.2 \
		signal-hook-0.3.8 \
		signal-hook-registry-1.3.0 \
		slab-0.4.3 \
		slog-2.7.0 \
		slog-async-2.6.0 \
		slog-envlogger-2.2.0 \
		slog-journald-2.1.1 \
		slog-scope-4.4.0 \
		slog-stdlog-4.1.0 \
		slog-term-2.8.0 \
		strsim-0.8.0 \
		syn-1.0.72 \
		take_mut-0.2.2 \
		tempfile-3.2.0 \
		term-0.7.0 \
		textwrap-0.11.0 \
		thread_local-1.1.3 \
		time-0.1.44 \
		tokio-1.5.0 \
		tokio-macros-1.1.0 \
		toml-0.5.8 \
		typenum-1.13.0 \
		ucd-trie-0.1.3 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x11-dl-2.18.5 \
		xdg-2.2.0

OPTIONS_DEFINE=	THEMES
OPTIONS_DEFAULT= THEMES
OPTIONS_SUB=	yes

THEMES_DESC=	LeftWM Basic Themes

post-install-THEMES-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} themes \
		${STAGEDIR}${DATADIR}

post-install:
.for l in leftwm-state leftwm-worker leftwm-check leftwm
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/xsessions
	(cd ${WRKSRC} && ${COPYTREE_SHARE} leftwm.desktop \
		${STAGEDIR}${LOCALBASE}/share/xsessions/)

.include <bsd.port.mk>
