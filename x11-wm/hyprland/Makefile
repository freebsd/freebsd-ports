PORTNAME=	hyprland
DISTVERSIONPREFIX=	v
DISTVERSION=	0.34.0
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
		wlroots>=0.17.0<0.18.0:x11-toolkits/wlroots
LIB_DEPENDS=	libtomlplusplus.so:devel/tomlplusplus \
		libdrm.so:graphics/libdrm \
		libwayland-server.so:graphics/wayland \
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
GH_TUPLE=	hyprwm:hyprland-protocols:v0.2-4-g0c2ce70:hyprland_protocols/subprojects/hyprland-protocols \
		canihavesomecoffee:udis86:1.7.2-186-g5336633:udis86/subprojects/udis86
MESON_ARGS=	-Dsystemd=disabled

# XXX Drop after FreeBSD 14.0 EOL around 2025-03-01
.if exists(/usr/lib/libc++.so) && !exists(/usr/include/c++/v1/__format/write_escaped.h)
CXXFLAGS+=	-fexperimental-library
.endif

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USE=		XORG=xcb
X11_MESON_ENABLED=	xwayland

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit \
		-e "/version.*jq/s/run_command.*/'${DISTVERSIONFULL}',/" \
		${WRKSRC}/meson.build
	@${REINPLACE_CMD} -i .nogit \
		-e '/^HASH/s/=.*/=${DISTVERSIONFULL:C/.*-g//}/' \
		-e '/^BRANCH/s/=.*/=main/' \
		-e '/^MESSAGE/s/=.*/="?"/' \
		-e "/^DATE/s/=.*/=\"$$(date -ur $$(${AWK} \
			'/TIMESTAMP/ { print $$3 }' ${DISTINFO_FILE}))\"/" \
		-e '/^DIRTY/s/=.*/=portbld/' \
		-e '/^TAG/s/=.*/=${DISTVERSIONFULL}/' \
		${WRKSRC}/scripts/generateVersion.sh

# Respect PREFIX for wallpapers
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/src/render/OpenGL.cpp

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
USES+=		llvm:min=16,build,export
PATH:=		${LLVM_PREFIX}/bin:${PATH} # XXX _CMAKE_TOOLCHAIN_SUFFIX vs. devel/llvm*
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
.include <bsd.port.mk>
