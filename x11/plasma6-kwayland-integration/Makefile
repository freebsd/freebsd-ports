PORTNAME=	kwayland-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma
PKGNAMESUFFIX=	-qt5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Wayland integration plugins for Qt 5 applications

BUILD_DEPENDS=	wayland-protocols>=1.21:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-cursor.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	wayland windowsystem \
		ecm:build plasma-wayland-protocols:build
USE_QT=		core gui wayland widgets \
		buildtools:build qmake:build
USE_XORG=	x11

KDE_PLASMA_VERSION=	${KDE_PLASMA6_VERSION}
PKGNAMEPREFIX?=		plasma6-
DESCR=			${.CURDIR:H:H}/x11/plasma6-plasma/pkg-descr

.include <bsd.port.mk>
