PORTNAME=	plasma-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	Qt Platform Theme integration plugins for the Plasma workspaces
MAINTAINER=	kde@FreeBSD.org

RUN_DEPENDS=	hack-font>0:x11-fonts/hack-font \
		noto-basic>0:x11-fonts/noto-basic \
		noto-emoji>0:x11-fonts/noto-emoji

USES=		cmake gettext kde:6 qt:6 shebangfix tar:xz
USE_KDE=	breeze xdg-desktop-portal-kde \
		ecm:build plasma-wayland-protocols:build
USE_QT=		base

CMAKE_ON=	BUILD_QT6
CMAKE_OFF=	BUILD_QT5

SHEBANG_FILES=	qt6/src/platformtheme/*.pl

.include <bsd.port.mk>
