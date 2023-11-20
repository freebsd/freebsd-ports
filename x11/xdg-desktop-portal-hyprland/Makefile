PORTNAME=	xdg-desktop-portal-hyprland
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.5
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xdg-desktop-portal backend for hyprland
WWW=		https://github.com/hyprwm/xdg-desktop-portal-hyprland

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_12=	libc++ too old

BUILD_DEPENDS=	wayland-protocols>=1.31:graphics/wayland-protocols
LIB_DEPENDS=	libsdbus-c++.so:devel/sdbus-cpp \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libpipewire-0.3.so:multimedia/pipewire
RUN_DEPENDS=	grim:x11/grim \
		hyprland-share-picker:x11/hyprland-share-picker@${FLAVOR} \
		slurp:x11/slurp

FLAVORS=	qt5 qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}
qt6_PKGNAMESUFFIX=	-qt6

USES=		compiler:c++11-lib gl meson pkgconfig
USE_GITHUB=	yes
USE_GL=		gbm
GH_ACCOUNT=	hyprwm
GH_TUPLE=	hyprwm:hyprland-protocols:v0.2:hyprland_protocols/subprojects/hyprland-protocols
MESON_ARGS=	-Dsystemd=disabled
PLIST_FILES=	libexec/${PORTNAME} \
		share/dbus-1/services/org.freedesktop.impl.portal.desktop.hyprland.service \
		share/xdg-desktop-portal/portals/hyprland.portal

# XXX Drop after FreeBSD 14.0 EOL around 2025-03-01
.if exists(/usr/lib/libc++.so) && !exists(/usr/include/c++/v1/__format/write_escaped.h)
CXXFLAGS+=	-fexperimental-library
.endif

post-patch:
# XXX Merge with hyprland-share-picker instead
	@${REINPLACE_CMD} '/hyprland-share-picker/d' ${WRKSRC}/meson.build

.ifdef GH_TUPLE
post-configure:
	@${REINPLACE_CMD} 's/meson install/& \
		--skip-subprojects/' ${BUILD_WRKSRC}/build.ninja
.endif

# XXX Drop after FreeBSD 13.2 EOL around 2024-05-01 (don't forget distinfo)
.if ${CXX} == c++ && exists(/usr/lib/libc++.so)
.if !exists(/usr/include/c++/v1/__ranges/as_rvalue_view.h) || make(makesum) || make(fetch)
BUILD_DEPENDS+=	${CMAKE_BIN}:devel/cmake-core
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
