PORTNAME=	squeekboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0
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
GL_COMMIT=	8aefae9634778402a4fea776ad40f20296f63e34
MAKE_ENV=	${CARGO_ENV}
MESON_ARGS=	-Dstrict=false
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-entry \
		bin/${PORTNAME}-test-layout \
		share/applications/sm.puri.Squeekboard.desktop

CARGO_CRATES=	atk-0.7.0 \
		atk-sys-0.9.1 \
		bitflags-1.2.1 \
		cairo-rs-0.7.1 \
		cairo-sys-rs-0.9.2 \
		cc-1.0.67 \
		clap-2.33.3 \
		dtoa-0.4.8 \
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
		libc-0.2.93 \
		linked-hash-map-0.5.4 \
		maplit-1.0.2 \
		memmap-0.7.0 \
		pango-0.7.0 \
		pango-sys-0.9.1 \
		pkg-config-0.3.19 \
		proc-macro2-1.0.26 \
		quote-1.0.9 \
		regex-1.3.9 \
		regex-syntax-0.6.23 \
		serde-1.0.125 \
		serde_derive-1.0.125 \
		serde_yaml-0.8.17 \
		syn-1.0.69 \
		textwrap-0.11.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xkbcommon-0.4.0 \
		yaml-rust-0.4.5
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
TARGET_ORDER_OVERRIDE=	750:cargo-configure
CARGO_CARGOTOML=	${BUILD_WRKSRC}/Cargo.toml

post-patch:
# Add --verbose after each cargo subcommand
	@${REINPLACE_CMD} -e '/^cargo/s/"$$@"/--verbose &/' \
		${WRKSRC}/cargo.sh

post-configure:
# Provide preprocessed Cargo.toml for USES=cargo
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC} Cargo.toml

.include <bsd.port.mk>
