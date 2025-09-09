PORTNAME=	magpie
DISTVERSION=	0.9.4
CATEGORIES=	x11-wm budgie
MASTER_SITES=	BUDGIE

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	X11 window manager and compositor library for Budgie desktop
WWW=		https://github.com/BuddiesOfBudgie/magpie

LICENSE=	GPLv2+

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		xkeyboard-config>0:x11/xkeyboard-config
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libgudev-1.0.so:devel/libgudev \
		libdrm.so:graphics/libdrm \
		libinput.so:x11/libinput \
		libgbm.so:graphics/mesa-libs \
		libfontconfig.so:x11-fonts/fontconfig \
		libfribidi.so:converters/fribidi \
		libgraphene-1.0.so:graphics/graphene \
		libjson-glib-1.0.so:devel/json-glib \
		libstartup-notification-1.so:x11/startup-notification \
		libupower-glib.so:sysutils/upower \
		libxkbcommon.so:x11/libxkbcommon \
		liblcms2.so:graphics/lcms2 \
		libdbus-1.so:devel/dbus \
		libcolord.so:graphics/colord
RUN_DEPENDS=	gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		xkeyboard-config>0:x11/xkeyboard-config

USES=		budgie compiler:c++0x gettext-tools gl gnome localbase meson \
		pkgconfig python:build shebangfix tar:xz xorg
USE_GL=		egl gbm
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 introspection:build
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xau xcb xcomposite xcursor xdamage xext xfixes xi \
		xinerama xkbfile xrandr xrender xtst
MESON_ARGS=	-Dsystemd=false \
		-Dnative_backend=false \
		-Dremote_desktop=false \
		-Dlibwacom=false \
		-Dprofiler=false
CFLAGS+=	-Wno-format-nonliteral
CPPFLAGS+=	-fno-omit-frame-pointer
SHEBANG_FILES=	tools/get-state.py

.include <bsd.port.mk>
