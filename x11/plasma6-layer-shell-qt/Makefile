PORTNAME=	layer-shell-qt
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	Qt component to allow applications to make use of the Wayland wl-layer-shell protocol
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base wayland

.include <bsd.port.mk>
