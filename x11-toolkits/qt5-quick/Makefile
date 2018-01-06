# $FreeBSD$

PORTNAME=	quick
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interfaces

USE_GL=		gl
USE_QT5=	core gui network qml sql testlib \
		widgets xmlpatterns buildtools_build
QT_DIST=	declarative
USES=		python:build qmake:norecursive
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

CONFLICTS=	qt5-declarative-render2d-*

QT_DEFINES=	ACCESSIBILITY
QT_CONFIG=	accessibility accessibility-atspi-bridge

# libQt5Qml.so and libQt5QmlDevTools.a come from lang/qt5-qml, so we do not
# want to build them again here. On the other hand, if we just remove qml/ and
# qmldevtools/ from src/src.pro the versions installed in ${LOCALBASE} will be
# picked up and their .pri files will make -Wl,-rpath-link,${LOCALBASE}/lib be
# used when building targets such as tools/qmltestrunner. This causes problems
# when building the port with an older version installed (bug 194870).
# Instead, we let the .pri modules be created in ${WRKSRC}/mkspecs but symlink
# the existing libraries and trick the existing Makefiles into doing nothing
# (it is more future-proof than whitelisting the other directories).
post-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/lib
	${LN} -s ${QT_LIBDIR}/libQt5Qml.so \
		${CONFIGURE_WRKSRC}/lib/libQt5Qml.so
	${LN} -s ${QT_LIBDIR}/libQt5QmlDevTools.a \
		${CONFIGURE_WRKSRC}/lib/libQt5QmlDevTools.a
	${PRINTF} ".DEFAULT:\n\t@${DO_NADA}" \
		> ${CONFIGURE_WRKSRC}/src/qml/Makefile
	${PRINTF} ".DEFAULT:\n\t@${DO_NADA}" \
		> ${CONFIGURE_WRKSRC}/src/qmldevtools/Makefile

post-patch:
# qtdeclarative.pro wants to run python, replace that with PYTHON_CMD
	${REINPLACE_CMD} '/py_out/s#python#${PYTHON_CMD}#g' \
		${WRKSRC}/qtdeclarative.pro

.include <bsd.port.mk>
