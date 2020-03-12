# $FreeBSD$

PORTNAME=	squeekboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	On-screen keyboard for Wayland

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_11=	requires getrandom()

BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libcroco-0.6.so:textproc/libcroco \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		cargo compiler:c11 gettext-tools gnome meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 gtk30
GL_SITE=	https://source.puri.sm
GL_ACCOUNT=	Librem5
GL_COMMIT=	930f5be0c86d33ae39aa5c65babffd3e7420b81e
MAKE_ENV=	${CARGO_ENV}
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-entry \
		bin/${PORTNAME}-test-layout \
		share/applications/sm.puri.Squeekboard.desktop

CARGO_CRATES=	aho-corasick-0.7.8 \
		atk-sys-0.7.0 \
		bitflags-1.0.4 \
		cairo-rs-0.5.0 \
		cairo-sys-rs-0.7.0 \
		cc-1.0.50 \
		clap-2.32.0 \
		dtoa-0.4.5 \
		fragile-0.3.0 \
		gdk-0.9.0 \
		gdk-pixbuf-0.5.0 \
		gdk-pixbuf-sys-0.7.0 \
		gdk-sys-0.7.0 \
		gio-0.5.1 \
		gio-sys-0.7.0 \
		glib-0.6.1 \
		glib-sys-0.7.0 \
		gobject-sys-0.7.0 \
		gtk-0.5.0 \
		gtk-sys-0.7.0 \
		lazy_static-1.4.0 \
		libc-0.2.66 \
		linked-hash-map-0.5.2 \
		maplit-1.0.2 \
		memchr-2.3.2 \
		memmap-0.7.0 \
		pango-0.5.0 \
		pango-sys-0.7.0 \
		pkg-config-0.3.17 \
		proc-macro2-1.0.8 \
		quote-1.0.2 \
		regex-1.1.9 \
		regex-syntax-0.6.14 \
		serde-1.0.104 \
		serde_derive-1.0.104 \
		serde_yaml-0.8.11 \
		syn-1.0.14 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		utf8-ranges-1.0.4 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xkbcommon-0.4.0 \
		yaml-rust-0.4.3
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

post-patch:
# Add --verbose after each cargo subcommand
# Don't use BSD realpath(1) against non-existing files
	@${REINPLACE_CMD} -e '/^cargo/ { \
		  s,^,cmd=$$1; shift; ,; \
		  s,"$$@","$$cmd" --verbose &,; }' \
		-e '/OUT_PATH=/s,=.*,=$$PWD/$$1,' \
		${WRKSRC}/cargo*.sh

.include <bsd.port.mk>
