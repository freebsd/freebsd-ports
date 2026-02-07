PORTNAME=	kglobalaccel
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library to add support for global workspace shortcuts

DEPRECATED=	has its functionality stripped compared to a kf6 variant

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz xorg
USE_KDE=	config coreaddons crash dbusaddons service \
		windowsystem \
		ecm:build
USE_QT=		core dbus gui linguisttools widgets x11extras \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11 xcb

# KF6 coinstallability
CMAKE_ON=	KF6_COMPAT_BUILD

.include <bsd.port.mk>
