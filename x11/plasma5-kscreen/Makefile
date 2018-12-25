# $FreeBSD$

PORTNAME=	kscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	2
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 screen management library

USES=		cmake compiler:c++11-lang cpe gettext kde:5 qt:5 \
		tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons ecm \
		globalaccel i18n kdeclarative libkscreen plasma-framework \
		widgetsaddons xmlgui
USE_QT=		core dbus declarative gui network testlib widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
