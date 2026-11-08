PORTNAME=	kglobalacceld
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	Daemon providing Global Keyboard Shortcut (Accelerator) functionality

MAINTAINER=	kde@FreeBSD.org

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	config coreaddons globalaccel jobwidgets kio \
		service \
		ecm:build
USE_QT=		base

.include <bsd.port.mk>
