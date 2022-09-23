PORTNAME=	plasma-framework
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 plugin based UI runtime used to write user interfaces

USES=		cmake compiler:c++11-lib gettext gl kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=		egl gl
USE_KDE=	activities archive auth codecs completion config \
		configwidgets coreaddons dbusaddons doctools:build globalaccel \
		guiaddons i18n iconthemes jobwidgets kirigami2 kio package \
		notifications service solid wayland windowsystem xmlgui kdeclarative \
		widgetsaddons
USE_QT=		buildtools:build concurrent core dbus declarative gui network qmake:build \
		script sql svg widgets x11extras xml
USE_XORG=	ice sm x11 xcb xext xrandr

.include <bsd.port.mk>
