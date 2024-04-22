PORTNAME=	hyprpicker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Color picker and magnifier for Wayland
WWW=		https://github.com/hyprwm/hyprpicker

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lib cmake gnome localbase:ldflags pkgconfig
USE_GNOME=	cairo
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	CLIPBOARD
OPTIONS_DEFAULT=CLIPBOARD

CLIPBOARD_DESC=		Copy to clipboard support
CLIPBOARD_RUN_DEPENDS=	wl-copy:x11/wl-clipboard

post-patch:
# Extract (snapshot) version from the port instead of Git
	@${REINPLACE_CMD} -i .nogit -e '/Get git info/,/^#$$/d' \
		-e 's/$${GIT_BRANCH}/main/' \
		-e 's/$${GIT_COMMIT_HASH}/${GH_TAGNAME}/' \
		-e '/$${GIT_COMMIT_MESSAGE}/d' \
		-e 's/$${GIT_DIRTY}/portbld/' \
		${WRKSRC}/CMakeLists.txt
# https://clang.llvm.org/cxx_status.html#cxx23
	@${REINPLACE_CMD} -e 's/c++23/c++17/' \
		${WRKSRC}/CMakeLists.txt
# Drop unused dependencies
	@${REINPLACE_CMD} 's/ wlroots//' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/ pango pangocairo//' \
		-e 's/ libjpeg//' \
		-e '/OpenGL/d; /GLESv2/d' \
		-e '/pthread/d; /CMAKE_THREAD_LIBS_INIT/d' \
		-e '/ rt)/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/GLES3/d' \
		-e '/pthread\.h/d' \
		${WRKSRC}/src/includes.hpp

pre-configure:
	@${SETENV} ${MAKE_ENV} ${GMAKE} protocols -C${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
