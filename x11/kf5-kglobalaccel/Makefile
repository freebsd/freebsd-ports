PORTNAME=	kglobalaccel
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library to add support for global workspace shortcuts
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kglobalaccel/html/index.html

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz xorg
USE_KDE=	config coreaddons crash dbusaddons i18n service \
		windowsystem \
		ecm_build
USE_QT=		core dbus gui linguisttools widgets x11extras \
		buildtools_build qmake_build testlib_build
USE_XORG=	x11 xcb

.include <bsd.port.mk>
