PORTNAME=	kscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	KDE screen management software
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gettext kde:6 qt:6 tar:xz gl xorg
USE_KDE=	colorscheme config configwidgets coreaddons dbusaddons \
		globalaccel i18n iconthemes kcmutils layer-shell-qt libkscreen \
		libplasma svg widgetsaddons windowsystem xmlgui \
		ecm:build
USE_GL=		gl opengl
USE_QT=		base declarative sensors
USE_XORG=	x11 xcb xext xi

.include <bsd.port.mk>
