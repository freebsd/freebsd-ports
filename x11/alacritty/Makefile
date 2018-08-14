# $FreeBSD$

PORTNAME=	alacritty
PORTVERSION=	g20180717
CATEGORIES=	x11

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	GPU-accelerated terminal emulator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jwilm
GH_TAGNAME=	7cc9c11
GH_TUPLE=	jwilm:rust-fontconfig:be2b94de833ec69cf767186262a5fb8360fa5b45:servofontconfig \
		jwilm:libfontconfig:5c1845e1bffa11cf4d3e6fb27f456bf5c814ce1b:servofontconfigsys

PLIST_FILES=	bin/alacritty \
		man/man1/alacritty.1.gz \
		etc/bash_completion.d/alacritty-completions.bash \
		share/fish/completions/alacritty-completions.fish \
		share/zsh/site-functions/_alacritty \
		${DESKTOPDIR:S,^${PREFIX}/,,}/alacritty.desktop

CARGO_CRATES=	aho-corasick-0.6.4 \
		android_glue-0.2.3 \
		ansi_term-0.11.0 \
		approx-0.1.1 \
		arraydeque-0.4.2 \
		atty-0.2.10 \
		base64-0.9.2 \
		bitflags-0.4.0 \
		bitflags-0.7.0 \
		bitflags-0.8.2 \
		bitflags-1.0.3 \
		block-0.1.6 \
		byteorder-1.2.3 \
		bytes-0.3.0 \
		cc-1.0.17 \
		cfg-if-0.1.3 \
		cgl-0.2.2 \
		cgmath-0.16.1 \
		clap-2.31.2 \
		cmake-0.1.31 \
		cocoa-0.15.0 \
		core-foundation-0.5.1 \
		core-foundation-0.6.0 \
		core-foundation-sys-0.5.1 \
		core-foundation-sys-0.6.0 \
		core-graphics-0.13.0 \
		core-graphics-0.14.0 \
		core-text-9.2.0 \
		dlib-0.4.1 \
		downcast-rs-1.0.3 \
		dtoa-0.4.2 \
		env_logger-0.5.10 \
		errno-0.2.3 \
		euclid-0.17.3 \
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
		gl_generator-0.9.0 \
		gleam-0.5.1 \
		glutin-0.16.0 \
		humantime-1.1.1 \
		inotify-0.3.0 \
		iovec-0.1.2 \
		itoa-0.4.1 \
		kernel32-sys-0.2.2 \
		khronos_api-2.2.0 \
		lazy_static-1.0.1 \
		lazycell-0.4.0 \
		lazycell-0.6.0 \
		libc-0.2.42 \
		libloading-0.5.0 \
		libz-sys-1.0.18 \
		linked-hash-map-0.5.1 \
		log-0.3.9 \
		log-0.4.2 \
		malloc_buf-0.0.6 \
		memchr-2.0.1 \
		memmap-0.6.2 \
		mio-0.5.1 \
		mio-0.6.14 \
		mio-more-0.1.0 \
		miow-0.1.5 \
		miow-0.2.1 \
		net2-0.2.32 \
		nix-0.11.0 \
		nix-0.5.1 \
		notify-4.0.3 \
		num-traits-0.1.43 \
		num-traits-0.2.4 \
		objc-0.2.2 \
		objc-foundation-0.1.1 \
		objc_id-0.1.0 \
		osmesa-sys-0.1.2 \
		owning_ref-0.3.3 \
		parking_lot-0.5.5 \
		parking_lot_core-0.2.14 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.11 \
		proc-macro2-0.4.6 \
		quick-error-1.2.2 \
		quote-0.6.3 \
		rand-0.4.2 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-1.0.0 \
		regex-syntax-0.6.1 \
		remove_dir_all-0.5.1 \
		safemem-0.2.0 \
		same-file-1.0.2 \
		serde-1.0.66 \
		serde_derive-1.0.66 \
		serde_json-1.0.20 \
		serde_yaml-0.7.5 \
		shared_library-0.1.8 \
		slab-0.1.3 \
		slab-0.3.0 \
		slab-0.4.0 \
		smallvec-0.6.1 \
		smithay-client-toolkit-0.2.3 \
		stable_deref_trait-1.1.0 \
		static_assertions-0.2.5 \
		strsim-0.7.0 \
		syn-0.14.2 \
		tempfile-3.0.2 \
		termcolor-0.3.6 \
		termion-1.5.1 \
		textwrap-0.9.0 \
		thread_local-0.3.5 \
		time-0.1.40 \
		ucd-util-0.1.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		utf8parse-0.1.0 \
		vcpkg-0.2.3 \
		vec_map-0.8.1 \
		void-1.0.2 \
		vte-0.3.2 \
		walkdir-2.1.4 \
		wayland-client-0.20.10 \
		wayland-commons-0.20.10 \
		wayland-protocols-0.20.10 \
		wayland-scanner-0.20.10 \
		wayland-sys-0.20.10 \
		winapi-0.2.8 \
		winapi-0.3.5 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-0.1.6 \
		winit-0.15.1 \
		ws2_32-sys-0.2.1 \
		x11-dl-2.18.0 \
		xdg-2.1.0 \
		xml-rs-0.7.0 \
		yaml-rust-0.4.0
CARGO_USE_GITHUB=	yes
CARGO_GH_CARGOTOML=	${CARGO_CARGOTOML} \
			${WRKSRC}/font/Cargo.toml \
			${WRKSRC_servofontconfig}/Cargo.toml

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/alacritty
	${INSTALL_DATA} ${WRKSRC}/alacritty.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_MAN} ${WRKSRC}/alacritty.man ${STAGEDIR}${MANPREFIX}/man/man1/alacritty.1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/alacritty-completions.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/alacritty-completions.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/alacritty-completions.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_alacritty

.include <bsd.port.mk>
