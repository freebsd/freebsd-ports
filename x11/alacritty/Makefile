PORTNAME=	alacritty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.2
PORTREVISION=	5
CATEGORIES=	x11 wayland

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	GPU-accelerated terminal emulator
WWW=		https://alacritty.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon
TEST_DEPENDS=	dejavu>0:x11-fonts/dejavu

USES=		cargo localbase:ldflags python:build
USE_GITHUB=	yes

CARGO_CRATES=	adler-1.0.2 \
		android-activity-0.4.0 \
		android-properties-0.2.2 \
		arrayref-0.3.6 \
		arrayvec-0.7.2 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		block-0.1.6 \
		block-sys-0.1.0-beta.1 \
		block2-0.2.0-alpha.6 \
		bumpalo-3.12.0 \
		bytemuck-1.12.1 \
		calloop-0.10.4 \
		cc-1.0.73 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		cfg_aliases-0.1.1 \
		cgl-0.3.2 \
		clap-3.2.21 \
		clap_complete-3.2.5 \
		clap_derive-3.2.18 \
		clap_lex-0.2.4 \
		clipboard-win-3.1.1 \
		cmake-0.1.48 \
		cocoa-0.24.0 \
		cocoa-foundation-0.1.0 \
		copypasta-0.8.2 \
		core-foundation-0.9.3 \
		core-foundation-sys-0.8.3 \
		core-graphics-0.22.3 \
		core-graphics-types-0.1.1 \
		core-text-19.2.0 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.6 \
		crossbeam-utils-0.8.12 \
		crossfont-0.5.1 \
		cty-0.2.2 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		dispatch-0.2.0 \
		dlib-0.5.0 \
		downcast-rs-1.2.0 \
		dwrote-0.11.0 \
		embed-resource-1.7.3 \
		expat-sys-2.1.6 \
		filetime-0.2.17 \
		flate2-1.0.24 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.2 \
		foreign-types-shared-0.1.1 \
		foreign-types-shared-0.3.1 \
		freetype-rs-0.26.0 \
		freetype-sys-0.13.1 \
		fsevent-sys-4.1.0 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		gethostname-0.2.3 \
		getrandom-0.2.7 \
		gl_generator-0.14.0 \
		glutin-0.30.9 \
		glutin_egl_sys-0.5.0 \
		glutin_glx_sys-0.4.0 \
		glutin_wgl_sys-0.4.0 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.9.1 \
		inotify-0.9.6 \
		inotify-sys-0.1.5 \
		instant-0.1.12 \
		iovec-0.1.4 \
		itoa-1.0.3 \
		jni-sys-0.3.0 \
		jobserver-0.1.25 \
		js-sys-0.3.60 \
		kernel32-sys-0.2.2 \
		khronos_api-3.1.0 \
		kqueue-1.0.7 \
		kqueue-sys-1.0.3 \
		lazy-bytes-cast-5.0.1 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.132 \
		libloading-0.7.3 \
		linked-hash-map-0.5.6 \
		lock_api-0.4.8 \
		log-0.4.17 \
		malloc_buf-0.0.6 \
		memchr-2.5.0 \
		memmap2-0.5.10 \
		memoffset-0.6.5 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.5.4 \
		mio-0.6.23 \
		mio-0.8.4 \
		mio-anonymous-pipes-0.2.0 \
		mio-extras-2.0.6 \
		mio-uds-0.6.8 \
		miow-0.2.2 \
		miow-0.3.7 \
		ndk-0.7.0 \
		ndk-context-0.1.1 \
		ndk-sys-0.4.1+23.1.7779620 \
		net2-0.2.37 \
		nix-0.24.2 \
		nix-0.25.1 \
		nom-7.1.1 \
		notify-5.1.0 \
		num_enum-0.5.7 \
		num_enum_derive-0.5.7 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc-sys-0.2.0-beta.2 \
		objc2-0.3.0-beta.3.patch-leaks.2 \
		objc2-encode-2.0.0-pre.2 \
		objc_id-0.1.1 \
		once_cell-1.14.0 \
		orbclient-0.3.42 \
		os_str_bytes-6.3.0 \
		parking_lot-0.11.2 \
		parking_lot-0.12.1 \
		parking_lot_core-0.8.5 \
		parking_lot_core-0.9.3 \
		percent-encoding-2.2.0 \
		pkg-config-0.3.25 \
		png-0.17.6 \
		proc-macro-crate-1.2.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.43 \
		quote-1.0.21 \
		raw-window-handle-0.5.0 \
		redox_syscall-0.2.16 \
		redox_syscall-0.3.4 \
		redox_users-0.4.3 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.27 \
		rustc_version-0.4.0 \
		ryu-1.0.11 \
		same-file-1.0.6 \
		scoped-tls-1.0.0 \
		scopeguard-1.1.0 \
		sctk-adwaita-0.5.4 \
		semver-1.0.14 \
		serde-1.0.144 \
		serde_derive-1.0.144 \
		serde_json-1.0.85 \
		serde_yaml-0.8.26 \
		servo-fontconfig-0.5.1 \
		servo-fontconfig-sys-5.1.0 \
		signal-hook-0.3.14 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.0 \
		slab-0.4.7 \
		slotmap-1.0.6 \
		smallvec-1.9.0 \
		smithay-client-toolkit-0.16.0 \
		smithay-clipboard-0.6.6 \
		spsc-buffer-0.1.1 \
		strict-num-0.1.0 \
		strsim-0.10.0 \
		syn-1.0.99 \
		termcolor-1.1.3 \
		textwrap-0.15.1 \
		thiserror-1.0.35 \
		thiserror-impl-1.0.35 \
		tiny-skia-0.8.3 \
		tiny-skia-path-0.8.3 \
		toml-0.5.8 \
		unicode-ident-1.0.4 \
		unicode-width-0.1.10 \
		utf8parse-0.2.0 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		vswhom-0.1.0 \
		vswhom-sys-0.1.1 \
		vte-0.10.1 \
		vte_generate_state_changes-0.1.1 \
		walkdir-2.3.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.83 \
		wasm-bindgen-backend-0.2.83 \
		wasm-bindgen-macro-0.2.83 \
		wasm-bindgen-macro-support-0.2.83 \
		wasm-bindgen-shared-0.2.83 \
		wayland-client-0.29.5 \
		wayland-commons-0.29.5 \
		wayland-cursor-0.29.5 \
		wayland-protocols-0.29.5 \
		wayland-scanner-0.29.5 \
		wayland-sys-0.29.5 \
		wayland-sys-0.30.0 \
		web-sys-0.3.60 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-wsapoll-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows-sys-0.42.0 \
		windows-sys-0.45.0 \
		windows-targets-0.42.1 \
		windows_aarch64_gnullvm-0.42.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_aarch64_msvc-0.42.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_gnu-0.42.1 \
		windows_i686_msvc-0.36.1 \
		windows_i686_msvc-0.42.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_gnu-0.42.1 \
		windows_x86_64_gnullvm-0.42.1 \
		windows_x86_64_msvc-0.36.1 \
		windows_x86_64_msvc-0.42.1 \
		winit-0.28.6 \
		winreg-0.10.1 \
		wio-0.2.2 \
		ws2_32-sys-0.2.1 \
		x11-clipboard-0.7.1 \
		x11-dl-2.20.0 \
		x11rb-0.10.1 \
		x11rb-protocol-0.10.0 \
		xcursor-0.3.4 \
		xdg-2.4.1 \
		xml-rs-0.8.4 \
		yaml-rust-0.4.5
CARGO_INSTALL_PATH=	alacritty

CARGO_FEATURES+=	--no-default-features
CARGO_CARGOTOML=	${WRKSRC}/${PORTNAME}/Cargo.toml

# For xcb crate
BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/alacritty \
		etc/bash_completion.d/alacritty.bash \
		share/fish/completions/alacritty.fish \
		share/man/man1/alacritty-msg.1.gz \
		share/man/man1/alacritty.1.gz \
		share/metainfo/org.alacritty.Alacritty.appdata.xml \
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/extra/linux/org.alacritty.Alacritty.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_MAN} ${WRKSRC}/extra/alacritty.man \
		${STAGEDIR}${PREFIX}/share/man/man1/alacritty.1
	${INSTALL_MAN} ${WRKSRC}/extra/alacritty-msg.man \
		${STAGEDIR}${PREFIX}/share/man/man1/alacritty-msg.1
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
