# $FreeBSD$

PORTNAME=	frameworkintegration
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 workspace and cross-framework integration plugins

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig \
		qt:5 tar:xz xorg
USE_KDE=	auth attica codecs config configwidgets coreaddons ecm i18n \
		iconthemes kio newstuff notifications package widgetsaddons
USE_QT=		buildtools_build core dbus gui network qmake_build widgets \
		x11extras xml
USE_XORG=	xcb xcursor

.include <bsd.port.mk>
