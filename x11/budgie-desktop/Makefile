PORTNAME=	budgie-desktop
DISTVERSION=	10.8.2
PORTREVISION=	6
DISTVERSIONPREFIX=	v
CATEGORIES=	x11 budgie
MASTER_SITES=	BUDGIE

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Modern and familiar desktop environment
WWW=		https://github.com/BuddiesOfBudgie/budgie-desktop

LICENSE_COMB=	multi
LICENSE=	GPLv2 LGPL21

BUILD_DEPENDS=	gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		sassc:textproc/sassc \
		zenity>0:x11/zenity
LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit \
		libpeas-1.0.so:devel/libpeas1 \
		libuuid.so:misc/libuuid \
		libnotify.so:devel/libnotify \
		libaccountsservice.so:sysutils/accountsservice \
		libpulse.so:audio/pulseaudio \
		libasound.so:audio/alsa-lib \
		libgraphene-1.0.so:graphics/graphene \
		libupower-glib.so:sysutils/upower \
		libibus-1.0.so:textproc/ibus \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libgee-0.8.so:devel/libgee
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		gnome-session>0:x11/gnome-session \
		consolekit2>0:sysutils/consolekit2 \
		zenity>0:x11/zenity \
		xdotool>0:x11/xdotool

USES=		budgie gettext gnome gstreamer meson pkgconfig tar:xz \
		vala:build xorg
USE_BUDGIE=	libmagpie screensaver:build
USE_GNOME=	cairo gdkpixbuf glib20 gnomedesktop3 gnomemenus3 \
		gtk30 intltool introspection libwnck3
USE_GSTREAMER=	libgstreamer
USE_XORG=	x11 xcomposite

MESON_ARGS=	-Dwith-gtk-doc=false \
		-Dwith-bluetooth=false \
		-Dwith-hibernate=false \
		-Dwith-libuuid-time-safe=false

# If zenity >= 3.90 → build against Gtk4 (new API)
MESON_ARGS+=	-Duse-old-zenity=true

GLIB_SCHEMAS=	20_buddiesofbudgie.budgie-desktop.notifications.gschema.override \
		20_solus-project.budgie.wm.gschema.override \
		com.solus-project.budgie-menu.gschema.xml \
		com.solus-project.budgie-panel.gschema.xml \
		com.solus-project.budgie.raven.gschema.xml \
		com.solus-project.budgie.wm.gschema.xml \
		com.solus-project.clock.gschema.xml \
		com.solus-project.icon-tasklist.gschema.xml \
		com.solus-project.places-indicator.gschema.xml \
		com.solus-project.spacer.gschema.xml \
		com.solus-project.status.gschema.xml \
		com.solus-project.trash.gschema.xml \
		com.solus-project.tray.gschema.xml \
		com.solus-project.workspaces.gschema.xml \
		org.buddiesofbudgie.budgie-desktop.raven.widget.Calendar.gschema.xml \
		org.buddiesofbudgie.budgie-desktop.raven.widget.SoundInput.gschema.xml \
		org.buddiesofbudgie.budgie-desktop.raven.widget.SoundOutput.gschema.xml \
		org.buddiesofbudgie.budgie-desktop.raven.widget.UsageMonitor.gschema.xml \
		org.buddiesofbudgie.budgie-desktop.screenshot.gschema.xml \
		25_org.buddiesofbudgie-default-settings.gschema.override

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-extract:
	${CP} ${FILESDIR}/25_org.buddiesofbudgie-default-settings.gschema.override \
		${WRKSRC}/data

post-patch:
	${REINPLACE_CMD} -i "" -e 's|%%PREFIX%%|${LOCALBASE}|g' \
		${WRKSRC}/src/wm/20_solus-project.budgie.wm.gschema.override
	${REINPLACE_CMD} -i "" -e 's|start-here|view-grid|'  \
		${WRKSRC}/src/panel/applets/budgie-menu/com.solus-project.budgie-menu.gschema.xml

.include <bsd.port.mk>
