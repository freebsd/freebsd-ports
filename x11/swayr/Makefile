PORTNAME=	swayr
DISTVERSION=	0.22.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Urgent-first/LRU window switcher for sway
WWW=		https://sr.ht/~tsdh/swayr/#swayr

LICENSE=	GPLv3+
LICENSE_FILE=	${_LICENSE_STORE}/GPLv3

USES=		cargo
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}d

CARGO_CRATES=	aho-corasick-0.7.19 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		clap-3.2.22 \
		clap_derive-3.2.18 \
		clap_lex-0.2.4 \
		directories-4.0.1 \
		dirs-sys-0.3.7 \
		env_logger-0.9.1 \
		getrandom-0.2.7 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		indexmap-1.9.1 \
		itoa-1.0.3 \
		lazy_static-1.4.0 \
		libc-0.2.133 \
		log-0.4.17 \
		memchr-2.5.0 \
		once_cell-1.15.0 \
		os_str_bytes-6.3.0 \
		peg-0.8.1 \
		peg-macros-0.8.1 \
		peg-runtime-0.8.1 \
		ppv-lite86-0.2.16 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.44 \
		quote-1.0.21 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		rt-format-0.3.1 \
		ryu-1.0.11 \
		serde-1.0.145 \
		serde_derive-1.0.145 \
		serde_json-1.0.85 \
		strsim-0.10.0 \
		swayipc-3.0.1 \
		swayipc-types-1.1.2 \
		syn-1.0.101 \
		termcolor-1.1.3 \
		textwrap-0.15.1 \
		thiserror-1.0.36 \
		thiserror-impl-1.0.36 \
		toml-0.5.9 \
		unicode-ident-1.0.4 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

post-patch:
# Respect PREFIX for config and icons
	@${REINPLACE_CMD} -e 's,/usr/share,${DATADIR:H},' \
		-e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/config.rs \
		${WRKSRC}/src/shared/cfg.rs \
		${WRKSRC}/src/util.rs

.include <bsd.port.mk>
