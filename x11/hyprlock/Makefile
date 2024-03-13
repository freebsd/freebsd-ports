PORTNAME=	hyprlock
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	e040c56ad294.patch:-p1 # https://github.com/hyprwm/hyprlock/pull/195

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Hyprland's GPU-accelerated screen locking utility #'
WWW=		https://github.com/hyprwm/hyprlock

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	unix-selfauth-helper>0:security/unix-selfauth-helper

USES=		compiler:c++11-lib cmake gl gnome pkgconfig
USE_GITHUB=	yes
USE_GL=		egl gbm
USE_GNOME=	cairo pango
GH_ACCOUNT=	hyprwm
LDFLAGS+=	-Wl,--as-needed # pango deps
PLIST_FILES=	bin/${PORTNAME} \
		etc/pam.d/${PORTNAME}

# XXX Drop after FreeBSD 14.0 EOL around 2025-03-01
.if exists(/usr/lib/libc++.so) && !exists(/usr/include/c++/v1/__format/write_escaped.h)
CXXFLAGS+=	-fexperimental-library
.endif

# XXX Drop after FreeBSD 13.3 EOL around 2025-07-01
.if exists(/usr/lib/libc++.so) && !exists(/usr/include/c++/v1/__chrono/time_zone.h)
LIB_DEPENDS+=	libdate-tz.so:devel/date
USES+=		localbase:ldflags
.endif

# XXX Drop after FreeBSD 13.2 EOL around 2024-07-01 (don't forget distinfo)
.if ${CXX} == c++ && exists(/usr/lib/libc++.so)
.if !exists(/usr/include/c++/v1/expected) || make(makesum) || make(fetch)
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
