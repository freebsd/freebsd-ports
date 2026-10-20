PORTNAME=	libwinpos
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	x11

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Client-side window positioning hint library for Qt applications
WWW=		https://github.com/ximion/libwinpos/

BUILD_DEPENDS=	vulkan-headers>=0:graphics/vulkan-headers \
		wayland-protocols>0:graphics/wayland-protocols

USES=		cmake compiler:c++23-lang pkgconfig qt:6
USE_QT=		base wayland

USE_GITHUB=	yes
GH_ACCOUNT=	ximion

CMAKE_OFF=	BUILD_EXAMPLES

.include <bsd.port.mk>
