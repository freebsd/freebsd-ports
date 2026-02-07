PORTNAME=	kwindowsystem
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for access to the windowing system

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms

USES=		cmake compiler:c++11-lib kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	ecm:build
USE_QT=		core gui linguisttools widgets x11extras \
		buildtools:build qmake:build testlib:build
USE_XORG=	ice sm x11 xcb xext xfixes xrender

.include <bsd.port.mk>
