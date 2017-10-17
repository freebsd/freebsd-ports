# $FreeBSD$

PORTNAME=	alacritty
PORTVERSION=	g20171006
CATEGORIES=	x11

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	GPU-accelerated terminal emulator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jwilm
GH_TAGNAME=	e17d38167e174a2cf664e430fe968ec6492e1f08
GH_TUPLE=	jwilm:rust-fontconfig:419135e5e1106ec0973dd4923bd9c70d8e438cc8:servofontconfig \
		jwilm:libfontconfig:618a52973d46e5cce4f054f6ee3bd2682167eee4:servofontconfigsys

EXTRA_PATCHES+=	${EXTRA_PATCHES_${OPSYS}_${OSREL:R}}
EXTRA_PATCHES_FreeBSD_12=	${PATCHDIR}/extra-patch-freebsd12

PLIST_FILES=	bin/alacritty \
		${DESKTOPDIR:S,^${PREFIX}/,,}/Alacritty.desktop

CARGO_CRATES=	android_glue-0.2.3 \
		ansi_term-0.9.0 \
		approx-0.1.1 \
		arraydeque-0.2.3 \
		atty-0.2.2 \
		bitflags-0.4.0 \
		bitflags-0.7.0 \
		bitflags-0.8.2 \
		bitflags-0.9.1 \
		block-0.1.6 \
		byteorder-1.1.0 \
		bytes-0.3.0 \
		cargo_metadata-0.2.3 \
		cfg-if-0.1.2 \
		cgl-0.2.1 \
		cgmath-0.15.0 \
		clap-2.26.0 \
		clippy-0.0.164 \
		clippy_lints-0.0.164 \
		cmake-0.1.25 \
		cocoa-0.9.2 \
		conv-0.3.3 \
		core-foundation-0.3.0 \
		core-foundation-0.4.4 \
		core-foundation-sys-0.3.1 \
		core-foundation-sys-0.4.4 \
		core-graphics-0.8.2 \
		core-text-6.1.2 \
		custom_derive-0.1.7 \
		dlib-0.3.1 \
		dtoa-0.4.2 \
		dwmapi-sys-0.1.0 \
		either-1.1.0 \
		errno-0.2.3 \
		euclid-0.12.0 \
		expat-sys-2.1.5 \
		filetime-0.1.10 \
		fnv-1.0.5 \
		foreign-types-0.2.0 \
		freetype-rs-0.13.0 \
		freetype-sys-0.4.0 \
		fs2-0.2.5 \
		fsevent-0.2.16 \
		fsevent-sys-0.1.6 \
		gcc-0.3.53 \
		gdi32-sys-0.1.1 \
		getopts-0.2.15 \
		gl_generator-0.5.5 \
		gleam-0.4.8 \
		glutin-0.10.0 \
		heapsize-0.3.9 \
		inotify-0.3.0 \
		iovec-0.1.0 \
		itertools-0.6.3 \
		itoa-0.3.3 \
		kernel32-sys-0.2.2 \
		khronos_api-1.0.1 \
		lazy_static-0.2.8 \
		lazycell-0.4.0 \
		lazycell-0.5.1 \
		libc-0.2.30 \
		libloading-0.3.4 \
		libz-sys-1.0.16 \
		linked-hash-map-0.3.0 \
		linked-hash-map-0.4.2 \
		log-0.3.8 \
		magenta-0.1.1 \
		magenta-sys-0.1.1 \
		malloc_buf-0.0.6 \
		matches-0.1.6 \
		memmap-0.4.0 \
		mio-0.5.1 \
		mio-0.6.10 \
		mio-more-0.1.0 \
		miow-0.1.5 \
		miow-0.2.1 \
		net2-0.2.31 \
		nix-0.5.1 \
		nodrop-0.1.9 \
		notify-4.0.1 \
		num-traits-0.1.40 \
		objc-0.2.2 \
		objc-foundation-0.1.1 \
		objc_id-0.1.0 \
		odds-0.2.25 \
		osmesa-sys-0.1.2 \
		owning_ref-0.3.3 \
		parking_lot-0.4.5 \
		parking_lot_core-0.2.4 \
		phf-0.7.21 \
		phf_codegen-0.7.21 \
		phf_generator-0.7.21 \
		phf_shared-0.7.21 \
		pkg-config-0.3.9 \
		pulldown-cmark-0.0.15 \
		quine-mc_cluskey-0.2.4 \
		quote-0.3.15 \
		rand-0.3.16 \
		redox_syscall-0.1.31 \
		regex-syntax-0.4.1 \
		rustc-serialize-0.3.24 \
		semver-0.6.0 \
		semver-parser-0.7.0 \
		serde-0.9.15 \
		serde-1.0.11 \
		serde_derive-1.0.11 \
		serde_derive_internals-0.15.1 \
		serde_json-0.9.10 \
		serde_json-1.0.2 \
		serde_yaml-0.7.1 \
		shared_library-0.1.7 \
		shell32-sys-0.1.1 \
		siphasher-0.2.2 \
		slab-0.1.3 \
		slab-0.3.0 \
		smallvec-0.4.3 \
		stable_deref_trait-1.0.0 \
		strsim-0.6.0 \
		syn-0.11.11 \
		synom-0.11.3 \
		target_build_utils-0.3.1 \
		tempfile-2.1.6 \
		term_size-0.3.0 \
		textwrap-0.7.0 \
		time-0.1.38 \
		toml-0.4.5 \
		unicode-normalization-0.1.5 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		user32-sys-0.1.2 \
		utf8parse-0.1.0 \
		vcpkg-0.2.2 \
		vec_map-0.8.0 \
		vte-0.3.2 \
		walkdir-0.1.8 \
		wayland-client-0.9.9 \
		wayland-kbd-0.9.1 \
		wayland-protocols-0.9.9 \
		wayland-scanner-0.9.9 \
		wayland-sys-0.9.9 \
		wayland-window-0.8.0 \
		winapi-0.2.8 \
		winapi-build-0.1.1 \
		winit-0.8.2 \
		ws2_32-sys-0.2.1 \
		x11-dl-2.15.0 \
		xdg-2.1.0 \
		xml-rs-0.3.6 \
		xml-rs-0.6.1 \
		yaml-rust-0.3.5
CARGO_USE_GITHUB=	yes
CARGO_GH_CARGOTOML=	${CARGO_CARGOTOML} \
			${WRKSRC}/font/Cargo.toml \
			${WRKSRC_servofontconfig}/Cargo.toml

post-install:
	${INSTALL_DATA} ${WRKSRC}/Alacritty.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
