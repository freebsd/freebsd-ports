PORTNAME=	wlroots
DISTVERSION=	0.13.0
CATEGORIES=	x11-toolkits

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	7c0e2a271a4c.patch:-p1 # https://github.com/swaywm/wlroots/pull/2064
PATCHFILES+=	e1b5323f56c3.patch:-p1 # https://github.com/swaywm/wlroots/pull/2064

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modular Wayland compositor library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland>=1.18:graphics/wayland \
		wayland-protocols>=1.17:graphics/wayland-protocols
LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libdrm.so:graphics/libdrm \
		libwayland-server.so:graphics/wayland \
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

OPTIONS_DEFINE=	CONSOLEKIT LIBSEAT NVIDIA UUID X11
OPTIONS_DEFAULT=LIBSEAT UUID X11
OPTIONS_SUB=	yes

CONSOLEKIT_DESC=	DRM sessions without root via ConsoleKit2 (experimental)
CONSOLEKIT_PATCH_SITES=	https://github.com/unrelentingtech/${GH_PROJECT}/commit/:ck2
CONSOLEKIT_PATCHFILES=	fb837ae10b1f.patch:-p1:ck2 # https://github.com/swaywm/wlroots/pull/1467
CONSOLEKIT_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libconsolekit.so:sysutils/consolekit2
CONSOLEKIT_MESON_ENABLED=	consolekit2
.if make(makesum)
.MAKEFLAGS:		WITH+=CONSOLEKIT
.endif

LIBSEAT_DESC=		DRM sessions with/without root via libseat
LIBSEAT_LIB_DEPENDS=	libseat.so:sysutils/seatd
LIBSEAT_MESON_ENABLED=	libseat

NVIDIA_DESC=		EGLStreams support for DRM backend (experimental)
NVIDIA_PATCH_SITES=	https://github.com/danvd/${GH_PROJECT}-eglstreams/commit/:nvidia
NVIDIA_PATCHFILES=	eba4b66f92ca.patch:-p1:nvidia # https://github.com/swaywm/wlroots/pull/2769
.if make(makesum)
.MAKEFLAGS:		WITH+=NVIDIA
.endif

# uuid_create() is random on NetBSD and OpenBSD but not DragonFly and FreeBSD
# See also https://github.com/netbsd/src/commit/8651e9a438af
UUID_DESC=		Exported surfaces to use random UUIDs via libuuid
UUID_LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

X11_LIB_DEPENDS=	libxcb-errors.so:x11/xcb-util-errors \
			libxcb-render-util.so:x11/xcb-util-renderutil \
			libxcb-icccm.so:x11/xcb-util-wm
X11_BUILD_DEPENDS=	xwayland-devel>0:x11-servers/xwayland-devel
X11_RUN_DEPENDS=	xwayland-devel>0:x11-servers/xwayland-devel
X11_USE=		XORG=xcb
X11_MESON_ENABLED=	x11-backend xwayland

.include <bsd.port.mk>
