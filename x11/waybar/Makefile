# $FreeBSD$

PORTNAME=	waybar
DISTVERSION=	0.9.0
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
# https://github.com/Alexays/Waybar/pull/425
PATCHFILES+=	2e9d80139411.patch:-p1
PATCHFILES+=	9ba4bfcb20f2.patch:-p1
PATCHFILES+=	2155d9560887.patch:-p1
PATCHFILES+=	abc17ff5393c.patch:-p1
PATCHFILES+=	d3ad69814f28.patch:-p1
PATCHFILES+=	4ceefa8ed4d9.patch:-p1
PATCHFILES+=	7675d81f3205.patch:-p1
PATCHFILES+=	4a151db3a433.patch:-p1
PATCHFILES+=	e9263a38841b.patch:-p1
PATCHFILES+=	acb51ccef3ab.patch:-p1
PATCHFILES+=	6349d48af076.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Highly customizable Wayland bar for Sway and wlroots-based compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	spdlog>0:devel/spdlog \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp \
		libfmt.so:devel/libfmt \
		libwayland-client.so:graphics/wayland

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30
GH_ACCOUNT=	Alexays
GH_PROJECT=	Waybar
CPPFLAGS+=	-D_WITH_GETLINE # XXX Remove after FreeBSD 11 EOL
PLIST_FILES=	bin/${PORTNAME} \
		etc/xdg/${PORTNAME}/config \
		etc/xdg/${PORTNAME}/style.css

OPTIONS_DEFINE=	DBUS GLS MANPAGES MPD PULSEAUDIO UDEV
OPTIONS_DEFAULT=DBUS GLS MANPAGES MPD PULSEAUDIO UDEV

DBUS_LIB_DEPENDS=	libdbusmenu-gtk3.so:devel/libdbusmenu
DBUS_MESON_ENABLED=	dbusmenu-gtk

GLS_DESC=		Use gtk-layer-shell library for popups support
GLS_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
GLS_MESON_ENABLED=	gtk-layer-shell

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man5/${PORTNAME}-backlight.5.gz \
			man/man5/${PORTNAME}-battery.5.gz \
			man/man5/${PORTNAME}-clock.5.gz \
			man/man5/${PORTNAME}-cpu.5.gz \
			man/man5/${PORTNAME}-custom.5.gz \
			man/man5/${PORTNAME}-disk.5.gz \
			man/man5/${PORTNAME}-idle-inhibitor.5.gz \
			man/man5/${PORTNAME}-memory.5.gz \
			man/man5/${PORTNAME}-mpd.5.gz \
			man/man5/${PORTNAME}-network.5.gz \
			man/man5/${PORTNAME}-pulseaudio.5.gz \
			man/man5/${PORTNAME}-states.5.gz \
			man/man5/${PORTNAME}-sway-mode.5.gz \
			man/man5/${PORTNAME}-sway-window.5.gz \
			man/man5/${PORTNAME}-sway-workspaces.5.gz \
			man/man5/${PORTNAME}-temperature.5.gz \
			man/man5/${PORTNAME}-tray.5.gz \
			man/man5/${PORTNAME}.5.gz \

MPD_DESC=		Music Player Daemon support
MPD_LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient
MPD_MESON_ENABLED=	mpd

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	pulseaudio

UDEV_DESC=		Monitor backlight level via libudev
UDEV_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libudev.so:devel/libudev-devd
UDEV_MESON_ENABLED=	libudev

.include <bsd.port.mk>
