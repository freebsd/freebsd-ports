PORTNAME=	gamescope
DISTVERSION=	3.9
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	98bc90ecf55c.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	acc8a1bed4e8.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	afa1c085ebbf.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	d59836199ebe.patch:-p1 # https://github.com/Plagman/gamescope/issues/120

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Micro-compositor from SteamOS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		evdev-proto>0:devel/evdev-proto \
		vulkan-headers>0:graphics/vulkan-headers \
		wayland-protocols>=1.17:graphics/wayland-protocols \
		wlroots>=0.13.0<0.14.0:x11-toolkits/wlroots
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libdrm.so:graphics/libdrm \
		libvulkan.so:graphics/vulkan-loader \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lib meson pkgconfig sdl xorg
USE_GITHUB=	yes
USE_SDL=	sdl2
USE_XORG=	x11 xcomposite xdamage xext xfixes xrender xres xtst xxf86vm
GH_ACCOUNT=	Plagman
GH_TUPLE=	emersion:libliftoff:v0.1.0-3-g516cf94:libliftoff/subprojects/libliftoff \
		nothings:stb:c0c9826:stb/subprojects/stb
CPPFLAGS+=	-D_WITH_DPRINTF # XXX Remove after FreeBSD 11 EOL
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	PIPEWIRE
OPTIONS_DEFAULT=PIPEWIRE

PIPEWIRE_DESC=		Screen capture via PipeWire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_MESON_ENABLED=	pipewire

# https://github.com/Plagman/gamescope/pull/202
BUILD_DEPENDS:=	${BUILD_DEPENDS:N*wlroots*} \
		xwayland-devel>0:x11-servers/xwayland-devel
LIB_DEPENDS:=	${LIB_DEPENDS:N*wlroots*} \
		libudev.so:devel/libudev-devd \
		libseat.so:sysutils/seatd \
		libinput.so:x11/libinput \
		libxcb-errors.so:x11/xcb-util-errors \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-icccm.so:x11/xcb-util-wm
RUN_DEPENDS+=	xwayland-devel>0:x11-servers/xwayland-devel
USE_XORG+=	pixman xcb
USE_GL+=	gbm egl
GH_TUPLE+=	swaywm:wlroots:0.13.0:wlroots/subprojects/wlroots
PLIST_FILES+=	"@comment libdata/pkgconfig/wlroots.pc"

.include <bsd.port.mk>
