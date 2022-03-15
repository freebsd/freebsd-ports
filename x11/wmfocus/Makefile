PORTNAME=	wmfocus
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	6
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	c646aa39614b.patch:-p1 # https://github.com/svenstaro/wmfocus/pull/72

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Visually focus windows by label

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libxkbcommon>0:x11/libxkbcommon
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		cargo gnome python:3.4+,build xorg
USE_GITHUB=	yes
USE_GNOME=	cairo
USE_XORG=	x11 xcb
GH_ACCOUNT=	svenstaro
CARGO_FEATURES=	i3
PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		anyhow-1.0.42 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		cairo-rs-0.14.1 \
		cairo-sys-rs-0.14.0 \
		cc-1.0.68 \
		cfg-expr-0.7.4 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		cmake-0.1.45 \
		core-foundation-0.9.1 \
		core-foundation-sys-0.8.2 \
		core-graphics-0.22.2 \
		core-graphics-types-0.1.1 \
		core-text-19.2.0 \
		css-color-parser-0.1.2 \
		either-1.6.1 \
		env_logger-0.7.1 \
		expat-sys-2.1.6 \
		font-loader-0.11.0 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		freetype-sys-0.13.1 \
		futures-channel-0.3.15 \
		futures-core-0.3.15 \
		futures-executor-0.3.15 \
		futures-task-0.3.15 \
		futures-util-0.3.15 \
		glib-0.14.2 \
		glib-macros-0.14.1 \
		glib-sys-0.14.0 \
		gobject-sys-0.14.0 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		humantime-1.3.0 \
		itertools-0.10.1 \
		itoa-0.4.7 \
		lazy_static-0.1.16 \
		lazy_static-1.4.0 \
		libc-0.2.98 \
		log-0.4.14 \
		memchr-2.4.0 \
		once_cell-1.8.0 \
		pin-project-lite-0.2.7 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		pretty_env_logger-0.4.0 \
		proc-macro-crate-1.0.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.27 \
		quick-error-1.2.3 \
		quote-1.0.9 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		ryu-1.0.5 \
		serde-1.0.126 \
		serde_derive-1.0.126 \
		serde_json-1.0.64 \
		servo-fontconfig-0.5.1 \
		servo-fontconfig-sys-5.1.0 \
		slab-0.4.3 \
		smallvec-1.6.1 \
		strsim-0.8.0 \
		structopt-0.3.22 \
		structopt-derive-0.4.15 \
		strum-0.21.0 \
		strum_macros-0.21.1 \
		syn-1.0.73 \
		system-deps-3.1.2 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		thiserror-1.0.26 \
		thiserror-impl-1.0.26 \
		toml-0.5.8 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version-compare-0.0.11 \
		version_check-0.9.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x11-2.18.2 \
		xcb-0.9.0 \
		xcb-util-0.3.0 \
		xkbcommon-0.4.0 \
		swayipc,swayipc-types@git+https://github.com/JayceFayne/swayipc-rs\#f6b045f6dff3b8135c74c996cb95a39c874e4939

post-patch:
# lang/python3 cannot be used as a dependency
	@${REINPLACE_CMD} -e 's/"python3"/"${PYTHON_CMD:T}"/' \
		${WRKSRC}/cargo-crates/xcb-*/build.rs

.include <bsd.port.mk>
