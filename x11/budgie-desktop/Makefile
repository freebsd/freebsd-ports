PORTNAME=	budgie-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	10.9.3
CATEGORIES=	x11 budgie
MASTER_SITES=	BUDGIE

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Modern and familiar desktop environment
WWW=		https://github.com/BuddiesOfBudgie/budgie-desktop

LICENSE=		GPLv2 LGPL21
LICENSE_COMB=		multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE.LGPL2.1

BUILD_DEPENDS=	gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		sassc:textproc/sassc \
		zenity:x11/zenity
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
		libgee-0.8.so:devel/libgee \
		libgudev-1.0.so:devel/libgudev
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		budgie-session>0:x11/budgie-session \
		consolekit2>0:sysutils/consolekit2 \
		zenity:x11/zenity \
		xdotool:x11/xdotool \
		matcha-gtk-themes>0:x11-themes/matcha-gtk-themes \
		xdg-desktop-portal-gtk>0:x11/xdg-desktop-portal-gtk

USES=		budgie gettext-tools gnome gstreamer meson pkgconfig \
		tar:xz vala:build xfce xorg
USE_BUDGIE=	libmagpie screensaver:build
USE_GNOME=	cairo gdkpixbuf glib20 gnomedesktop3 gnomemenus3 \
		gtk30 intltool:build introspection libwnck3
USE_GSTREAMER=	libgstreamer
USE_XFCE=	windowing
USE_XORG=	x11 xext xfixes xi xorgproto

MESON_ARGS=	-Dwith-gtk-doc=false \
		-Dwith-bluetooth=false \
		-Dwith-hibernate=false

# As long as x11/gtk30 is required, we depend of x11/zenity
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
		org.buddiesofbudgie.settings-daemon.plugins.media-keys.gschema.xml \
		25_org.buddiesofbudgie-default-settings.gschema.override

NO_SHLIB_REQUIRES_GLOB=	libmagpie-clutter-* libmagpie-cogl-*

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
