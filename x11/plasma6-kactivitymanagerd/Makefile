PORTNAME=	kactivitymanagerd
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-plasma

COMMENT=	System service to manage user's activities, track the usage patterns etc
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	colorscheme config configwidgets coreaddons crash dbusaddons \
		globalaccel i18n kio service widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		5compat base sqldriver-sqlite
USE_XORG=	x11

.include <bsd.port.mk>
