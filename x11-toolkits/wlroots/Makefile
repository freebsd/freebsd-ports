PORTNAME=	wlroots
DISTVERSION=	0.14.0
CATEGORIES=	x11-toolkits

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	7c0e2a271a4c.patch:-p1 # https://github.com/swaywm/wlroots/pull/2064
PATCHFILES+=	55a8d225cf8c.patch:-p1 # https://github.com/swaywm/wlroots/pull/2064

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
		libseat.so:sysutils/seatd \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	libudev-devd>=0.4.1:devel/libudev-devd

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		gbm
USE_XORG=	pixman
USE_LDCONFIG=	yes
GH_ACCOUNT=	swaywm
MESON_ARGS=	-Dexamples=false -Drenderers=${RENDERERS:ts,}

OPTIONS_DEFINE=	NVIDIA OPENGL X11
OPTIONS_DEFAULT=OPENGL X11
OPTIONS_SUB=	yes

NVIDIA_DESC=		EGLStreams support for DRM backend (experimental)
NVIDIA_PATCH_SITES=	https://github.com/danvd/${GH_PROJECT}-eglstreams/commit/:nvidia
NVIDIA_PATCHFILES=	b78146d76ab0.patch:-p1:nvidia # https://github.com/swaywm/wlroots/pull/2769
NVIDIA_IMPLIES=		OPENGL
.if make(makesum)
.MAKEFLAGS:		WITH+=NVIDIA
.endif

OPENGL_RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri
OPENGL_USE=		GL=egl,glesv2
OPENGL_VARS=		RENDERERS+=gles2

X11_LIB_DEPENDS=	libxcb-errors.so:x11/xcb-util-errors \
			libxcb-render-util.so:x11/xcb-util-renderutil \
			libxcb-icccm.so:x11/xcb-util-wm
X11_BUILD_DEPENDS=	xwayland-devel>0:x11-servers/xwayland-devel
X11_RUN_DEPENDS=	xwayland-devel>0:x11-servers/xwayland-devel
X11_USE=		XORG=xcb
X11_MESON_ENABLED=	x11-backend xwayland

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} "/STR/s/meson.project_version()/'${DISTVERSIONFULL}'/" \
		${WRKSRC}/include/wlr/meson.build

.include <bsd.port.mk>
