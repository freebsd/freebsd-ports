PORTNAME=	frameworkintegration
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

COMMENT=	Integration of Qt application with KDE workspaces
MAINTAINER=	kde@FreeBSD.org

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	attica5 colorscheme config coreaddons i18n iconthemes newstuff \
		notifications widgetsaddons \
		ecm:build
USE_QT=		base

.include <bsd.port.mk>
