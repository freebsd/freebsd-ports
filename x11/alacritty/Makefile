# $FreeBSD$

PORTNAME=	alacritty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	GPU-accelerated terminal emulator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
TEST_DEPENDS=	dejavu>0:x11-fonts/dejavu

USES=		cargo localbase:ldflags python:3.6+,build ssl:build
USE_GITHUB=	yes

CARGO_CRATES=	ab_glyph_rasterizer-0.1.4 \
		adler32-1.2.0 \
		andrew-0.3.1 \
		android_glue-0.2.3 \
		ansi_term-0.11.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.12.3 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.11 \
		block-0.1.6 \
		byteorder-1.4.2 \
		calloop-0.6.5 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		cgl-0.3.2 \
		clap-2.33.3 \
		clipboard-win-3.1.1 \
		cmake-0.1.45 \
		cocoa-0.23.0 \
		cocoa-0.24.0 \
		cocoa-foundation-0.1.0 \
		constant_time_eq-0.1.5 \
		copypasta-0.7.1 \
		core-foundation-0.7.0 \
		core-foundation-0.9.1 \
		core-foundation-sys-0.7.0 \
		core-foundation-sys-0.8.2 \
		core-graphics-0.19.2 \
		core-graphics-0.22.2 \
		core-graphics-types-0.1.1 \
		core-text-19.1.0 \
		core-video-sys-0.1.4 \
		crc32fast-1.2.1 \
		crossbeam-utils-0.8.1 \
		crossfont-0.2.0 \
		darling-0.10.2 \
		darling_core-0.10.2 \
		darling_macro-0.10.2 \
		derivative-2.2.0 \
		dirs-2.0.2 \
		dirs-sys-0.3.5 \
		dispatch-0.2.0 \
		dlib-0.4.2 \
		downcast-rs-1.2.0 \
		dtoa-0.4.7 \
		dwrote-0.11.0 \
		embed-resource-1.5.1 \
		expat-sys-2.1.6 \
		filetime-0.2.14 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.1 \
		foreign-types-shared-0.1.1 \
		foreign-types-shared-0.3.0 \
		freetype-rs-0.26.0 \
		freetype-sys-0.13.1 \
		fsevent-0.4.0 \
		fsevent-sys-2.0.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		getrandom-0.1.16 \
		gl_generator-0.14.0 \
		glutin-0.26.0 \
		glutin_egl_sys-0.1.5 \
		glutin_emscripten_sys-0.1.1 \
		glutin_gles2_sys-0.1.5 \
		glutin_glx_sys-0.1.7 \
		glutin_wgl_sys-0.1.5 \
		hermit-abi-0.1.18 \
		ident_case-1.0.1 \
		inotify-0.7.1 \
		inotify-sys-0.1.5 \
		instant-0.1.9 \
		iovec-0.1.4 \
		itoa-0.4.7 \
		jni-sys-0.3.0 \
		kernel32-sys-0.2.2 \
		khronos_api-3.1.0 \
		lazy-bytes-cast-5.0.1 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.86 \
		libloading-0.6.7 \
		linked-hash-map-0.5.4 \
		lock_api-0.4.2 \
		log-0.4.14 \
		malloc_buf-0.0.6 \
		maybe-uninit-2.0.0 \
		memchr-2.3.4 \
		memmap2-0.1.0 \
		miniz_oxide-0.3.7 \
		mio-0.6.23 \
		mio-anonymous-pipes-0.1.0 \
		mio-extras-2.0.6 \
		miow-0.2.2 \
		miow-0.3.6 \
		ndk-0.2.1 \
		ndk-glue-0.2.1 \
		ndk-macro-0.2.0 \
		ndk-sys-0.2.1 \
		net2-0.2.37 \
		nix-0.18.0 \
		nom-6.1.0 \
		notify-4.0.15 \
		num_enum-0.4.3 \
		num_enum_derive-0.4.3 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		once_cell-1.5.2 \
		osmesa-sys-0.1.2 \
		owned_ttf_parser-0.6.0 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.19 \
		png-0.16.8 \
		proc-macro-crate-0.1.5 \
		proc-macro2-1.0.24 \
		quote-1.0.9 \
		raw-window-handle-0.3.3 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.4 \
		redox_users-0.3.5 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.22 \
		rust-argon2-0.8.3 \
		rusttype-0.9.2 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scoped-tls-1.0.0 \
		scopeguard-1.1.0 \
		serde-1.0.123 \
		serde_derive-1.0.123 \
		serde_json-1.0.62 \
		serde_yaml-0.8.17 \
		servo-fontconfig-0.5.1 \
		servo-fontconfig-sys-5.1.0 \
		shared_library-0.1.9 \
		signal-hook-0.1.17 \
		signal-hook-registry-1.3.0 \
		slab-0.4.2 \
		smallvec-1.6.1 \
		smithay-client-toolkit-0.12.2 \
		smithay-clipboard-0.6.3 \
		socket2-0.3.19 \
		spsc-buffer-0.1.1 \
		strsim-0.8.0 \
		strsim-0.9.3 \
		syn-1.0.60 \
		textwrap-0.11.0 \
		thiserror-1.0.23 \
		thiserror-impl-1.0.23 \
		time-0.1.44 \
		toml-0.5.8 \
		ttf-parser-0.6.2 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		urlocator-0.1.4 \
		utf8parse-0.2.0 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		vswhom-0.1.0 \
		vswhom-sys-0.1.0 \
		vte-0.10.0 \
		vte_generate_state_changes-0.1.1 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wayland-client-0.28.3 \
		wayland-commons-0.28.3 \
		wayland-cursor-0.28.3 \
		wayland-egl-0.28.3 \
		wayland-protocols-0.28.3 \
		wayland-scanner-0.28.3 \
		wayland-sys-0.28.3 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winit-0.24.0 \
		winreg-0.8.0 \
		wio-0.2.2 \
		ws2_32-sys-0.2.1 \
		x11-clipboard-0.5.1 \
		x11-dl-2.18.5 \
		xcb-0.9.0 \
		xcursor-0.3.3 \
		xdg-2.2.0 \
		xml-rs-0.8.3 \
		yaml-rust-0.4.5
CARGO_USE_GITHUB=	yes
CARGO_INSTALL_PATH=	alacritty

CARGO_FEATURES+=	--no-default-features
CARGO_CARGOTOML=	${WRKSRC}/${PORTNAME}/Cargo.toml

# For xcb crate
BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/alacritty \
		etc/bash_completion.d/alacritty.bash \
		share/fish/completions/alacritty.fish \
		share/man/man1/alacritty.1.gz \
		share/pixmaps/Alacritty.svg \
		share/zsh/site-functions/_alacritty \
		${DESKTOPDIR}/Alacritty.desktop
PORTEXAMPLES=	alacritty.yml

OPTIONS_DEFINE=	EXAMPLES

BACKEND_DESC=	Display backend

OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	WAYLAND X11
OPTIONS_DEFAULT=	WAYLAND X11

WAYLAND_VARS=	CARGO_FEATURES+=wayland
X11_USES=	xorg
X11_USE=	XORG=xcb
X11_VARS=	CARGO_FEATURES+=x11

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/alacritty
	${INSTALL_DATA} ${WRKSRC}/extra/linux/Alacritty.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/logo/alacritty-term.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/Alacritty.svg
	${INSTALL_MAN} ${WRKSRC}/extra/alacritty.man \
		${STAGEDIR}${PREFIX}/share/man/man1/alacritty.1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/extra/completions/alacritty.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/extra/completions/alacritty.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/extra/completions/_alacritty \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
