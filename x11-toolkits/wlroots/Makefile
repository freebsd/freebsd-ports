PORTNAME=	wlroots
DISTVERSION=	0.16.1
DISTVERSIONSUFFIX=	-g${GL_COMMIT:C/(.{12}).*/\1/}
PORTREVISION=	1
CATEGORIES=	x11-toolkits

PATCH_SITES+=	https://github.com/swaywm/${GL_PROJECT}/commit/:github
PATCHFILES+=	fc0854d5f256.patch:-p1:github # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2064
PATCHFILES+=	29cb694655db.patch:-p1:github # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/2064
PATCHFILES+=	91a8ff42d26e.patch:-p1:github # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/3318
PATCH_SITES+=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	bc8260f377b5.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/3959

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modular Wayland compositor library
WWW=		https://gitlab.freedesktop.org/wlroots/wlroots

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.27:graphics/wayland-protocols \
		hwdata>0:misc/hwdata
LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libdrm.so:graphics/libdrm \
		libwayland-server.so:graphics/wayland \
		libseat.so:sysutils/seatd \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	hwdata>0:misc/hwdata

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITLAB=	yes
USE_GL=		gbm
USE_XORG=	pixman
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_COMMIT=	0911a41f17df2f684c383923772994a3807ce416
MESON_ARGS=	-Dexamples=false -Dbackends=${BACKENDS:ts,} -Drenderers=${RENDERERS:ts,}

OPTIONS_DEFINE=	DRM OPENGL VULKAN X11
OPTIONS_DEFAULT=DRM OPENGL VULKAN X11
OPTIONS_SUB=	yes

DRM_DESC=		KMS console support
DRM_LIB_DEPENDS=	libinput.so:x11/libinput
DRM_VARS=		BACKENDS+="drm libinput"

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
