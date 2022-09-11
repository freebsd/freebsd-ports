PORTNAME=	krunner
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 parallelized query system

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	activities config coreaddons i18n kio package plasma-framework \
		service solid threadweaver \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network widgets \
		buildtools:build qmake:build

.include <bsd.port.mk>
