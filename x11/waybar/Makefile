# $FreeBSD$

PORTNAME=	waybar
DISTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
# https://github.com/Alexays/Waybar/pull/425
PATCHFILES+=	903b8a9ceb9f.patch:-p1
PATCHFILES+=	db1d7e4dc8e9.patch:-p1
PATCHFILES+=	f9bcb7ecc4c4.patch:-p1
PATCHFILES+=	e704078a2203.patch:-p1
PATCHFILES+=	11ce516b45ba.patch:-p1
PATCHFILES+=	d2ba72fb4ec7.patch:-p1
PATCHFILES+=	3281701b98ae.patch:-p1
PATCHFILES+=	ff6decbf39ca.patch:-p1
PATCHFILES+=	f74df748da05.patch:-p1
PATCHFILES+=	212195c96548.patch:-p1
PATCHFILES+=	f73e03b563af.patch:-p1
PATCHFILES+=	83f3cb042457.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Highly customizable Wayland bar for Sway and wlroots-based compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libtz.so:devel/date \
		libjsoncpp.so:devel/jsoncpp \
		libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog \
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

# XXX Add pkg-config support to devel/date
.if exists(${.CURDIR}/files/date.pc.in)
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${WRKDIR}"
SUB_FILES+=	date.pc
post-patch:	apply-slist
.endif

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

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
