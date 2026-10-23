PORTNAME=	bosd
DISTVERSION=	10.6
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	X11 on-screen display engine

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libpng16.so:graphics/png

USES=		localbase:ldflags pkgconfig shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xft xrandr xrender

SHEBANG_FILES=	examples/*.py tools/glyph.py

# FreeBSD keeps .pc files under libdata/pkgconfig.
# PYTHON= drives the example glyph build (no bare python3 on PATH).
# DATADIR is compiled into bosd. DATADIR and DOCSDIR are written into bosd.1.
MAKE_ARGS=	DATADIR="${DATADIR}" \
		DOCSDIR="${DOCSDIR}" \
		PKGCONFIGDIR="${PREFIX}/libdata/pkgconfig" \
		PYTHON="${PYTHON_CMD}"
ALL_TARGET=	all example

OPTIONS_DEFINE=		EXAMPLES TESTS
OPTIONS_DEFAULT=	TESTS
OPTIONS_SUB=		yes

TESTS_DESC=		Install the test suite
EXAMPLES_USES=		python:build,run
EXAMPLES_USES_OFF=	python:build
TESTS_MAKE_ARGS=	INSTALL_TESTS=yes
TESTS_MAKE_ARGS_OFF=	INSTALL_TESTS=no

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bosd \
		${STAGEDIR}${PREFIX}/lib/libbosd.so.4

# Upstream install always copies the example scripts.
post-install-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
