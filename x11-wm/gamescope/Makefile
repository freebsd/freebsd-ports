PORTNAME=	gamescope
DISTVERSION=	3.11.14
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	2a84a44f6897.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	e0927f7bce95.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	a618ea074660.patch:-p1 # https://github.com/Plagman/gamescope/issues/120

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Micro-compositor from SteamOS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		evdev-proto>0:devel/evdev-proto \
		libliftoff>=0.2.0<0.3.0:graphics/libliftoff \
		vulkan-headers>0:graphics/vulkan-headers \
		wayland-protocols>=1.17:graphics/wayland-protocols \
		wlroots>=0.15.0<0.16.0:x11-toolkits/wlroots
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libdrm.so:graphics/libdrm \
		libliftoff.so:graphics/libliftoff \
		libvulkan.so:graphics/vulkan-loader \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lib meson pkgconfig sdl xorg
USE_GITHUB=	yes
USE_SDL=	sdl2
USE_XORG=	x11 xcomposite xdamage xext xfixes xrender xres xtst xxf86vm
GH_ACCOUNT=	Plagman
GH_TUPLE=	nothings:stb:af1a5bc:stb/subprojects/stb
PLIST_FILES=	bin/${PORTNAME}
MESON_ARGS=	--force-fallback-for= # allow system wlroots + libliftoff

OPTIONS_DEFINE=	PIPEWIRE
OPTIONS_DEFAULT=PIPEWIRE

PIPEWIRE_DESC=		Screen capture via PipeWire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_MESON_ENABLED=	pipewire

post-extract:
# Merge patch_directory for subprojects without meson.build
	@(cd ${WRKSRC}/subprojects/packagefiles && ${COPYTREE_SHARE} . ..)

.include <bsd.port.mk>
