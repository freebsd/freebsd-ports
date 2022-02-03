PORTNAME=	wlroots
DISTVERSION=	0.15.1
DISTVERSIONSUFFIX=	-g${GL_COMMIT:C/(.{12}).*/\1/}
CATEGORIES=	x11-toolkits

PATCH_SITES+=	https://github.com/swaywm/${GL_PROJECT}/commit/:github
PATCHFILES+=	7c0e2a271a4c.patch:-p1:github # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2064
PATCHFILES+=	55a8d225cf8c.patch:-p1:github # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2064
PATCH_SITES+=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	347b32642fb6.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/3318

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modular Wayland compositor library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.24:graphics/wayland-protocols
LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libdrm.so:graphics/libdrm \
		libwayland-server.so:graphics/wayland \
		libseat.so:sysutils/seatd \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITLAB=	yes
USE_GL=		gbm
USE_XORG=	pixman
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_COMMIT=	29938b74251e826f3778f6bf9c54974a30488cc1
MESON_ARGS=	-Dexamples=false -Dbackends=${BACKENDS:ts,} -Drenderers=${RENDERERS:ts,}

OPTIONS_DEFINE=	DRM NVIDIA OPENGL VULKAN X11
OPTIONS_DEFAULT=DRM OPENGL VULKAN X11
OPTIONS_SUB=	yes

DRM_DESC=		KMS console support
DRM_LIB_DEPENDS=	libinput.so:x11/libinput
DRM_VARS=		BACKENDS+="drm libinput"

NVIDIA_DESC=		EGLStreams support for DRM backend (experimental)
NVIDIA_PATCH_SITES=	https://github.com/danvd/${GL_PROJECT}-eglstreams/commit/:nvidia
NVIDIA_PATCHFILES=	c0fc017207f0.patch:-p1:nvidia # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2769
NVIDIA_IMPLIES=		DRM OPENGL X11
.if make(makesum)
.MAKEFLAGS:		WITH+=NVIDIA
.endif

OPENGL_RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri
OPENGL_USE=		GL=egl,glesv2
OPENGL_VARS=		RENDERERS+=gles2

VULKAN_DESC=		Vulkan renderer
VULKAN_BUILD_DEPENDS=	glslangValidator:graphics/glslang \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri
VULKAN_VARS=		RENDERERS+=vulkan

X11_LIB_DEPENDS=	libxcb-errors.so:x11/xcb-util-errors \
			libxcb-render-util.so:x11/xcb-util-renderutil \
			libxcb-icccm.so:x11/xcb-util-wm
X11_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			xwayland-devel>0:x11-servers/xwayland-devel
X11_RUN_DEPENDS=	xwayland-devel>0:x11-servers/xwayland-devel
X11_USE=		XORG=xcb
X11_MESON_ENABLED=	xwayland
X11_VARS=		BACKENDS+=x11

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} "/STR/s/meson.project_version()/'${DISTVERSIONFULL}'/" \
		${WRKSRC}/include/wlr/meson.build

.include <bsd.port.mk>
