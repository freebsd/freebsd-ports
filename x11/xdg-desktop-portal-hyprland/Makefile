PORTNAME=	xdg-desktop-portal-hyprland
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	f46cff1df2d8.patch:-p1 # https://github.com/hyprwm/xdg-desktop-portal-hyprland/issues/151
PATCHFILES+=	21d216ed7f64.patch:-p1 # https://github.com/hyprwm/xdg-desktop-portal-hyprland/pull/154
PATCHFILES+=	c0b606460a09.patch:-p1 # https://github.com/hyprwm/xdg-desktop-portal-hyprland/issues/156
PATCHFILES+=	df8c154f5793.patch:-p1 # https://github.com/hyprwm/xdg-desktop-portal-hyprland/issues/157
PATCHFILES+=	86a94c3e4edb.patch:-p1 # https://github.com/hyprwm/xdg-desktop-portal-hyprland/issues/158
PATCHFILES+=	1c802128f6cc.patch:-p1 # https://github.com/hyprwm/xdg-desktop-portal-hyprland/issues/159
PATCHFILES+=	379b27281e2c.patch:-p1 # https://github.com/hyprwm/xdg-desktop-portal-hyprland/issues/160

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xdg-desktop-portal backend for hyprland
WWW=		https://github.com/hyprwm/xdg-desktop-portal-hyprland

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.31:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libsdbus-c++.so:devel/sdbus-cpp \
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

USES=		cmake compiler:c++11-lib gl pkgconfig
USE_GITHUB=	yes
USE_GL=		gbm
GH_ACCOUNT=	hyprwm
GH_TUPLE=	hyprwm:hyprland-protocols:v0.2:hyprland_protocols/subprojects/hyprland-protocols
LDFLAGS+=	-Wl,--as-needed # sdbus-cpp deps
PLIST_FILES=	lib/systemd/user/${PORTNAME}.service \
		libexec/${PORTNAME} \
		share/dbus-1/services/org.freedesktop.impl.portal.desktop.hyprland.service \
		share/xdg-desktop-portal/portals/hyprland.portal

# XXX Drop after FreeBSD 14.0 EOL around 2025-03-01
.if exists(/usr/lib/libc++.so) && !exists(/usr/include/c++/v1/__format/write_escaped.h)
CXXFLAGS+=	-fexperimental-library
.endif

post-patch:
# XXX Merge with hyprland-share-picker instead
	@${REINPLACE_CMD} '/hyprland-share-picker/d' ${WRKSRC}/CMakeLists.txt

# XXX Drop after FreeBSD 13.2 EOL around 2024-05-01 (don't forget distinfo)
.if ${CXX} == c++ && exists(/usr/lib/libc++.so)
.if !exists(/usr/include/c++/v1/__ranges/as_rvalue_view.h) || make(makesum) || make(fetch)
USES+=		llvm:min=16,build,export
PATH:=		${LLVM_PREFIX}/bin:${PATH} # XXX _CMAKE_TOOLCHAIN_SUFFIX vs. devel/llvm*
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" CPP="${CPP}"

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
