PORTNAME=	gamescope
DISTVERSION=	3.12.5
CATEGORIES=	x11-wm wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a618ea074660.patch:-p1 # https://github.com/ValveSoftware/gamescope/issues/120

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	SteamOS session compositing window manager
WWW=		https://github.com/ValveSoftware/gamescope

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		glslangValidator:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers \
		wayland-protocols>=1.17:graphics/wayland-protocols \
		glm>0:math/glm \
		hwdata>0:misc/hwdata \
		wlroots>=0.16.0<0.17.0:x11-toolkits/wlroots
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libliftoff.so:graphics/libliftoff \
		libvulkan.so:graphics/vulkan-loader \
		libwayland-server.so:graphics/wayland \
		libdisplay-info.so:sysutils/libdisplay-info \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	hwdata>0:misc/hwdata

USES=		compiler:c++11-lib meson pkgconfig sdl xorg
USE_GITHUB=	yes
USE_SDL=	sdl2
USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xmu xrender xres xtst xxf86vm
GH_ACCOUNT=	ValveSoftware
GH_TUPLE=	nothings:stb:5736b15:stb/subprojects/stb \
		Joshua-Ashton:vkroots:2675710:vkroots/subprojects/vkroots
MESON_ARGS=	--force-fallback-for= # allow system wlroots + libliftoff
MESON_ARGS+=	-Denable_openvr_support=false # https://github.com/ValveSoftware/openvr/pull/564
MESON_ARCH_FAMILY=	${ARCH:S/amd/x86_/:S/i3/x/:C/v[67]//:S/power/p/:S/le$//}
PLIST_FILES=	bin/${PORTNAME} \
		lib/libVkLayer_FROG_${PORTNAME}_wsi.so \
		share/vulkan/implicit_layer.d/VkLayer_FROG_${PORTNAME}_wsi.${MESON_ARCH_FAMILY}.json

OPTIONS_DEFINE=	PIPEWIRE
OPTIONS_DEFAULT=PIPEWIRE

PIPEWIRE_DESC=		Screen capture via PipeWire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_MESON_ENABLED=	pipewire

post-extract:
# Merge patch_directory for subprojects without meson.build
	@(cd ${WRKSRC}/subprojects/packagefiles && ${COPYTREE_SHARE} . ..)

post-patch:
# gamescope_color_microbench isn't installed, so make its dependency optional
	@${REINPLACE_CMD} '/dependency.*benchmark/s/)/, required: false, disabler: true&/' \
		${WRKSRC}/src/meson.build

.ifdef GH_TUPLE
post-configure:
	@${REINPLACE_CMD} 's/meson install/& \
		--skip-subprojects/' ${BUILD_WRKSRC}/build.ninja
.endif

.include <bsd.port.mk>
