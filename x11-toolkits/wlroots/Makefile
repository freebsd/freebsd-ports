PORTNAME=	wlroots
DISTVERSION=	0.14.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits

PATCH_SITES=	https://github.com/swaywm/${GL_PROJECT}/commit/
PATCHFILES+=	7c0e2a271a4c.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2064
PATCHFILES+=	55a8d225cf8c.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2064

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modular Wayland compositor library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.21:graphics/wayland-protocols
LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libdrm.so:graphics/libdrm \
		libwayland-server.so:graphics/wayland \
		libseat.so:sysutils/seatd \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITLAB=	yes
USE_GL=		gbm
USE_XORG=	pixman
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_COMMIT=	49a574420138646845fb664862db03982cfd9f5b
MESON_ARGS=	-Dexamples=false -Drenderers=${RENDERERS:ts,}

OPTIONS_DEFINE=	NVIDIA OPENGL VULKAN X11
OPTIONS_DEFAULT=OPENGL VULKAN X11
OPTIONS_SUB=	yes

NVIDIA_DESC=		EGLStreams support for DRM backend (experimental)
NVIDIA_PATCH_SITES=	https://github.com/danvd/${GL_PROJECT}-eglstreams/commit/:nvidia
NVIDIA_PATCHFILES=	d9acdb6b21ec.patch:-p1:nvidia # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2769
NVIDIA_IMPLIES=		OPENGL
.if make(makesum)
.MAKEFLAGS:		WITH+=NVIDIA
.endif

OPENGL_RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri
OPENGL_USE=		GL=egl,glesv2
OPENGL_VARS=		RENDERERS+=gles2

VULKAN_DESC=		Vulkan renderer (experimental)
VULKAN_PATCHFILES+=	8c700c534556.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	0464af8573f9.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	e3e9250ea6d8.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	1af1d1694195.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	93319aa2b633.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	0028938735d1.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	6885b636508c.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	76534695a8d3.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	445142e6a1f9.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	f029ae1dac4b.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	ad1fab0b3704.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	4407b8e5a3a7.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	e021c068d02f.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	2cc710bda83c.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	f0888604d6ce.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	4fdd5efc9260.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	59c119829f1c.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	cfbd8aa6cf24.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	3f6dbe428e8b.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	a83943798aef.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	f64a98d49d25.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	9885ccb4b0b1.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	71f9f33e3bf2.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	bd8c520dbd9a.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	2d89dc9b8651.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	8f9aeda46d8a.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	e3d16970433f.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	79f10d929b72.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	1a16e8fc56a9.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	dd039c56d93a.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2771
VULKAN_PATCHFILES+=	347b32642fb6.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/3318
VULKAN_BUILD_DEPENDS=	glslangValidator:graphics/glslang \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri
VULKAN_VARS=		RENDERERS+=vulkan
VULKAN_PLIST_FILES=	include/wlr/types/wlr_drm.h \
			%%VULKAN%%include/wlr/render/vulkan.h

X11_LIB_DEPENDS=	libxcb-errors.so:x11/xcb-util-errors \
			libxcb-render-util.so:x11/xcb-util-renderutil \
			libxcb-icccm.so:x11/xcb-util-wm
X11_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			xwayland-devel>0:x11-servers/xwayland-devel
X11_RUN_DEPENDS=	xwayland-devel>0:x11-servers/xwayland-devel
X11_USE=		XORG=xcb
X11_MESON_ENABLED=	x11-backend xwayland

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} "/STR/s/meson.project_version()/'${DISTVERSIONFULL}'/" \
		${WRKSRC}/include/wlr/meson.build

.include <bsd.port.mk>
