PORTNAME=	kinit
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 process launcher to speed up launching KDE applications

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	completion config coreaddons crash dbusaddons i18n \
		jobwidgets kio service solid widgetsaddons windowsystem \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network widgets \
		buildtools:build qmake:build
USE_XORG=	x11 xcb

.include <bsd.port.mk>
