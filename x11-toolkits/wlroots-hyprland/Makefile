PORTNAME=	wlroots
DISTVERSION=	0.17.0-312
DISTVERSIONSUFFIX=	-gb1b34cd665
PORTREVISION=	2
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	-hyprland

PATCH_SITES+=	https://github.com/hyprwm/wlroots-hyprland/raw/422207db/patches/:hyprland
PATCHFILES+=	surface-nondivisible-by-scale.patch:-p1:hyprland
PATCHFILES+=	nvidia-hardware-cursors.patch:-p1:hyprland
PATCHFILES+=	displaylink.patch:-p1:hyprland
PATCH_SITES+=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	6e6c4408d36d.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/4697
PATCHFILES+=	4b4f76cc1357.patch:-p1 # https://gitlab.freedesktop.org/wlroots/wlroots/-/merge_requests/4614

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modular Wayland compositor library (Hyprland fork)
WWW=		https://github.com/hyprwm/wlroots-hyprland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Project discontinued, use x11-toolkits/aquamarine instead

BUILD_DEPENDS=	wayland-protocols>=1.33:graphics/wayland-protocols
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libwayland-server.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITLAB=	yes
USE_GL=		gbm
USE_XORG=	pixman
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
MESON_ARGS=	-Dexamples=false -Dbackends=${BACKENDS:ts,} -Drenderers=${RENDERERS:ts,}
PLIST_SUB=	SUFFIX=${PKGNAMESUFFIX}

PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	DRM OPENGL VULKAN X11
OPTIONS_DEFAULT=DRM OPENGL VULKAN X11
OPTIONS_EXCLUDE=VULKAN # not supported by Hyprland due to custom renderer
OPTIONS_SUB=	yes

DRM_DESC=		KMS console support
DRM_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			hwdata>0:misc/hwdata
DRM_LIB_DEPENDS=	libudev.so:devel/libudev-devd \
			libliftoff.so:graphics/libliftoff \
			libdisplay-info.so:sysutils/libdisplay-info \
			libseat.so:sysutils/seatd \
			libinput.so:x11/libinput
DRM_MESON_ENABLED=	session
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
			Xwayland:x11-servers/xwayland
X11_RUN_DEPENDS=	Xwayland:x11-servers/xwayland
X11_USE=		XORG=xcb
X11_MESON_ENABLED=	xwayland
X11_VARS=		BACKENDS+=x11

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} "/STR/s/meson.project_version()/'${DISTVERSIONFULL}'/" \
		${WRKSRC}/include/wlr/meson.build

.include <bsd.port.mk>
