# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$

PORTNAME=	mutter
PORTVERSION=	3.36.6
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window and compositing manager based on Clutter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zenity>=3.0.0:x11/zenity \
		xkeyboard-config>=0:x11/xkeyboard-config \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas \
		gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libfribidi.so:converters/fribidi \
		libxkbcommon.so:x11/libxkbcommon \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libupower-glib.so:sysutils/upower \
		libjson-glib-1.0.so:devel/json-glib \
		libxkbfile.so:x11/libxkbfile \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libdrm.so:graphics/libdrm \
		libpipewire-0.3.so:multimedia/pipewire \
		libgraphene-1.0.so:graphics/graphene
RUN_DEPENDS=	zenity>=3.0.0:x11/zenity \
		xkeyboard-config>=0:x11/xkeyboard-config \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas \
		gnome-settings-daemon>0:sysutils/gnome-settings-daemon

PORTSCOUT=	limitw:1,even

USES=		compiler:c++0x gettext gl gnome localbase meson \
		pkgconfig tar:xz xorg
USE_GL=		egl gbm
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 introspection
USE_XORG=	ice sm x11 xcb xcomposite xcursor xdamage xext xfixes \
		xi xinerama xrandr xrender xtst
USE_LDCONFIG=	yes
CFLAGS+=	-Wno-unknown-warning-option \
		-Wno-format-nonliteral
CPPFLAGS+=	-fno-omit-frame-pointer
MESON_ARGS=	-Dlibwacom=false \
		-Dwayland=false \
		-Dudev=false \
		-Dnative_backend=false \
		-Dprofiler=false \
		-Dtests=false \
		-Dsm=true

# Required by embedded cogl/clutter forks.
MESON_ARGS+=	-Dopengl_libname=libGL.so \
		-Dgles2_libname=libGLESv2

# Disable remote_desktop for now because it requires memfd which only appears current
MESON_ARGS+=	-Dremote_desktop=false

GLIB_SCHEMAS=	org.gnome.mutter.gschema.xml \
		org.gnome.mutter.wayland.gschema.xml

.include <bsd.port.mk>
