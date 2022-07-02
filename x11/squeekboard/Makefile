PORTNAME=	squeekboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.1
PORTREVISION=	3
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	On-screen keyboard for Wayland

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_12_powerpc64=	fails to compile: rs.e2mg9us3-cgu.14:(.text.imservice_handle_commit_state+0x228): undefined reference to 'eekboard_context_service_show_keyboard'
BROKEN_FreeBSD_13_powerpc64=	fails to link: ld: error: undefined symbol: eekboard_context_service_get_overlay

BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
LIB_DEPENDS=	libfeedback-0.0.so:accessibility/feedbackd \
		libwayland-client.so:graphics/wayland \
		libcroco-0.6.so:textproc/libcroco \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		cargo compiler:c11 gettext-tools gnome meson pkgconfig python:build shebangfix
USE_GITLAB=	yes
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 gtk30
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/Phosh
GL_COMMIT=	2faa98d85f1142383ec8ad1487616c1a7ad1882f
SHEBANG_FILES=	tools/entry.py
MAKE_ENV=	${CARGO_ENV}
MESON_ARGS=	-Dstrict=false
MESON_ARGS+=	-Donline=false # XXX Cargo.lock
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-entry \
		bin/${PORTNAME}-test-layout \
		share/applications/sm.puri.Squeekboard.desktop \
		share/locale/ca/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/de/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/fa/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/fi/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/fur/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/gl/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/he/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/nl/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/pt_BR/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/ro/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/sl/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/sv/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/uk/LC_MESSAGES/${PORTNAME}.mo \
		${NULL}

CARGO_CRATES=	atk-0.7.0 \
		atk-sys-0.9.1 \
		autocfg-1.1.0 \
		bitflags-1.2.1 \
		cairo-rs-0.7.1 \
		cairo-sys-rs-0.9.2 \
		cc-1.0.73 \
		clap-2.33.4 \
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
		hashbrown-0.11.2 \
		indexmap-1.8.0 \
		lazy_static-1.4.0 \
		libc-0.2.119 \
		linked-hash-map-0.5.4 \
		maplit-1.0.2 \
		memmap-0.7.0 \
		pango-0.7.0 \
		pango-sys-0.9.1 \
		pkg-config-0.3.24 \
		proc-macro2-1.0.36 \
		quote-1.0.15 \
		ryu-1.0.9 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_yaml-0.8.23 \
		syn-1.0.86 \
		textwrap-0.11.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
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
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e '/^cargo/s/"$$@"/--verbose --verbose &/' \
		${WRKSRC}/cargo.sh

post-configure:
# Provide preprocessed Cargo.toml for USES=cargo
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC} Cargo.toml

.include <bsd.port.mk>
