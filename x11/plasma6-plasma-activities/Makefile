PORTNAME=	plasma-activities
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	Core components for the KDE Activity concept
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext gl kde:6 pathfix qt:6 tar:xz
USE_KDE=	config coreaddons \
		ecm:build
USE_QT=		base declarative
USE_GL=		gl opengl

.include <bsd.port.mk>
