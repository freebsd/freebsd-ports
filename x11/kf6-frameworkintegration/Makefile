PORTNAME=	frameworkintegration
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

COMMENT=	Integration of Qt application with KDE workspaces
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libAppStreamQt.so:devel/appstream-qt \
		libpackagekitqt6.so:ports-mgmt/packagekit-qt \

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	attica colorscheme config coreaddons i18n iconthemes newstuff \
		notifications package widgetsaddons \
		ecm:build
USE_QT=		base

.include <bsd.port.mk>
