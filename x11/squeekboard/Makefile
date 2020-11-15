# $FreeBSD$

PORTNAME=	squeekboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	On-screen keyboard for Wayland

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_11=	requires getrandom()
BROKEN_FreeBSD_12_powerpc64=	fails to compile: rs.e2mg9us3-cgu.14:(.text.imservice_handle_commit_state+0x228): undefined reference to 'eekboard_context_service_show_keyboard'
BROKEN_FreeBSD_13_powerpc64=	fails to link: ld: error: undefined symbol: eekboard_context_service_get_overlay

BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
LIB_DEPENDS=	libfeedback-0.0.so:accessibility/feedbackd \
		libwayland-client.so:graphics/wayland \
		libcroco-0.6.so:textproc/libcroco \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		cargo compiler:c11 gettext-tools gnome meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 gtk30
GL_SITE=	https://source.puri.sm
GL_ACCOUNT=	Librem5
GL_COMMIT=	5aa73347877d1a716d9e668533ae96123d50bf56
MAKE_ENV=	${CARGO_ENV}
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-entry \
		bin/${PORTNAME}-test-layout \
		share/applications/sm.puri.Squeekboard.desktop

CARGO_CRATES=	atk-0.7.0 \
		atk-sys-0.9.1 \
		bitflags-1.2.1 \
		cairo-rs-0.7.1 \
		cairo-sys-rs-0.9.2 \
		cc-1.0.62 \
		clap-2.33.3 \
		dtoa-0.4.6 \
		fragile-0.3.0 \
		gdk-0.11.0 \
		gdk-pixbuf-0.7.0 \
		gdk-pixbuf-sys-0.9.1 \
		gdk-sys-0.9.1 \
		gio-0.7.0 \
		gio-sys-0.9.1 \
		glib-0.8.2 \
		glib-sys-0.9.1 \
		gobject-sys-0.9.1 \
		gtk-0.7.0 \
		gtk-sys-0.9.2 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		linked-hash-map-0.5.3 \
		maplit-1.0.2 \
		memmap-0.7.0 \
		pango-0.7.0 \
		pango-sys-0.9.1 \
		pkg-config-0.3.19 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		regex-1.3.9 \
		regex-syntax-0.6.21 \
		serde-1.0.117 \
		serde_derive-1.0.117 \
		serde_yaml-0.8.14 \
		syn-1.0.48 \
		textwrap-0.11.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xkbcommon-0.4.0 \
		yaml-rust-0.4.4
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
TARGET_ORDER_OVERRIDE=	750:cargo-configure
CARGO_CARGOTOML=	${BUILD_WRKSRC}/Cargo.toml

post-patch:
# Add --verbose after each cargo subcommand
# Recognize --release even if not passed as 1st argument
# Don't use BSD realpath(1) against non-existing files
	@${REINPLACE_CMD} -e '/^cargo/s/"$$@"/--verbose &/' \
		${"${CARGO_BUILD_ARGS:M--release}":?-e '/^BINARY_DIR/s/debug/release/':} \
		-e '/OUT_PATH=/s,=.*,=$$PWD/$$1,' \
		${WRKSRC}/cargo*.sh

post-configure:
# Provide preprocessed Cargo.toml for USES=cargo
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC} Cargo.toml

.include <bsd.port.mk>
