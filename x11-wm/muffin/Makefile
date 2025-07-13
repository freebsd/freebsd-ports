PORTNAME=	muffin
DISTVERSION=	6.4.1
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
		libdbus-1.so:devel/dbus
RUN_DEPENDS=	xkeyboard-config>0:x11/xkeyboard-config \
		zenity>0:x11/zenity

USES=		compiler:c11 gettext-tools gl gnome localbase meson pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 pango
USE_XORG=	ice x11 xau xcb xcomposite xcursor xdamage xext xfixes xi xinerama \
		xkbfile xrandr xrender xtst
USE_GL=		egl gl glesv2

USE_LDCONFIG=	yes
MESON_ARGS=	-Dnative_backend=false

GLIB_SCHEMAS=	org.cinnamon.muffin.gschema.xml

OPTIONS_DEFINE=		EGL_DEVICE INTROSPECTION PANGOFT2 REMOTE SM STARTUP \
			TEST UDEV WACOM WAYLAND WAYLAND_EGL
OPTIONS_DEFAULT=	INTROSPECTION PANGOFT2 REMOTE SM STARTUP UDEV WACOM
OPTIONS_SUB=		yes

EGL_DEVICE_DESC=	Enable EGLDevice and EGLStream renderer support
EGL_DEVICE_MESON_TRUE=	egl_device

INTROSPECTION_DESC=	Enable GObject introspection
INTROSPECTION_MESON_TRUE=	introspection
INTROSPECTION_USE=		GNOME=introspection

PANGOFT2_DESC=		Enable PangoFt2 support
PANGOFT2_MESON_TRUE=	pango_ft2
PANGOFT2_USE=		GNOME=pangoft2

REMOTE_DESC=		Enable remote desktop and screen cast support
REMOTE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
REMOTE_MESON_TRUE=	remote_desktop

SM_DESC=		Enable X11 session management support
SM_MESON_TRUE=		sm
SM_USE=			XORG=sm

STARTUP_DESC=		Enable startup notification support
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
STARTUP_MESON_TRUE=	startup_notification

TEST_BUILD_DEPENDS=	bash:shells/bash
TEST_MESON_TRUE=	tests

UDEV_DESC=		Enable udev support when using the X11 backend
UDEV_LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev \
			libudev.so:devel/libudev-devd
UDEV_MESON_TRUE=	udev

WACOM_DESC=		Tablet support with libwacom
WACOM_LIB_DEPENDS=	libwacom.so:x11/libwacom
WACOM_MESON_TRUE=	libwacom

WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm \
			wayland-protocols>0:graphics/wayland-protocols \
			Xwayland:x11-servers/xwayland
WAYLAND_LIB_DEPENDS=	libwayland-server.so:graphics/wayland
WAYLAND_MESON_TRUE=	core_tests wayland

WAYLAND_EGL_DESC=	Enable Wayland EGLStream support client support
WAYLAND_EGL_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/wayland-eglstream-protocols.pc:graphics/egl-wayland
WAYLAND_EGL_MESON_TRUE=		wayland_eglstream
WAYLAND_EGL_IMPLIES=		wayland

post-patch:
	@${REINPLACE_CMD} -e 's/<drm_fourcc.h>/<libdrm\/drm_fourcc.h>/' \
		${WRKSRC}/src/wayland/meta-wayland-dma-buf.c \
		${WRKSRC}/src/wayland/meta-wayland-buffer.c

.include <bsd.port.mk>
