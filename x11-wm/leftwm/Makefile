PORTNAME=	leftwm
DISTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiling window manager for Adventurers
WWW=		https://leftwm.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo xorg
USE_XORG=	xinerama xrandr
USE_GITHUB=	yes

CARGO_CRATES=	aho-corasick-0.7.19 \
		anyhow-1.0.66 \
		anymap2-0.13.0 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		base64-0.13.1 \
		bitflags-1.3.2 \
		block-buffer-0.10.3 \
		bytes-1.2.1 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		clap-4.0.18 \
		clap_lex-0.3.0 \
		const_format-0.2.30 \
		const_format_proc_macros-0.2.29 \
		cpufeatures-0.2.5 \
		crossbeam-channel-0.5.6 \
		crossbeam-utils-0.8.12 \
		crypto-common-0.1.6 \
		digest-0.10.5 \
		dirs-4.0.0 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.7 \
		dirs-sys-next-0.1.2 \
		doc-comment-0.3.3 \
		either-1.8.0 \
		fastrand-1.8.0 \
		futures-0.3.25 \
		futures-channel-0.3.25 \
		futures-core-0.3.25 \
		futures-executor-0.3.25 \
		futures-io-0.3.25 \
		futures-macro-0.3.25 \
		futures-sink-0.3.25 \
		futures-task-0.3.25 \
		futures-util-0.3.25 \
		generic-array-0.14.6 \
		getrandom-0.2.8 \
		git-version-0.3.5 \
		git-version-macro-0.3.5 \
		hermit-abi-0.1.19 \
		instant-0.1.12 \
		itertools-0.10.5 \
		itoa-1.0.4 \
		kstring-2.0.0 \
		lazy_static-1.4.0 \
		lefthk-core-0.1.8 \
		libc-0.2.135 \
		liquid-0.26.0 \
		liquid-core-0.26.0 \
		liquid-derive-0.26.0 \
		liquid-lib-0.26.0 \
		log-0.4.17 \
		matchers-0.1.0 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		mio-0.8.4 \
		nix-0.23.1 \
		nix-0.25.0 \
		nu-ansi-term-0.46.0 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		num_threads-0.1.6 \
		once_cell-1.15.0 \
		os_str_bytes-6.3.0 \
		overload-0.1.1 \
		percent-encoding-2.2.0 \
		pest-2.4.0 \
		pest_derive-2.4.0 \
		pest_generator-2.4.0 \
		pest_meta-2.4.0 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		pkg-config-0.3.25 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.47 \
		proc-quote-0.4.0 \
		proc-quote-impl-0.3.2 \
		quote-1.0.21 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.6.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.27 \
		remove_dir_all-0.5.3 \
		ron-0.8.0 \
		ryu-1.0.11 \
		serde-1.0.147 \
		serde_derive-1.0.147 \
		serde_json-1.0.87 \
		sha1-0.10.5 \
		sharded-slab-0.1.4 \
		shellexpand-2.1.2 \
		signal-hook-0.3.14 \
		signal-hook-registry-1.4.0 \
		slab-0.4.7 \
		smallvec-1.10.0 \
		socket2-0.4.7 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.103 \
		syslog-tracing-0.1.0 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		thiserror-1.0.37 \
		thiserror-impl-1.0.37 \
		thread_local-1.1.4 \
		time-0.3.15 \
		time-macros-0.2.4 \
		tokio-1.21.2 \
		tokio-macros-1.8.0 \
		toml-0.5.9 \
		tracing-0.1.37 \
		tracing-appender-0.2.2 \
		tracing-attributes-0.1.23 \
		tracing-core-0.1.30 \
		tracing-journald-0.3.0 \
		tracing-log-0.1.3 \
		tracing-subscriber-0.3.16 \
		typenum-1.15.0 \
		ucd-trie-0.1.5 \
		unicode-ident-1.0.5 \
		unicode-segmentation-1.10.0 \
		unicode-xid-0.2.4 \
		valuable-0.1.0 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.36.1 \
		x11-dl-2.20.0 \
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
