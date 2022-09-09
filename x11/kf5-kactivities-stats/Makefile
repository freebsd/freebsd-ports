PORTNAME=	kactivities-stats
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 statistics for activities
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kactivities/html/index.html

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs

USES=		cmake compiler:c++11-lib kde:5 pathfix qt:5 tar:xz
USE_KDE=	activities config \
		ecm_build
USE_QT=		core dbus sql \
		buildtools_build qmake_build

.include <bsd.port.mk>
