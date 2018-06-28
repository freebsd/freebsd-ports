# $FreeBSD$

PORTNAME=	kscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 screen management library

USES=		cmake:outsource cpe gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons ecm \
		globalaccel i18n libkscreen widgetsaddons xmlgui
USE_QT=		core dbus gui network qml quick testlib widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
