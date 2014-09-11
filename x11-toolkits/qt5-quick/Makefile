# $FreeBSD$

PORTNAME=	quick
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interfaces

USE_QT5=	core gui network qml qmldevtools_build sql testlib \
		widgets xmlpatterns buildtools_build
QT_DIST=	declarative
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

QT_DEFINES=	ACCESSIBILITY
QT_CONFIG=	accessibility accessibility-atspi-bridge

post-patch:
	@${REINPLACE_CMD} -e '/qmldevtools/ d' \
		${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e 's/qmldevtools-private/qmldevtools-private qml-private/' \
		${WRKSRC}/tools/qmlimportscanner/qmlimportscanner.pro
	@${REINPLACE_CMD} -e 's/qmltest/qmltest quick/' \
		${WRKSRC}/tools/qmltestrunner/qmltestrunner.pro

post-configure:
# Disable build of QML library (we need it on configure stage to
# create a local qt_lib_qml.pri).
	@${REINPLACE_CMD} -Ee 's|sub-qml-[-_0-9a-z]+||' \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
