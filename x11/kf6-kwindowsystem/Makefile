PORTNAME=	kwindowsystem
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

COMMENT=	Access to the windowing system
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	ecm:build \
		plasma-wayland-protocols:build
USE_QT=		base declarative tools wayland
USE_XORG=	ice sm x11 xcb xext xfixes

.include <bsd.port.mk>
