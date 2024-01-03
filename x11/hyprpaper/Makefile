PORTNAME=	hyprpaper
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Blazing fast Wayland wallpaper utility with IPC controls
WWW=		https://github.com/hyprwm/hyprpaper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp

USES=		compiler:c++11-lib cmake gnome jpeg localbase:ldflags pkgconfig
USE_GNOME=	cairo
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Extract (snapshot) version from the port instead of Git
	@${REINPLACE_CMD} -i .nogit -e '/Get git info/,/^#$$/d' \
		-e 's/$${GIT_BRANCH}/main/' \
		-e 's/$${GIT_COMMIT_HASH}/${GH_TAGNAME}/' \
		-e '/$${GIT_COMMIT_MESSAGE}/d' \
		-e 's/$${GIT_DIRTY}/portbld/' \
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

.include <bsd.port.mk>
