PORTNAME=	gamescope
DISTVERSION=	3.10
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ec8e547be135.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	ea415ae28442.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	7c188b24afaa.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	a618ea074660.patch:-p1 # https://github.com/Plagman/gamescope/issues/120
PATCHFILES+=	9553362865bb.patch:-p1 # https://github.com/Plagman/gamescope/pull/330

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Micro-compositor from SteamOS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		evdev-proto>0:devel/evdev-proto \
		vulkan-headers>0:graphics/vulkan-headers \
		wayland-protocols>=1.17:graphics/wayland-protocols \
		wlroots>=0.15.0<0.16.0:x11-toolkits/wlroots
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libdrm.so:graphics/libdrm \
		libvulkan.so:graphics/vulkan-loader \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lib meson pkgconfig sdl xorg
USE_GITHUB=	yes
USE_GITLAB=	nodefault
USE_SDL=	sdl2
USE_XORG=	x11 xcomposite xdamage xext xfixes xrender xres xtst xxf86vm
GH_ACCOUNT=	Plagman
GH_TUPLE=	nothings:stb:af1a5bc:stb/subprojects/stb
GL_TUPLE=	https://gitlab.freedesktop.org:emersion:libliftoff:b7a6958bcacdedf6e451d8821c807299943ef150:libliftoff/subprojects/libliftoff
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	PIPEWIRE
OPTIONS_DEFAULT=PIPEWIRE

PIPEWIRE_DESC=		Screen capture via PipeWire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_MESON_ENABLED=	pipewire

post-extract:
# Merge patch_directory for subprojects without meson.build
	@(cd ${WRKSRC}/subprojects/packagefiles && ${COPYTREE_SHARE} . ..)

.include "${.CURDIR}/Makefile.wlroots"
.include <bsd.port.mk>
