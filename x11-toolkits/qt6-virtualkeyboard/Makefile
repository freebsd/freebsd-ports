PORTNAME=	virtualkeyboard
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 Virtual Keyboard Module

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl pkgconfig qt-dist:6
USE_GL=		opengl
USE_QT=		base declarative svg

.include <bsd.port.mk>
