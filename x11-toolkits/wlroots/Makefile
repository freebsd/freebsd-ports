# $FreeBSD$

PORTNAME=	wlroots
DISTVERSION=	0.12.0
CATEGORIES=	x11-toolkits

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	8bdf0df41719.patch:-p1 # https://github.com/swaywm/wlroots/pull/2064
PATCHFILES+=	90cb6d26877b.patch:-p1 # https://github.com/swaywm/wlroots/pull/2064

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modular Wayland compositor library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland>=1.18:graphics/wayland \
		wayland-protocols>=1.17:graphics/wayland-protocols
LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libdrm.so:graphics/libdrm \
		libwayland-egl.so:graphics/wayland \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	libudev-devd>=0.4.1:devel/libudev-devd \
		mesa-dri>0:graphics/mesa-dri

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		egl gbm glesv2
USE_XORG=	pixman
USE_LDCONFIG=	yes
GH_ACCOUNT=	swaywm
MESON_ARGS=	-Dexamples=false

OPTIONS_DEFINE=	CONSOLEKIT LIBSEAT X11
OPTIONS_DEFAULT=LIBSEAT X11
OPTIONS_SUB=	yes

CONSOLEKIT_DESC=	DRM sessions without root using ConsoleKit2
CONSOLEKIT_PATCH_SITES=	https://github.com/myfreeweb/${GH_PROJECT}/commit/:ck2
CONSOLEKIT_PATCHFILES=	fcee578b13eb.patch:-p1:ck2 # https://github.com/swaywm/wlroots/pull/1467
CONSOLEKIT_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libconsolekit.so:sysutils/consolekit2
CONSOLEKIT_MESON_ENABLED=	consolekit2
.if make(makesum)
.MAKEFLAGS:		WITH+=CONSOLEKIT
.endif

LIBSEAT_DESC=		DRM sessions with/without root via libseat (experimental)
LIBSEAT_LIB_DEPENDS=	libseat.so:sysutils/seatd
LIBSEAT_MESON_ENABLED=	libseat

X11_LIB_DEPENDS=	libxcb-errors.so:x11/xcb-util-errors \
			libxcb-icccm.so:x11/xcb-util-wm
X11_RUN_DEPENDS=	xwayland-devel>0:x11-servers/xwayland-devel
X11_USE=		XORG=x11,xcb
X11_MESON_ENABLED=	x11-backend xcb-icccm xwayland

.include <bsd.port.mk>
