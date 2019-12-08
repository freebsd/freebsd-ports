# $FreeBSD$

PORTNAME=	waybar
DISTVERSION=	0.8.0
PORTREVISION=	3
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
# https://github.com/Alexays/Waybar/pull/425
PATCHFILES+=	a85ae0da0580.patch:-p1
PATCHFILES+=	f0dfa34e651c.patch:-p1
PATCHFILES+=	25d4420904bd.patch:-p1
PATCHFILES+=	bf0d2621504e.patch:-p1
PATCHFILES+=	82844ce8a6f3.patch:-p1
PATCHFILES+=	7bc3577137af.patch:-p1
PATCHFILES+=	96ef80d06c00.patch:-p1
PATCHFILES+=	cf114a111fe0.patch:-p1
PATCHFILES+=	684d9121a721.patch:-p1
PATCHFILES+=	f1b288adf8b5.patch:-p1
# https://github.com/Alexays/Waybar/pull/???
PATCHFILES+=	0b008154d9de.patch:-p1

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

OPTIONS_DEFINE=	DBUS MANPAGES MPD PULSEAUDIO UDEV
OPTIONS_DEFAULT=DBUS MANPAGES MPD PULSEAUDIO UDEV

DBUS_LIB_DEPENDS=	libdbusmenu-gtk3.so:devel/libdbusmenu
DBUS_MESON_ENABLED=	dbusmenu-gtk

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man5/${PORTNAME}-backlight.5.gz \
			man/man5/${PORTNAME}-battery.5.gz \
			man/man5/${PORTNAME}-clock.5.gz \
			man/man5/${PORTNAME}-cpu.5.gz \
			man/man5/${PORTNAME}-custom.5.gz \
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
