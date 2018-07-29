# $FreeBSD$

PORTNAME=	kactivitymanagerd
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	System service to manage user's activities, track the usage patterns

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons ecm \
		globalaccel i18n kio service widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network sql widgets xml \
		buildtools_build qmake_build

# https://bugs.kde.org/show_bug.cgi?id=305529#c10
CMAKE_ARGS+=	-DCMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS=-rdynamic

.include <bsd.port.mk>
