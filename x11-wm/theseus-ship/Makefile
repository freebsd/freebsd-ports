PORTNAME=	theseus-ship
DISTVERSIONPREFIX=	v
DISTVERSION=	6.1.0
CATEGORIES=	x11-wm # wayland: https://github.com/winft/theseus-ship/issues/9

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland and X11 compositor for KDE Plasma Desktop
WWW=		https://github.com/winft/theseus-ship

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libwayland-server.so:graphics/wayland \
		libWraplandServer.so:graphics/wrapland \
		libcomo-script.so.0:x11-toolkits/como \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-icccm.so:x11/xcb-util-wm

CONFLICTS_INSTALL=	plasma6-kwin # bin/kwin_wayland

USES=		cmake:testing gettext-tools kde:6 pkgconfig qt:6 xorg
USE_GITHUB=	yes
USE_KDE=	colorscheme config coreaddons crash dbusaddons decoration \
		ecm:build globalaccel i18n kcmutils kscreenlocker newstuff:build \
		notifications package svg widgetsaddons windowsystem xmlgui
USE_LDCONFIG=	yes
USE_QT=		base declarative tools
USE_XORG=	pixman x11 xcb xi
GH_ACCOUNT=	winft
GH_PROJECT=	theseus-ship
PLIST_SUB=	VERSION=${PORTVERSION}
LDFLAGS+=	-Wl,--as-needed # GL, ICE/SM/Xext, input, KF6Service

OPTIONS_DEFINE=	BREEZE
OPTIONS_DEFAULT=BREEZE

BREEZE_DESC=		Default window decoration plugin
BREEZE_USE=		KDE=breeze
BREEZE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Breeze

# XXX Drop after FreeBSD 13.2 EOL around 2024-07-01 (don't forget distinfo)
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
