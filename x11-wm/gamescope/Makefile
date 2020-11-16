# $FreeBSD$

PORTNAME=	gamescope
DISTVERSION=	3.7.1
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	56a1378c3643.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	620f8f5bc530.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	892d79b0f37e.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	ae60c865d9d8.patch:-p1 # https://github.com/Plagman/gamescope/pull/119
PATCHFILES+=	d59836199ebe.patch:-p1 # https://github.com/Plagman/gamescope/issues/120

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Micro-compositor from SteamOS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:devel/glslang \
		evdev-proto>0:devel/evdev-proto \
		vulkan-headers>0:devel/vulkan-headers \
		wayland-protocols>=1.17:graphics/wayland-protocols \
		wlroots>=0.11.0:x11-toolkits/wlroots
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libdrm.so:graphics/libdrm \
		libvulkan.so:graphics/vulkan-loader \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lib meson pkgconfig sdl xorg
USE_GITHUB=	yes
USE_SDL=	sdl2
USE_XORG=	x11 xcomposite xdamage xext xfixes xrender xtst xxf86vm
GH_ACCOUNT=	Plagman
GH_TUPLE=	emersion:libliftoff:24abeb9:libliftoff/subprojects/libliftoff
CPPFLAGS+=	-D_WITH_DPRINTF # XXX Remove after FreeBSD 11 EOL
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
