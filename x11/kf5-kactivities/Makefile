PORTNAME=	kactivities
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 runtime and library to organize work in separate activities

BUILD_DEPENDS=	boost-libs>1.53.so:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext kde:5 pathfix qt:5 tar:xz
USE_KDE=	bookmarks config configwidgets coreaddons dbusaddons ecm \
		globalaccel i18n kcmutils kdeclarative  kio package \
		service widgetsaddons windowsystem xmlgui
USE_QT=		buildtools_build core dbus declarative gui network qmake_build \
		sql widgets

.include <bsd.port.mk>
