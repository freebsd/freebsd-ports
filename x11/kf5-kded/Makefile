PORTNAME=	kded
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 extensible daemon for providing system level services
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kded/html/index.html

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons crash dbusaddons service \
		doctools_build ecm_build
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
