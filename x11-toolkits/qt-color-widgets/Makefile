PORTNAME=	qt-color-widgets
DISTVERSION=	3.0.0
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	${SUFFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt (C++) widgets to manage color inputs
WWW=		https://gitlab.com/mattia.basaglia/Qt-Color-Widgets

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang gl pkgconfig qt:6
USE_QT=		base tools:build
USE_GL=		opengl
LIB_DEPENDS+=	libGLX.so:graphics/libglvnd
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	mattia.basaglia
GL_PROJECT=	Qt-Color-Widgets

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DQT_VERSION_MAJOR=6

.include <bsd.port.mk>
