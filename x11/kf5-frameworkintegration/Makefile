# Created by: tcberner
# $FreeBSD$

PORTNAME=	frameworkintegration
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 workspace and cross-framework integration plugins

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 pkgconfig \
		tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons ecm i18n \
		iconthemes kio notifications package widgetsaddons
USE_QT5=	buildtools_build core dbus gui qmake_build widgets \
		x11extras xml
USE_XORG=	xcb xcursor

.include <bsd.port.mk>
