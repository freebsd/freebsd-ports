PORTNAME=	libkscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	KDE screen management software
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lib gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	config \
		ecm:build plasma-wayland-protocols:build
USE_QT=		base wayland
USE_XORG=	xcb

.include <bsd.port.mk>
