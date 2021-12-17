PORTNAME=	kscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 screen management library

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		globalaccel i18n kcmutils kdeclarative libkscreen package \
		plasma-framework service widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT=		core dbus declarative gui network sensors widgets xml \
		buildtools_build qmake_build testlib_build

.include <bsd.port.mk>
