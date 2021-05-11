PORTNAME=	wmfocus
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.5
PORTREVISION=	4
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ea57e7daf4d8.patch:-p1 # https://github.com/svenstaro/wmfocus/pull/72

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Visually focus windows by label

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxkbcommon.so:x11/libxkbcommon

USES=		cargo gnome python:3.4+,build xorg
USE_GITHUB=	yes
USE_GNOME=	cairo
USE_XORG=	x11 xcb
GH_ACCOUNT=	svenstaro
GH_TUPLE=	JayceFayne:swayipc-rs:f6b045f6dff3b8135c74c996cb95a39c874e4939:swayipc
CARGO_FEATURES=	i3
PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		anyhow-1.0.34 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		cairo-rs-0.9.1 \
		cairo-sys-rs-0.10.0 \
		cc-1.0.65 \
		cfg-if-0.1.10 \
		clap-2.33.3 \
		cmake-0.1.45 \
		core-foundation-0.9.1 \
		core-foundation-sys-0.8.2 \
		core-graphics-0.22.1 \
		core-graphics-types-0.1.1 \
		core-text-19.1.0 \
		css-color-parser-0.1.2 \
		either-1.6.1 \
		env_logger-0.7.1 \
		expat-sys-2.1.6 \
		font-loader-0.11.0 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		freetype-sys-0.13.1 \
		futures-channel-0.3.8 \
		futures-core-0.3.8 \
		futures-executor-0.3.8 \
		futures-macro-0.3.8 \
		futures-task-0.3.8 \
		futures-util-0.3.8 \
		glib-0.10.3 \
		glib-macros-0.10.1 \
		glib-sys-0.10.1 \
		gobject-sys-0.10.0 \
		heck-0.3.1 \
		hermit-abi-0.1.17 \
		humantime-1.3.0 \
		itertools-0.9.0 \
		itoa-0.4.6 \
		lazy_static-0.1.16 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		log-0.4.11 \
		memchr-2.3.4 \
		once_cell-1.5.2 \
		pin-project-1.0.2 \
		pin-project-internal-1.0.2 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		pretty_env_logger-0.4.0 \
		proc-macro-crate-0.1.5 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.6 \
		proc-macro2-1.0.24 \
		quick-error-1.2.3 \
		quote-1.0.7 \
		regex-1.4.1 \
		regex-syntax-0.6.20 \
		ryu-1.0.5 \
		serde-1.0.117 \
		serde_derive-1.0.117 \
		serde_json-1.0.59 \
		servo-fontconfig-0.5.1 \
		servo-fontconfig-sys-5.1.0 \
		slab-0.4.2 \
		strsim-0.8.0 \
		structopt-0.3.20 \
		structopt-derive-0.4.13 \
		strum-0.18.0 \
		strum_macros-0.18.0 \
		syn-1.0.51 \
		system-deps-1.3.2 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		thiserror-1.0.22 \
		thiserror-impl-1.0.22 \
		thread_local-1.0.1 \
		toml-0.5.7 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		version-compare-0.0.10 \
		version_check-0.9.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x11-2.18.2 \
		xcb-0.9.0 \
		xcb-util-0.3.0 \
		xkbcommon-0.4.0
CARGO_USE_GITHUB=	yes
CARGO_GIT_SUBDIR=	swayipc:swayipc:blocking

post-patch:
# lang/python3 cannot be used as a dependency
	@${REINPLACE_CMD} -e 's/"python3"/"${PYTHON_CMD:T}"/' \
		${WRKSRC}/cargo-crates/xcb-*/build.rs

.include <bsd.port.mk>
