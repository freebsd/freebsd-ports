PORTNAME=	hyprland
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24.1
PORTREVISION=	1
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Dynamic tiling Wayland compositor that doesn't sacrifice on its looks #'
WWW=		https://hyprland.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.25:graphics/wayland-protocols \
		wlroots>=0.16.0<0.17.0:x11-toolkits/wlroots
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
GH_TUPLE=	hyprwm:hyprland-protocols:d7d403b:hyprland_protocols/subprojects/hyprland-protocols \
		canihavesomecoffee:udis86:1.7.2-186-g5336633:udis86/subprojects/udis86
MESON_ARGS=	-Dsystemd=disabled

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USE=		XORG=xcb
X11_MESON_ENABLED=	xwayland

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e "/GIT_BRANCH/s/run_command.*/'main'/" \
		-e "/GIT_COMMIT_HASH/s/run_command.*/'${DISTVERSIONFULL}'/" \
		-e "/GIT_COMMIT_MESSAGE/s/run_command.*/'?'/" \
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
post-install:
# XXX USES=meson invokes ninja directly, so doesn't support --skip-subprojects
	@${RM} -r ${STAGEDIR}${PREFIX}/share/pkgconfig
	@${RM} -r ${STAGEDIR}${PREFIX}/share/protocols
.endif

# XXX Drop after FreeBSD 13.2 EOL around 2024-05-01 (don't forget distinfo)
.if ${CXX} == c++ && exists(/usr/lib/libc++.so)
.if !exists(/usr/include/c++/v1/__ranges/as_rvalue_view.h) || make(makesum) || make(fetch)
USES+=		llvm:min=16,build
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}
CPP=		clang-cpp${LLVM_VERSION}
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" CPP="${CPP}"
CMAKE_BIN=	${LOCALBASE}/bin/cmake
CMAKE_ARGS+=	-GNinja

# XXX Move into separate port and standardize via USES
GH_TUPLE+=	llvm:llvm-project:llvmorg-16.0.1:libcxx
CXXFLAGS+=	-nostdinc++ -isystem${WRKDIR}/libcxx_prefix/include/c++/v1
# Don't link against new libc++ as it's not necessary
#LDFLAGS+=	-nostdlib++ -L${WRKDIR}/libcxx_prefix/lib -l:libc++.a -lcxxrt

pre-configure:	bundled-libcxx
bundled-libcxx:
	@${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS:M*Ninja*} \
		-DLIBCXX_INCLUDE_BENCHMARKS:BOOL=OFF \
		-DCMAKE_INSTALL_PREFIX:PATH=${WRKDIR}/libcxx_prefix \
		-B ${WRKDIR}/libcxx_build -S ${WRKSRC_libcxx}/libcxx
	@${DO_MAKE_BUILD:NDESTDIR*} install -C ${WRKDIR}/libcxx_build
.endif
.endif # exists(/usr/lib/libc++.so)

.include <bsd.port.mk>
