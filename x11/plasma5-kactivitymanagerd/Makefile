PORTNAME=	kactivitymanagerd
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	System service to manage user's activities, track the usage patterns

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons crash dbusaddons \
		ecm globalaccel i18n kio service widgetsaddons windowsystem \
		xmlgui
USE_QT=		concurrent core dbus gui network sql widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
