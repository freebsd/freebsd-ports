PORTNAME=	kactivities
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 runtime and library to organize work in separate activities

BUILD_DEPENDS=	boost-libs>1.53:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext kde:5 pathfix qt:5 tar:xz
USE_KDE=	config coreaddons service \
		ecm_build
USE_QT=		core dbus declarative gui network sql \
		buildtools_build qmake_build

.include <bsd.port.mk>
