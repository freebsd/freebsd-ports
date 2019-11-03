# $FreeBSD$

PORTNAME=	kinit
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 process launcher to speed up launching KDE applications

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	completion config coreaddons crash doctools ecm i18n \
		jobwidgets kio service widgetsaddons windowsystem
USE_QT=		buildtools_build concurrent core dbus gui network qmake_build widgets
USE_XORG=	x11 xcb

.include <bsd.port.mk>
