PORTNAME=	hyprland
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26.0
PORTREVISION=	3
CATEGORIES=	x11-wm wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	147e96237006.patch:-p1 # wlroots 0.17
PATCHFILES+=	c5a7202cd9a4.patch:-p1 # wlroots 0.17
PATCHFILES+=	10db5a4fdbb0.patch:-p1 # wlroots 0.17
PATCHFILES+=	fbabb105c342.patch:-p1 # wlroots 0.17

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Dynamic tiling Wayland compositor that doesn't sacrifice on its looks #'
WWW=		https://hyprland.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.25:graphics/wayland-protocols \
		wlroots>=0.16.0.529<0.17.0:x11-toolkits/wlroots
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lib gl gnome meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		egl opengl
USE_GNOME=	cairo pango
USE_XORG=	pixman
GH_ACCOUNT=	hyprwm
GH_PROJECT=	Hyprland
GH_TUPLE=	hyprwm:hyprland-protocols:4d29e48:hyprland_protocols/subprojects/hyprland-protocols \
		canihavesomecoffee:udis86:1.7.2-186-g5336633:udis86/subprojects/udis86
MESON_ARGS=	-Dsystemd=disabled

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USE=		XORG=xcb
X11_MESON_ENABLED=	xwayland

post-extract:
.if defined(PATCHFILES) && ${PATCHFILES:M147e96237006*}
# Pretend to be a regular file for vendor patch to apply as is
	@${RMDIR} ${WRKSRC}/subprojects/wlroots
	@${ECHO_CMD} "Subproject commit 6668c822b3bf58ca5af5d370ef03b075be3e4d27" \
		>${WRKSRC}/subprojects/wlroots
.endif

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e "/GIT_BRANCH/s/run_command.*/'main'/" \
		-e "/GIT_COMMIT_HASH/s/run_command.*/'${DISTVERSIONFULL}'/" \
		-e "/GIT_COMMIT_MESSAGE/d" \
		-e "/GIT_DIRTY/s/run_command.*/'portbld'/" \
		-e "/version.*jq/s/run_command.*/'${DISTVERSIONFULL}',/" \
		${WRKSRC}/meson.build
# Respect PREFIX for wallpapers
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/src/render/OpenGL.cpp
# Respect LOCALBASE for xdg-desktop-portal-hyprland installation
	@${REINPLACE_CMD} 's,/usr/share,${LOCALBASE}/share,g' \
		${WRKSRC}/src/Compositor.cpp

.ifdef GH_TUPLE
post-configure:
	@${REINPLACE_CMD} 's/meson install/& \
		--skip-subprojects/' ${BUILD_WRKSRC}/build.ninja
.endif

post-install:
# Plugin API installs all headers (no private vs. public)
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} include/${PORTNAME} ! -type d) >>${TMPPLIST}

# XXX Drop after FreeBSD 13.2 EOL around 2024-05-01 (don't forget distinfo)
.if ${CXX} == c++ && exists(/usr/lib/libc++.so)
.if !exists(/usr/include/c++/v1/__ranges/as_rvalue_view.h) || make(makesum) || make(fetch)
USES+=		llvm:min=16,build
PATH:=		${LLVM_PREFIX}/bin:${PATH} # XXX _CMAKE_TOOLCHAIN_SUFFIX vs. devel/llvm*
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}
CPP=		clang-cpp${LLVM_VERSION}
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

.include "${.CURDIR:H:H}/x11-toolkits/wlroots-devel/override.mk"
post-patch:	wlroots-devel-patch
wlroots-devel-patch:
# Prefer <wlr/*> headers (used by <hyprland/*>) from wlroots-devel
	@${REINPLACE_CMD} -i .devel "/subdirs/s|''|'../wlroots-devel/include', &|" \
		${WRKSRC}/meson.build
.include <bsd.port.mk>
