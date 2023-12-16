PORTNAME=	kglobalacceld
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	Daemon providing Global Keyboard Shortcut (Accelerator) functionality

MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	config coreaddons crash dbusaddons globalaccel jobwidgets kio \
		notifications service windowsystem \
		ecm:build
USE_QT=		base
USE_XORG=	x11 xcb

.include <bsd.port.mk>
