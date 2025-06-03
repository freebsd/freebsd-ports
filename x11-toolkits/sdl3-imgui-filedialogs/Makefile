PORTNAME=	sdl3-imgui-filedialogs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
CATEGORIES=	x11-toolkits

MAINTAINER=	josephvenable@verizon.net
COMMENT=	SDL3 ImGui File Dialogs - CLI and Client Library
WWW=		https://github.com/samuelvenable/SDL3-ImGui-FileDialogs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libepoll-shim.so:devel/libepoll-shim \
		libffi.so:devel/libffi \
		libpipewire-0.3.so:multimedia/pipewire \
		libwayland-client.so:graphics/wayland \
		libwayland-cursor.so:graphics/wayland \
		libwayland-egl.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake:indirect gl gnome pkgconfig sdl xorg
USE_GL=		gbm egl
USE_GNOME=	glib20 gtk30
USE_SDL=	sdl3
USE_XORG=	x11 xau xcb xcursor xdmcp xext xfixes xi xrandr xrender xscrnsaver

USE_GITHUB=	yes
GH_ACCOUNT=	samuelvenable
GH_PROJECT=	SDL3-ImGui-FileDialogs
GH_TAGNAME=	8d28d3688accaa00cb5bf56919c57cfee134a937

do-build:
	mkdir ${WRKSRC}/_build
	cmake "${WRKSRC}/filedialogs/lunasvg" -B "${WRKSRC}/_build"
	make -j${MAKE_JOBS_NUMBER} -C "${WRKSRC}/_build"
	cd "${WRKSRC}/filedialogs" && \
	${CXX} \
		"ImFileDialog/ImFileDialog.cpp" \
		"imgui/imgui.cpp" \
		"imgui/backends/imgui_impl_sdl3.cpp" \
		"imgui/backends/imgui_impl_sdlgpu3.cpp" \
		"imgui/backends/imgui_impl_sdlrenderer3.cpp" \
		"imgui/imgui_draw.cpp" \
		"imgui/imgui_tables.cpp" \
		"imgui/imgui_widgets.cpp" \
		"filesystem.cpp" \
		"filedialogs.cpp" \
		"msgbox/imguial_msgbox.cpp" \
		"main.cpp" \
		-o "${WRKSRC}/_build/filedialogs" \
		-std=c++17 -Wno-format-security -I. -IImFileDialog -Iimgui \
		-Iimgui/backends -L${WRKSRC}/_build -llunasvg -DIMGUI_USE_WCHAR32 \
		`pkg-config --cflags --libs sdl3 --static` \
		`pkg-config --cflags --libs gtk+-3.0` \
		`pkg-config --cflags --libs gio-2.0` \
		`pkg-config --cflags --libs glib-2.0` \
		-lX11 -lc -lpthread -fPIC

do-install:
	${CP} ${WRKSRC}/_build/filedialogs ${STAGEDIR}${PREFIX}/bin
	${CP} ${WRKSRC}/_build/libfiledialogs.so ${STAGEDIR}${PREFIX}/lib
	${CP} ${WRKSRC}/filedialogs/filedialogs.hpp ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
