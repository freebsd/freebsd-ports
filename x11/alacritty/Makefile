# $FreeBSD$

PORTNAME=	alacritty
PORTVERSION=	g20180126
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	GPU-accelerated terminal emulator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jwilm
GH_TAGNAME=	b82622e9948d1c90fc628739c7f328816214fb33
GH_TUPLE=	jwilm:rust-fontconfig:be2b94de833ec69cf767186262a5fb8360fa5b45:servofontconfig \
		jwilm:libfontconfig:5c1845e1bffa11cf4d3e6fb27f456bf5c814ce1b:servofontconfigsys

PLIST_FILES=	bin/alacritty \
		${DESKTOPDIR:S,^${PREFIX}/,,}/Alacritty.desktop

CARGO_CRATES=	aho-corasick-0.6.4 \
		android_glue-0.2.3 \
		ansi_term-0.10.2 \
		approx-0.1.1 \
		arraydeque-0.2.3 \
		atty-0.2.6 \
		base64-0.9.0 \
		bitflags-0.4.0 \
		bitflags-0.7.0 \
		bitflags-0.8.2 \
		bitflags-0.9.1 \
		bitflags-1.0.1 \
		block-0.1.6 \
		byteorder-1.2.1 \
		bytes-0.3.0 \
		cargo_metadata-0.2.3 \
		cc-1.0.4 \
		cfg-if-0.1.2 \
		cgl-0.2.1 \
		cgmath-0.16.0 \
		chrono-0.4.0 \
		clap-2.29.2 \
		clippy-0.0.182 \
		clippy_lints-0.0.182 \
		cmake-0.1.29 \
		cocoa-0.13.0 \
		core-foundation-0.4.6 \
		core-foundation-sys-0.4.6 \
		core-graphics-0.12.4 \
		core-text-8.0.0 \
		dlib-0.4.0 \
		dtoa-0.4.2 \
		dwmapi-sys-0.1.1 \
		either-1.4.0 \
		env_logger-0.5.3 \
		errno-0.2.3 \
		euclid-0.16.2 \
		expat-sys-2.1.5 \
		filetime-0.1.15 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		freetype-rs-0.13.0 \
		freetype-sys-0.4.0 \
		fsevent-0.2.17 \
		fsevent-sys-0.1.6 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		gdi32-sys-0.1.2 \
		getopts-0.2.17 \
		gl_generator-0.7.0 \
		gl_generator-0.8.0 \
		gleam-0.4.20 \
		glutin-0.12.0 \
		idna-0.1.4 \
		if_chain-0.1.2 \
		inotify-0.3.0 \
		iovec-0.1.1 \
		itertools-0.6.5 \
		itoa-0.3.4 \
		kernel32-sys-0.2.2 \
		khronos_api-2.0.0 \
		lazy_static-1.0.0 \
		lazycell-0.4.0 \
		lazycell-0.6.0 \
		libc-0.2.40 \
		libloading-0.4.3 \
		libz-sys-1.0.18 \
		linked-hash-map-0.5.0 \
		log-0.3.9 \
		log-0.4.1 \
		malloc_buf-0.0.6 \
		matches-0.1.6 \
		memchr-2.0.1 \
		memmap-0.6.2 \
		mio-0.5.1 \
		mio-0.6.12 \
		mio-more-0.1.0 \
		miow-0.1.5 \
		miow-0.2.1 \
		net2-0.2.31 \
		nix-0.5.1 \
		nodrop-0.1.12 \
		notify-4.0.3 \
		num-0.1.41 \
		num-integer-0.1.35 \
		num-iter-0.1.34 \
		num-traits-0.1.42 \
		objc-0.2.2 \
		objc-foundation-0.1.1 \
		objc_id-0.1.0 \
		odds-0.2.26 \
		osmesa-sys-0.1.2 \
		owning_ref-0.3.3 \
		parking_lot-0.5.3 \
		parking_lot_core-0.2.10 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.9 \
		pulldown-cmark-0.0.15 \
		quine-mc_cluskey-0.2.4 \
		quote-0.3.15 \
		rand-0.3.20 \
		rand-0.4.2 \
		redox_syscall-0.1.37 \
		redox_termios-0.1.1 \
		regex-0.2.5 \
		regex-syntax-0.4.2 \
		safemem-0.2.0 \
		same-file-1.0.2 \
		semver-0.6.0 \
		semver-parser-0.7.0 \
		serde-1.0.27 \
		serde_derive-1.0.27 \
		serde_derive_internals-0.19.0 \
		serde_json-1.0.9 \
		serde_yaml-0.7.3 \
		shared_library-0.1.8 \
		shell32-sys-0.1.2 \
		slab-0.1.3 \
		slab-0.3.0 \
		smallvec-0.6.0 \
		stable_deref_trait-1.0.0 \
		strsim-0.6.0 \
		syn-0.11.11 \
		synom-0.11.3 \
		tempfile-2.2.0 \
		termcolor-0.3.3 \
		termion-1.5.1 \
		textwrap-0.9.0 \
		thread_local-0.3.5 \
		time-0.1.39 \
		token_store-0.1.2 \
		toml-0.4.5 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.5 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		unreachable-1.0.0 \
		url-1.6.0 \
		user32-sys-0.1.3 \
		utf8-ranges-1.0.0 \
		utf8parse-0.1.0 \
		vcpkg-0.2.2 \
		vec_map-0.8.0 \
		void-1.0.2 \
		vte-0.3.2 \
		walkdir-2.0.1 \
		wayland-client-0.12.5 \
		wayland-kbd-0.13.1 \
		wayland-protocols-0.12.5 \
		wayland-scanner-0.12.5 \
		wayland-sys-0.12.5 \
		wayland-window-0.13.2 \
		winapi-0.2.8 \
		winapi-0.3.4 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-0.1.4 \
		winit-0.10.0 \
		ws2_32-sys-0.2.1 \
		x11-dl-2.17.2 \
		xdg-2.1.0 \
		xml-rs-0.7.0 \
		yaml-rust-0.4.0
CARGO_USE_GITHUB=	yes
CARGO_GH_CARGOTOML=	${CARGO_CARGOTOML} \
			${WRKSRC}/font/Cargo.toml \
			${WRKSRC_servofontconfig}/Cargo.toml

post-install:
	${INSTALL_DATA} ${WRKSRC}/Alacritty.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
