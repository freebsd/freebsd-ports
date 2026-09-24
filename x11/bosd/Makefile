PORTNAME=	bosd
DISTVERSION=	10.4
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	X11 on-screen display engine

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libpng16.so:graphics/png

USES=		localbase:ldflags pkgconfig python:build,run shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xft xrandr xrender

SHEBANG_FILES=	examples/*.py tools/glyph.py

# FreeBSD keeps .pc files under libdata/pkgconfig.
# PYTHON= drives the example glyph build (no bare python3 on PATH).
MAKE_ARGS=	PKGCONFIGDIR="${PREFIX}/libdata/pkgconfig" \
		PYTHON="${PYTHON_CMD}"
ALL_TARGET=	all example

OPTIONS_DEFINE=		TESTS
OPTIONS_DEFAULT=	TESTS
OPTIONS_SUB=		yes

TESTS_MAKE_ARGS=	INSTALL_TESTS=yes
TESTS_MAKE_ARGS_OFF=	INSTALL_TESTS=no

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bosd \
		${STAGEDIR}${PREFIX}/lib/libbosd.so.4
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
