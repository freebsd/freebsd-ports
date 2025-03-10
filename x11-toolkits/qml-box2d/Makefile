PORTNAME=	qml-box2d
DISTVERSION=	2.0.20240415
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QML Box2D plugin
WWW=		https://github.com/qml-box2d/qml-box2d

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang gl qt:6
USE_GITHUB=	yes
GH_TAGNAME=	3a85439
USE_GL=		gl opengl # glx
USE_QT=		base declarative

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR:STRING="${QT_QMLDIR}"
CMAKE_OFF=	BUILD_EXAMPLES

.include <bsd.port.mk>
