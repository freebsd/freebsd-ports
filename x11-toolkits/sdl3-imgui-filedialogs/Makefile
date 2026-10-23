PORTNAME=	sdl3-imgui-filedialogs
DISTVERSIONPREFIX=	v
DISTVERSION=	g20250611
CATEGORIES=	x11-toolkits

MAINTAINER=	josephvenable@verizon.net
COMMENT=	SDL3 ImGui File Dialogs - CLI and Client Library
WWW=		https://github.com/samuelvenable/SDL3-ImGui-FileDialogs

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
GH_TAGNAME=	71bee0ea2e3676191f5768db0600b5314d6a4fa3

do-build:
	cd "${WRKSRC}/filedialogs" && ${SH} ./build.sh

do-install:
	${CP} ${WRKSRC}/filedialogs/filedialogs ${STAGEDIR}${PREFIX}/bin
	${CP} ${WRKSRC}/filedialogs/filedialogs.hpp ${STAGEDIR}${PREFIX}/include
	${CP} ${WRKSRC}/filedialogs/libfiledialogs.so ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/share/licenses/filedialogs-${DISTVERSION}
	${CP} ${WRKSRC}/LICENSE ${STAGEDIR}${PREFIX}/share/licenses/filedialogs-${DISTVERSION}

.include <bsd.port.mk>
