PORTNAME=	hyprpicker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Color picker and magnifier for Wayland
WWW=		https://github.com/hyprwm/hyprpicker

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hyprwayland-scanner>=0.4.0:devel/hyprwayland-scanner \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprutils.so:devel/hyprutils \
		libwayland-client.so:graphics/wayland \
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
	@${REINPLACE_CMD} -i .nogit -e '/Get git info/,/^include/{//p;d;}' \
		-e 's/$${GIT_BRANCH}/main/' \
		-e 's/$${GIT_COMMIT_HASH}/${GH_TAGNAME}/' \
		-e 's/$${GIT_COMMIT_MESSAGE}/?/' \
		-e 's/$${GIT_DIRTY}/portbld/' \
		${WRKSRC}/CMakeLists.txt
# Drop unused dependencies
	@${REINPLACE_CMD} -e '/pango/d' \
		-e '/libjpeg/d' \
		-e 's/pthread $${CMAKE_THREAD_LIBS_INIT}//' \
		-e '/ rt)/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/pthread\.h/d' \
		${WRKSRC}/src/includes.hpp

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
