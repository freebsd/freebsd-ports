PORTNAME=	dmenu
DISTVERSION=	5.1
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	X11 menu application designed for the dwm window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	0mp
GH_PROJECT=	freebsd-${PORTNAME}
USE_XORG=	x11 xft

MAKE_ARGS=	CC="${CC}" \
		FREETYPEINC="${LOCALBASE}/include/freetype2" \
		PREFIX="${PREFIX}" \
		X11INC="${LOCALBASE}/include" \
		X11LIB="${LOCALBASE}/lib"

PLIST_FILES=	bin/dmenu \
		bin/dmenu_path \
		bin/dmenu_run \
		bin/stest \
		share/man/man1/dmenu.1.gz \
		share/man/man1/stest.1.gz

OPTIONS_DEFINE=		XINERAMA
OPTIONS_DEFAULT=	XINERAMA

XINERAMA_USE=		XORG=xinerama
XINERAMA_MAKE_ARGS_OFF=	XINERAMAFLAGS= \
			XINERAMALIBS=

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dmenu \
		${STAGEDIR}${PREFIX}/bin/stest

.include <bsd.port.mk>
