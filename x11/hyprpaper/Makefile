PORTNAME=	hyprpaper
PORTVERSION=	s20230315
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Blazing fast Wayland wallpaper utility with IPC controls
WWW=		https://github.com/hyprwm/hyprpaper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	mips mips64 powerpc powerpc64 powerpcspe sparc64
NOT_FOR_ARCHS_REASON=	only little-endian is supported

BUILD_DEPENDS=	gmake:devel/gmake \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c++11-lib cmake gnome jpeg localbase:ldflags pkgconfig
USE_GNOME=	cairo
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
GH_TAGNAME=	6196197
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Extract (snapshot) version from the port instead of Git
	@${REINPLACE_CMD} -i .nogit -e '/Get git info/,/^#$$/d' \
		-e 's/$${GIT_BRANCH}/main/' \
		-e 's/$${GIT_COMMIT_HASH}/${GH_TAGNAME}/' \
		-e 's/$${GIT_COMMIT_MESSAGE}/<unknown>/' \
		-e 's/$${GIT_DIRTY}/portbld/' \
		${WRKSRC}/CMakeLists.txt
# https://clang.llvm.org/cxx_status.html#cxx23
	@${REINPLACE_CMD} -e 's/c++23/c++2b/' \
		${WRKSRC}/CMakeLists.txt
# Drop unused dependencies
	@${REINPLACE_CMD} 's/ wlroots//' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/ pango pangocairo//' \
		-e '/OpenGL/d; /GLESv2/d' \
		-e '/ rt)/d' \
		${WRKSRC}/CMakeLists.txt

pre-configure:
	@${SETENV} ${MAKE_ENV} ${GMAKE} protocols -C${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

# XXX Drop after FreeBSD 12.3 EOL around 2023-03-31 (don't forget distinfo)
.if ${CXX} == c++ && exists(/usr/lib/libc++.so)
.if !exists(/usr/include/c++/v1/concepts) || make(makesum) || make(fetch)
USES+=		llvm:min=12,build
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}
CPP=		clang-cpp${LLVM_VERSION}

# XXX Move into separate port and standardize via USES
GH_TUPLE+=	llvm:llvm-project:llvmorg-13.0.1:libcxx
CXXFLAGS+=	-nostdinc++ -isystem${WRKDIR}/libcxx_prefix/include/c++/v1
# Don't link against new libc++ as it's not necessary
#LDFLAGS+=	-nostdlib++ -L${WRKDIR}/libcxx_prefix/lib -l:libc++.a -lcxxrt

pre-configure:	bundled-libcxx
bundled-libcxx:
	@${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS:M*Ninja*} \
		-DCMAKE_INSTALL_PREFIX:PATH=${WRKDIR}/libcxx_prefix \
		-B ${WRKDIR}/libcxx_build -S ${WRKSRC_libcxx}/libcxx
	@${DO_MAKE_BUILD:NDESTDIR*} install -C ${WRKDIR}/libcxx_build
.endif
.endif # exists(/usr/lib/libc++.so)

.include <bsd.port.mk>
