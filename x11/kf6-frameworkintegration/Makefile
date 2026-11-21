PORTNAME=	frameworkintegration
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Integration of Qt application with KDE workspaces

LIB_DEPENDS=	libAppStreamQt.so:devel/appstream-qt \
		libpackagekitqt6.so:ports-mgmt/packagekit-qt \

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	colorscheme config i18n iconthemes newstuff \
		notifications package widgetsaddons \
		ecm:build
USE_QT=		base \
		declarative:build

.include <bsd.port.mk>
