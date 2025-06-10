PORTNAME=	quick3d
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Provides a high-level API for creating 3D content or UIs based on Qt Quick

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl python:build \
		qt-dist:6
USE_GL=		opengl
USE_QT=		base declarative quicktimeline shadertools
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
