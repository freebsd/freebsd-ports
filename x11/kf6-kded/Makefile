PORTNAME=	kded
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Central daemon of KDE work spaces

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	config coreaddons crash dbusaddons service \
		doctools:build ecm:build
USE_QT=		base \
		declarative:build

.include <bsd.port.mk>
