PORTNAME=	kdeplasma-addons
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 addons to improve the Plasma experience
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig qt:5 tar:xz \
		xorg
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		holidays i18n init jobwidgets kcmutils kdeclarative kio \
		newstuff notifications package plasma-framework runner service \
		solid sonnet unitconversion widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative graphicaleffects gui location \
		network webchannel widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

OPTIONS_DEFINE=	PURPOSE QTWEBENGINE
OPTIONS_DEFAULT=	PURPOSE
OPTIONS_DEFAULT_amd64=	QTWEBENGINE
OPTIONS_DEFAULT_i386=	QTWEBENGINE
OPTIONS_SUB=	YES

PURPOSE_DESC=	Enable 'QuickShare' applet
PURPOSE_USE=	KDE=purpose
PURPOSE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF5Purpose

QTWEBENGINE_DESC=	Add dependency on qt5-webengine
QTWEBENGINE_USE=	qt=webengine
QTWEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngine

.include <bsd.port.mk>
