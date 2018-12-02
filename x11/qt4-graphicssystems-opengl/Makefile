# $FreeBSD$

PORTNAME=	graphicssystems
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	3
CATEGORIES=	x11
PKGNAMEPREFIX=	qt4-
PKGNAMESUFFIX=	-opengl

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt OpenGL rendering engine (experimental)

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake:no_env qt-dist:4
USE_QT=		opengl

HAS_CONFIGURE=	yes
USE_GL=		glu

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake tools translations \
		src/activeqt src/dbus src/multimedia src/network src/openvg \
		src/phonon src/qt3support src/s60installs src/s60main \
		src/script src/scripttools src/sql src/svg src/testlib \
		src/tools src/winmain src/xml src/xmlpatterns \
		src/3rdparty/clucene src/3rdparty/freetype \
		src/3rdparty/libjpeg src/3rdparty/libmng src/3rdparty/libpng \
		src/3rdparty/libtiff src/3rdparty/phonon src/3rdparty/webkit
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/src/plugins/${PORTNAME}/opengl
INSTALL_WRKSRC=	${BUILD_WRKSRC}

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake

.include <bsd.port.mk>
