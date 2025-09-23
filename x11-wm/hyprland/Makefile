PORTNAME=	hyprland
DISTVERSIONPREFIX=	v
DISTVERSION=	0.51.1
CATEGORIES=	x11-wm wayland
MASTER_SITES=	https://github.com/hyprwm/Hyprland/releases/download/${DISTVERSIONFULL}/
DISTNAME=	source-${DISTVERSIONFULL}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Dynamic tiling Wayland compositor that doesn't sacrifice on its looks #'
WWW=		https://hypr.land/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		glaze>0:devel/glaze \
		hyprwayland-scanner>=0.3.10:devel/hyprwayland-scanner \
		wayland-protocols>=1.45:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libinotify.so:devel/libinotify \
		libre2.so:devel/re2 \
		libtomlplusplus.so:devel/tomlplusplus \
		libhyprgraphics.so:graphics/hyprgraphics \
		libdrm.so:graphics/libdrm \
		libwayland-server.so:graphics/wayland \
		libuuid.so:misc/libuuid \
		libaquamarine.so:x11-toolkits/aquamarine \
		libhyprcursor.so:x11/hyprcursor \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++23-lang gl gnome pkgconfig xorg

USE_GL=		egl gbm opengl
USE_GNOME=	cairo glib20 pango
USE_XORG=	pixman xcursor

CMAKE_ON=	NO_SYSTEMD
CMAKE_OFF=	CMAKE_CXX_SCAN_FOR_MODULES # avoid devel/llvm*

LDFLAGS+=	-Wl,--as-needed # GL, pango deps

WRKSRC=		${WRKDIR}/${PORTNAME}-source

# XXX Drop after FreeBSD 13.5 EOL around 2026-04-30
# https://cgit.freebsd.org/src/commit/?id=af93fea71038
.if !exists(/usr/include/sys/timerfd.h)
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim
.endif

OPTIONS_DEFINE=		QT6 X11
OPTIONS_DEFAULT=	QT6 X11

QT6_RUN_DEPENDS=	hyprland-dialog:x11/hyprland-qtutils

X11_LIB_DEPENDS=	libxcb-errors.so:x11/xcb-util-errors \
			libxcb-icccm.so:x11/xcb-util-wm
X11_USE=		XORG=xcb
X11_CMAKE_BOOL_OFF=	NO_XWAYLAND

.include <bsd.port.options.mk>

# XXX Delete after 14.2-RELEASE EoL (2025-09-30)
# #embed directive in C23 standard requires llvm 19 or later
.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1400000 && ${OSVERSION} < 1402501)
USES+=		llvm:min=19
.endif

post-patch:
# Respect consolekit2 as XDG_RUNTIME_DIR fallback
	@${REINPLACE_CMD} 's|/run/user|/var&|' \
		${WRKSRC}/hyprctl/main.cpp \
		${WRKSRC}/hyprpm/src/core/HyprlandSocket.cpp \
		${WRKSRC}/hyprtester/src/hyprctlCompat.cpp \
		${WRKSRC}/src/Compositor.cpp
# Respect PREFIX for wallpapers
	@${REINPLACE_CMD} 's|/usr/share|${DATADIR:H}|' \
		${WRKSRC}/src/render/OpenGL.cpp
# XXX Replace linprocfs(4) with sysctl(3)
	@${REINPLACE_CMD} -e 's|/proc|${LINUXBASE}&|g' \
		${WRKSRC}/src/desktop/Window.cpp \
		${WRKSRC}/src/debug/HyprCtl.cpp \
		${WRKSRC}/src/debug/CrashReporter.cpp \
		${WRKSRC}/src/helpers/MiscFunctions.cpp \
		${WRKSRC}/src/plugins/HookSystem.cpp \
		${WRKSRC}/src/plugins/PluginAPI.cpp

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/hyprland
	@${RLN} ${STAGEDIR}${PREFIX}/bin/Hyprland ${STAGEDIR}${PREFIX}/bin/hyprland

.include <bsd.port.mk>

# XXX COMPILER_TYPE is defined after USES was already parsed
.if ${CHOSEN_COMPILER_TYPE} == clang && ${_CCVERSION:M+assertions}
llvm_ARGS=	build
.include "${USESDIR}/llvm.mk"
.endif
