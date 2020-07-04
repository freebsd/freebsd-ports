# $FreeBSD$

PORTNAME=	bemenu
DISTVERSION=	0.5.0
CATEGORIES=	x11 wayland

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Dynamic menu library and client program inspired by dmenu

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE-CLIENT
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LICENSE-LIB

USE_GITHUB=	yes
GH_ACCOUNT=	Cloudef
USE_LDCONFIG=	yes

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ARGS=	RENDERERS="${_BEMENU_RENDERERS}" \
		VERSION=${DISTVERSION}
PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFAULT=	${OPTIONS_MULTI_BACKEND}
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	NCURSES WAYLAND X11
OPTIONS_SUB=		yes

BACKEND_DESC=	Backend

NCURSES_USES=		ncurses
NCURSES_MAKE_ARGS=	curses_CFLAGS="-I${NCURSESINC}" \
			curses_LIBS="-L${NCURSESLIB} -l${NCURSES_IMPL}"
NCURSES_VARS=		_BEMENU_RENDERERS+=curses
WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_USES=		gnome pkgconfig
WAYLAND_USE=		GNOME=cairo,glib20,pango
WAYLAND_VARS=		_BEMENU_RENDERERS+=wayland
X11_USES=		gnome pkgconfig xorg
X11_USE=		GNOME=cairo,glib20,pango \
			XORG=x11,xinerama
X11_VARS=		_BEMENU_RENDERERS+=x11

.include <bsd.port.mk>
