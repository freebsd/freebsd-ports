PORTNAME=	muffin
PORTVERSION=	5.4.5
PORTREVISION=	3
CATEGORIES=	x11-wm gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Compositing window manager forked from Mutter for use with Cinnamon
WWW=		https://github.com/linuxmint/muffin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:x11/xkeyboard-config \
		${LOCALBASE}/include/EGL/eglmesaext.h:graphics/mesa-dri \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libfribidi.so:converters/fribidi \
		libjson-glib-1.0.so:devel/json-glib \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libxkbcommon.so:x11/libxkbcommon \
		libcanberra.so:audio/libcanberra \
		libdbus-1.so:devel/dbus \
		libstartup-notification-1.so:x11/startup-notification \
		libpipewire-0.3.so:multimedia/pipewire \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	xkeyboard-config>0:x11/xkeyboard-config

USES=		compiler:c11 gettext-tools gl gnome localbase meson pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 introspection pango
USE_XORG=	ice sm x11 xau xcb xcomposite xcursor xdamage xext xfixes xi xinerama \
		xkbfile xrandr xrender xtst
USE_GL=		egl gl glesv2

USE_LDCONFIG=	yes
MESON_ARGS=	-Dcore_tests=false

GLIB_SCHEMAS=	org.cinnamon.muffin.gschema.xml

OPTIONS_DEFINE=	TEST UDEV WACOM
OPTIONS_DEFAULT=	WACOM

TEST_MESON_TRUE=	cogl_tests clutter_tests

UDEV_DESC=	Enable udev support when using the X11 backend (EXPERIMENTAL)
UDEV_LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev \
			libudev.so:devel/libudev-devd
UDEV_MESON_TRUE=	udev

WACOM_DESC=	Tablet support with libwacom
WACOM_LIB_DEPENDS=	libwacom.so:x11/libwacom
WACOM_MESON_TRUE=	libwacom

.include <bsd.port.mk>
