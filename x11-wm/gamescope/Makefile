PORTNAME=	gamescope
DISTVERSION=	3.13.8
PORTREVISION=	1
CATEGORIES=	x11-wm wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a618ea074660.patch:-p1 # https://github.com/ValveSoftware/gamescope/issues/120
PATCHFILES+=	4a067fb4ebe2.patch:-p1 # https://github.com/ValveSoftware/gamescope/pull/678

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
		wlroots>=0.17.0<0.18.0:x11-toolkits/wlroots
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
		KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-316-gd790ced:spirv_headers/thirdparty/SPIRV-Headers \
		Joshua-Ashton:reshade:v4.4.2-2572-g9fdbea68:reshade/src/reshade \
		Joshua-Ashton:vkroots:d5ef31a:vkroots/subprojects/vkroots
MESON_ARGS=	--force-fallback-for= # allow system wlroots + libliftoff
MESON_ARGS+=	-Dbenchmark=disabled # gamescope_color_microbench isn't installed
MESON_ARGS+=	-Denable_openvr_support=false # https://github.com/ValveSoftware/openvr/pull/564
MESON_ARCH_FAMILY=	${ARCH:S/amd/x86_/:S/i3/x/:C/v[67]//:S/power/p/:S/le$//}
PLIST_FILES=	bin/${PORTNAME} \
		lib/libVkLayer_FROG_${PORTNAME}_wsi_${MESON_ARCH_FAMILY}.so \
		share/vulkan/implicit_layer.d/VkLayer_FROG_${PORTNAME}_wsi.${MESON_ARCH_FAMILY}.json

# https://github.com/freebsd/drm-kmod/issues/271
PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	PIPEWIRE
OPTIONS_DEFAULT=PIPEWIRE

PIPEWIRE_DESC=		Screen capture via PipeWire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_MESON_ENABLED=	pipewire

post-extract:
# Merge patch_directory for subprojects without meson.build
	@(cd ${WRKSRC}/subprojects/packagefiles && ${COPYTREE_SHARE} . ..)
.if defined(PATCHFILES) && ${PATCHFILES:M4a067fb4ebe2*}
# Pretend to be a regular file for vendor patch to apply as is
	@${RMDIR} ${WRKSRC}/subprojects/wlroots
	@${ECHO_CMD} "Subproject commit 1712a7d27444d62f8da8eeedf0840b386a810e96" \
		>${WRKSRC}/subprojects/wlroots
.endif

.ifdef GH_TUPLE
post-configure:
	@${REINPLACE_CMD} 's/meson install/& \
		--skip-subprojects/' ${BUILD_WRKSRC}/build.ninja
.endif

# XXX Drop after FreeBSD 13.2 EOL around 2024-05-01 (don't forget distinfo)
.if ${CXX} == c++ && exists(/usr/lib/libc++.so)
.if !exists(/usr/include/c++/v1/__ranges/as_rvalue_view.h) || make(makesum) || make(fetch)
BUILD_DEPENDS+=	${CMAKE_BIN}:devel/cmake-core
USES+=		llvm:min=16,build,export
PATH:=		${LLVM_PREFIX}/bin:${PATH} # XXX _CMAKE_TOOLCHAIN_SUFFIX vs. devel/llvm*
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" CPP="${CPP}"
CMAKE_BIN=	${LOCALBASE}/bin/cmake

# XXX Move into separate port and standardize via USES
GH_TUPLE+=	llvm:llvm-project:llvmorg-16.0.1:libcxx
CXXFLAGS+=	-nostdinc++ -isystem${WRKDIR}/libcxx_prefix/include/c++/v1
# Don't link against new libc++ as it's not necessary
#LDFLAGS+=	-nostdlib++ -L${WRKDIR}/libcxx_prefix/lib -l:libc++.a -lcxxrt

pre-configure:	bundled-libcxx
bundled-libcxx:
	@${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
		-DLIBCXX_INCLUDE_BENCHMARKS:BOOL=OFF \
		-DCMAKE_INSTALL_PREFIX:PATH=${WRKDIR}/libcxx_prefix \
		-B ${WRKDIR}/libcxx_build -S ${WRKSRC_libcxx}/libcxx
	@${DO_MAKE_BUILD:NDESTDIR*} install -C ${WRKDIR}/libcxx_build
.endif
.endif # exists(/usr/lib/libc++.so)

.include <bsd.port.mk>
