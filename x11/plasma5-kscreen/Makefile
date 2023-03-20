PORTNAME=	kscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 screen management library
WWW=		https://www.kde.org/plasma-desktop

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		globalaccel i18n kcmutils kdeclarative layer-shell-qt \
		libkscreen package plasma-framework service widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		core dbus declarative gui network sensors widgets x11extras \
		xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11 xcb xext xi

.include <bsd.port.mk>
