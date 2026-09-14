PORTNAME=	bosd
DISTVERSION=	10.2
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

SHEBANG_FILES=	examples/bsd.py tools/glyph.py

# FreeBSD keeps .pc files under libdata/pkgconfig.
# PYTHON= drives the example glyph build (no bare python3 on PATH).
MAKE_ARGS=	PKGCONFIGDIR="${PREFIX}/libdata/pkgconfig" \
		PYTHON="${PYTHON_CMD}"
ALL_TARGET=	all example

OPTIONS_DEFINE=		TESTS
OPTIONS_DEFAULT=	TESTS
OPTIONS_SUB=		yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
MAKE_ARGS+=	INSTALL_TESTS=yes
.else
MAKE_ARGS+=	INSTALL_TESTS=no
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bosd \
		${STAGEDIR}${PREFIX}/lib/libbosd.so.4

.include <bsd.port.mk>
