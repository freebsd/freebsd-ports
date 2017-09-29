# Created by: tcberner
# $FreeBSD$

PORTNAME=	kactivities
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	2
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 runtime and library to organize work in separate activities

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 pathfix tar:xz
USE_KDE=	bookmarks config configwidgets coreaddons dbusaddons ecm \
		globalaccel i18n kcmutils kdeclarative  kio package \
		service widgetsaddons windowsystem xmlgui
USE_QT5=	buildtools_build core dbus gui network qmake_build qml \
		quick sql widgets

.include <bsd.port.mk>
