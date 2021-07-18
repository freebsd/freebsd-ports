PORTNAME=	krunner
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 parallelized query system

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons i18n kio package plasma-framework \
		service solid threadweaver \
		ecm_build
USE_QT=		concurrent core dbus declarative gui network widgets \
		buildtools_build qmake_build 

.include <bsd.port.mk>
