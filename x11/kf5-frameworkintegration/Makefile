PORTNAME=	frameworkintegration
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

PATCH_SITES=	https://invent.kde.org/frameworks/frameworkintegration/commit/
PATCHFILES=	675802e706a737c008aa74600ac804b06db52140.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 workspace and cross-framework integration plugins

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig \
		qt:5 tar:xz xorg
USE_KDE=	auth attica codecs config configwidgets coreaddons i18n \
		iconthemes newstuff notifications widgetsaddons \
		ecm_build
USE_QT=		core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_XORG=	xcb xcursor

.include <bsd.port.mk>
