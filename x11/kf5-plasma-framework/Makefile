# Created by: tcberner
# $FreeBSD$

PORTNAME=	plasma-framework
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 plugin based UI runtime used to write user interfaces

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 pkgconfig tar:xz
USE_GL=		egl gl
USE_KDE=	activities archive auth codecs completion config \
		configwidgets coreaddons dbusaddons doctools globalaccel \
		guiaddons i18n iconthemes jobwidgets kio package \
		notifications service wayland windowsystem xmlgui kdeclarative \
		widgetsaddons
USE_QT5=	buildtools_build core dbus gui network qmake_build qml \
		quick script sql svg widgets x11extras xml
USE_XORG=	ice sm x11 xcb xext xrandr

.include <bsd.port.mk>
