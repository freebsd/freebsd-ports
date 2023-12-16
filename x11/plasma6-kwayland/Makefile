PORTNAME=	kwayland
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	Qt-style Client and Server library wrapper for the Wayland libraries
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		wayland-protocols>=1.27:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-cursor.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build \
		plasma-wayland-protocols:build
USE_QT=		base wayland

.include <bsd.port.mk>
