PORTNAME=	kwayland-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Integration plugins for a Wayland-based desktop
WWW=		https://www.kde.org/plasma-desktop

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols

USES=		cmake compiler:c++11-lib gl kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=		gl
USE_KDE=	idletime wayland windowsystem \
		ecm:build plasma-wayland-protocols:build
USE_QT=		core gui wayland widgets \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
