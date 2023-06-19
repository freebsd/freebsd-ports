PORTNAME=	bemenu
DISTVERSION=	0.6.15
CATEGORIES=	x11

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Dynamic menu library and client program inspired by dmenu
WWW=		https://github.com/Cloudef/bemenu

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE-CLIENT
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LICENSE-LIB

BUILD_DEPENDS=	scdoc:textproc/scdoc

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	Cloudef
USE_LDCONFIG=	yes
LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz
MAKEFILE=	GNUmakefile
ALL_TARGET=	clients
PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFAULT=	${OPTIONS_MULTI_BACKEND}
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	NCURSES WAYLAND X11
OPTIONS_SUB=		yes

BACKEND_DESC=	Backend

NCURSES_USES=		ncurses:base
NCURSES_ALL_TARGET=	curses
WAYLAND_CATEGORIES=	wayland
WAYLAND_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_USES=		gnome pkgconfig
WAYLAND_USE=		GNOME=cairo,glib20,pango
WAYLAND_ALL_TARGET=	wayland
X11_USES=		gnome pkgconfig xorg
X11_USE=		GNOME=cairo,glib20,pango \
			XORG=x11,xinerama
X11_ALL_TARGET=		x11

post-extract:
	${REINPLACE_CMD} -e 's,$$(shell $$(PKG_CONFIG) --libs ncursesw),${NCURSES_LIB},' \
		${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's,$$(shell $$(PKG_CONFIG) --cflags-only-I ncursesw),,' \
		${WRKSRC}/${MAKEFILE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-run
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.${DISTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/*.so

.include <bsd.port.mk>
