PORTNAME=	hyprpaper
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Blazing fast Wayland wallpaper utility with IPC controls
WWW=		https://github.com/hyprwm/hyprpaper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hyprwayland-scanner>=0.4.0:devel/hyprwayland-scanner \
		wayland-protocols>=1.35:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libhyprwire.so:devel/hyprwire \
		libhyprgraphics.so:graphics/hyprgraphics \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libhyprtoolkit.so:x11-toolkits/hyprtoolkit

USES=		compiler:c++11-lib cmake gnome jpeg localbase:ldflags \
		pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_XORG=	pixman
USE_GNOME=	cairo

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
# Extract (snapshot) version from the port instead of Git
	@${REINPLACE_CMD} -i .nogit -e '/Get git info/,/^include/{//p;d;}' \
		-e 's/$${GIT_BRANCH}/main/' \
		-e 's/$${GIT_COMMIT_HASH}/${GH_TAGNAME}/' \
		-e 's/$${GIT_COMMIT_MESSAGE}/?/' \
		-e 's/$${GIT_DIRTY}/portbld/' \
		${WRKSRC}/CMakeLists.txt
# Drop unused dependencies
	@${REINPLACE_CMD} -e '/OpenGL/d; /GLESv2/d' \
		-e '/ rt)/d' \
		-e '/install.*systemd/d' \
		${WRKSRC}/CMakeLists.txt
# Respect consolekit2 as XDG_RUNTIME_DIR fallback
	@${REINPLACE_CMD} 's|/run/user|/var&|' \
		${WRKSRC}/src/ipc/HyprlandSocket.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
