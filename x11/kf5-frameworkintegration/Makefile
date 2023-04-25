PORTNAME=	frameworkintegration
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 workspace and cross-framework integration plugins

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig \
		qt:5 tar:xz xorg
USE_KDE=	auth attica codecs config configwidgets coreaddons i18n \
		iconthemes newstuff notifications widgetsaddons \
		ecm:build
USE_QT=		core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	xcb xcursor

.include <bsd.port.mk>
