PORTNAME=	kglobalaccel
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library to add support for global workspace shortcuts

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz xorg
USE_KDE=	config coreaddons crash dbusaddons service \
		windowsystem \
		ecm:build
USE_QT=		core dbus gui linguisttools widgets x11extras \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11 xcb

.include <bsd.port.mk>
