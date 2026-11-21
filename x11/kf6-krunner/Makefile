PORTNAME=	krunner
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Framework for providing different actions given a string query

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	config coreaddons i18n itemmodels windowsystem \
		ecm:build
USE_QT=		base \
		declarative:build
USE_XORG=	x11

.include <bsd.port.mk>
