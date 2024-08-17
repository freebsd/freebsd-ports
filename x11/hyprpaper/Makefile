PORTNAME=	hyprpaper
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Blazing fast Wayland wallpaper utility with IPC controls
WWW=		https://github.com/hyprwm/hyprpaper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hyprwayland-scanner>=0.4.0:devel/hyprwayland-scanner \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp

USES=		compiler:c++11-lib cmake gnome jpeg localbase:ldflags pkgconfig
USE_GNOME=	cairo
USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm
PLIST_FILES=	bin/${PORTNAME}

# XXX Drop after FreeBSD 14.0 EOL around 2024-10-01
.if exists(/usr/lib/libc++.so) && !exists(/usr/include/c++/v1/__format/write_escaped.h)
CXXFLAGS+=	-fexperimental-library
.endif

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
		-e '/OpenGL/d; /GLESv2/d' \
		-e '/ rt)/d' \
		${WRKSRC}/CMakeLists.txt
# Respect consolekit2 as XDG_RUNTIME_DIR fallback
	@${REINPLACE_CMD} 's,/run/user,/var&,' \
		${WRKSRC}/src/ipc/Socket.cpp

.include <bsd.port.mk>
