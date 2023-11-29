PORTNAME=	plasma-activities-stats
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for accessing the usage data collected by the activities system

BUILD_DEPENDS=	boost-libs>1.53:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext kde:6 pathfix qt:6 tar:xz
USE_KDE=	activities config \
		ecm:build
USE_QT=		base

.include <bsd.port.mk>
