PORTNAME=	hyprpicker
PORTVERSION=	s20221120
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	wlroots-compatible Wayland color picker that does not suck
WWW=		https://github.com/hyprwm/hyprpicker

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c++11-lib cmake gnome jpeg pkgconfig
USE_GCC=	yes:build # C++23
USE_GNOME=	cairo
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
GH_TAGNAME=	f6c24d9
LDFLAGS+=	-static-libstdc++ -static-libgcc # avoid libc++ conflict
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Extract (snapshot) version from the port instead of Git
	@${REINPLACE_CMD} -i .nogit -e '/Get git info/,/^#$$/d' \
		-e 's/$${GIT_BRANCH}/main/' \
		-e 's/$${GIT_COMMIT_HASH}/${GH_TAGNAME}/' \
		-e 's/$${GIT_COMMIT_MESSAGE}/<unknown>/' \
		-e 's/$${GIT_DIRTY}/portbld/' \
		${WRKSRC}/CMakeLists.txt
# Drop unused dependencies
	@${REINPLACE_CMD} 's/ wlroots//' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/ pango pangocairo//' \
		-e 's/ libjpeg//' \
		-e '/OpenGL/d; /GLESv2/d' \
		-e '/pthread/d; /CMAKE_THREAD_LIBS_INIT/d' \
		-e '/ rt)/d' \
		${WRKSRC}/CMakeLists.txt

pre-configure:
	@${SETENV} ${MAKE_ENV} ${GMAKE} protocols -C${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
