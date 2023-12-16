PORTNAME=	frameworks
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde
PKGNAMEPREFIX=	kf6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE frameworks meta port
WWW=		https://api.kde.org/frameworks/index.html

USES=		kde:6 metaport qt:6
# remove bluez-qt as we do not have bluez
USE_KDE=	${_USE_FRAMEWORKS_ALL}
# pull bsd.qt.mk for QT_PLUGINDIR in the kf5-dependencies
USE_QT=		#

.include <bsd.port.mk>
