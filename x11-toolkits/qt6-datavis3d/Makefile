PORTNAME=	datavis3d
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 3D data visualization module

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++17-lang gl pkgconfig qt-dist:6
USE_GL=		opengl
USE_QT=		base declarative

.include <bsd.port.mk>
