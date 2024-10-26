PORTNAME=	qml-box2d
DISTVERSION=	2.0.20240415
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QML Box2D plugin
WWW=		https://github.com/qml-box2d/qml-box2d

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++11-lang gl qt:${FLAVOR:S/qt//}
USE_GITHUB=	yes
GH_TAGNAME=	3a85439
_USE_GL=qt5=	# empty
_USE_GL_qt6=	gl opengl # glx
USE_GL=		${_USE_GL_${FLAVOR}}
_USE_QT_qt5=	core declarative gui network \
		buildtools:build qmake:build
_USE_QT_qt6=	base declarative
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING="${QT_QMLDIR}"
_CMAKE_OFF_qt5=	USE_QT6
CMAKE_OFF=	BUILD_EXAMPLES \
		${_CMAKE_OFF_${FLAVOR}}

.include <bsd.port.mk>
