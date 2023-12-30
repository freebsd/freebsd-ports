PORTNAME=	plasma-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	Qt Platform Theme integration plugins for the Plasma workspaces
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	hack-font>0:x11-fonts/hack-font \
		noto-basic>0:x11-fonts/noto-basic \
		noto-emoji>0:x11-fonts/noto-emoji

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_KDE=	bookmarks breeze colorscheme completion config configwidgets \
		coreaddons guiaddons i18n iconthemes itemviews jobwidgets kio \
		notifications service solid statusnotifieritem widgetsaddons \
		windowsystem xdg-desktop-portal-kde xmlgui \
		ecm:build plasma-wayland-protocols:build
USE_GL=		gl opengl
USE_XORG=	x11 xcb xcursor
USE_QT=		base declarative wayland

CMAKE_ON=	BUILD_QT6
CMAKE_OFF=	BUILD_QT5

.include <bsd.port.mk>
