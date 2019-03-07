# $FreeBSD$

PORTNAME=	bemenu
DISTVERSION=	0.1.0
CATEGORIES=	x11 wayland

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Dynamic menu library and client program inspired by dmenu

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE-CLIENT
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LICENSE-LIB

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Cloudef
USE_LDCONFIG=	yes

LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=		BEMENU_RUN
OPTIONS_DEFAULT=	${OPTIONS_MULTI_BACKEND}
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	NCURSES WAYLAND X11
OPTIONS_SUB=		yes

BACKEND_DESC=		Backend
BEMENU_RUN_DESC=	Install bemenu-run (not recommended)

NCURSES_CMAKE_ON=	-DCURSES_FOUND:BOOL=yes \
			-DCURSES_INCLUDE_DIRS:PATH="${NCURSESINC}" \
			-DCURSES_LIBRARY:PATH="${NCURSESLIB}/libncursesw.so"
NCURSES_USES=		ncurses

WAYLAND_CFLAGS=		-I${LOCALBASE}/include/libepoll-shim
WAYLAND_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Wayland
WAYLAND_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_LDFLAGS=	-lepoll-shim
WAYLAND_USES=		localbase:ldflags gnome pkgconfig
WAYLAND_USE=		GNOME=cairo,glib20,pango

X11_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_X11
X11_USES=		gnome localbase:ldflags pkgconfig
X11_USE=		GNOME=cairo,glib20,pango XORG=x11,xinerama

.include <bsd.port.mk>
