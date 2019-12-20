# $FreeBSD$

PORTNAME=	bemenu
DISTVERSION=	0.3.0
CATEGORIES=	x11 wayland

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Dynamic menu library and client program inspired by dmenu

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE-CLIENT
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LICENSE-LIB

USES=		cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	Cloudef
USE_LDCONFIG=	yes

LDFLAGS+=	-pthread -Wl,--as-needed
PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFAULT=	${OPTIONS_MULTI_BACKEND}
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	NCURSES WAYLAND X11
OPTIONS_SUB=		yes

BACKEND_DESC=	Backend

NCURSES_USES=		ncurses
NCURSES_CMAKE_BOOL=	BEMENU_CURSES_RENDERER
NCURSES_CMAKE_ON=	-DCURSES_FOUND:BOOL=yes \
			-DCURSES_INCLUDE_DIRS:PATH="${NCURSESINC}" \
			-DCURSES_LIBRARY:PATH="${NCURSESLIB}/libncursesw.so"
WAYLAND_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_USES=		gnome pkgconfig
WAYLAND_USE=		GNOME=cairo,glib20,pango
WAYLAND_CMAKE_BOOL=	BEMENU_WAYLAND_RENDERER
X11_USES=		gnome pkgconfig xorg
X11_USE=		GNOME=cairo,glib20,pango \
			XORG=x11,xinerama
X11_CMAKE_BOOL=		BEMENU_X11_RENDERER

.include <bsd.port.mk>
