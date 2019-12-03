# $FreeBSD$

PORTNAME=	kdeplasma-addons
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-toolkits kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 addons to improve the Plasma experience

USES=		cmake compiler:c++11-lib cpe gettext \
		kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	activities archive attica auth bookmarks codecs completion \
		config configwidgets coreaddons crash ecm emoticons guiaddons \
		holidays i18n iconthemes init itemmodels itemviews jobwidgets kcmutils \
		kdeclarative kdelibs4support kio kross newstuff notifications package parts\
		plasma-framework plasma-workspace runner service solid \
		sonnet textwidgets unitconversion widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus declarative graphicaleffects gui location network \
		printsupport script webchannel widgets x11extras xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	PURPOSE QTWEBENGINE
OPTIONS_DEFAULT=	PURPOSE
OPTIONS_DEFAULT_amd64=	QTWEBENGINE
OPTIONS_DEFAULT_i386=	QTWEBENGINE
OPTIONS_DEFAULT_powerpc64=	${OPTIONS_DEFAULT_powerpc64_${OSREL:R}}
OPTIONS_DEFAULT_powerpc64_13=	WEBENGINE
OPTIONS_SUB=	YES

PURPOSE_DESC=	Enable 'QuickShare' applet
PURPOSE_USE=	KDE=purpose
PURPOSE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF5Purpose

QTWEBENGINE_DESC=	Add dependency on qt5-webengine
QTWEBENGINE_USE=	qt=webengine
QTWEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngine

.include <bsd.port.mk>
