# Created by: Pawel Worach <pawel.worach@gmail.com>

PORTNAME=	mutter
PORTVERSION=	41.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window and compositing manager based on Clutter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas \
		xkeyboard-config>=0:x11/xkeyboard-config \
		zenity>=3.0.0:x11/zenity
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libdrm.so:graphics/libdrm \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgraphene-1.0.so:graphics/graphene \
		libjson-glib-1.0.so:devel/json-glib \
		libpipewire-0.3.so:multimedia/pipewire \
		libstartup-notification-1.so:x11/startup-notification \
		libupower-glib.so:sysutils/upower \
		libxkbcommon.so:x11/libxkbcommon \
		libxkbfile.so:x11/libxkbfile
RUN_DEPENDS=	gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.4.0:devel/gsettings-desktop-schemas \
		xkeyboard-config>=0:x11/xkeyboard-config \
		zenity>=3.0.0:x11/zenity

PORTSCOUT=	limitw:1,even

USES=		compiler:c++0x gettext gl gnome localbase meson pkgconfig \
		tar:xz xorg
USE_GL=		egl gbm
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 introspection
USE_XORG=	ice sm x11 xcb xcomposite xcursor xdamage xext xfixes xi \
		xinerama xrandr xrender xtst
USE_LDCONFIG=	yes
CFLAGS+=	-Wno-unknown-warning-option -Wno-format-nonliteral
CPPFLAGS+=	-fno-omit-frame-pointer
MESON_ARGS=	-Dlibwacom=false \
		-Dnative_backend=false \
		-Dprofiler=false \
		-Dsm=true \
		-Dsystemd=false \
		-Dtests=false \
		-Dudev=false \
		-Dwayland=false

# Required by embedded cogl/clutter forks.
MESON_ARGS+=	-Dgles2_libname=libGLESv2 \
		-Dopengl_libname=libGL.so

# Disable remote_desktop for now because it requires memfd which only appears current
MESON_ARGS+=	-Dremote_desktop=false

GLIB_SCHEMAS=	org.gnome.mutter.gschema.xml \
		org.gnome.mutter.wayland.gschema.xml

.include <bsd.port.mk>
