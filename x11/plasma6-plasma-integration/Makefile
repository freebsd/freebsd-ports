PORTNAME=	plasma-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma
PKGNAMESUFFIX=	-${FLAVOR}

COMMENT=	Plasma 6 theme integration plugins for Qt${FLAVOR:S/qt//}
MAINTAINER=	kde@FreeBSD.org

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	hack-font>0:x11-fonts/hack-font \
		noto-basic>0:x11-fonts/noto-basic \
		noto-emoji>0:x11-fonts/noto-emoji

USES=		cmake gettext gl tar:xz xorg
USES+=		${${FLAVOR}_USES}
USE_KDE=	${${FLAVOR}_USE_KDE}
USE_GL=		gl opengl
USE_XORG=	x11 xcb xcursor
USE_QT=		${${FLAVOR}_USE_QT}

CMAKE_ON=	${${FLAVOR}_CMAKE_ON}
CMAKE_OFF=	${${FLAVOR}_CMAKE_OFF}

PLIST=		${.CURDIR}/pkg-plist.${FLAVOR}

# Sync Qt5 flavor with Qt6
KDE_PLASMA_VERSION=	${KDE_PLASMA6_VERSION}
PKGNAMEPREFIX?=		plasma6-
DESCR=		${.CURDIR:H:H}/x11/plasma6-plasma/pkg-descr

# Qt6 flavor
qt6_USES=	kde:6 qt:6
qt6_USE_KDE=	bookmarks breeze colorscheme completion config configwidgets \
		coreaddons guiaddons i18n iconthemes itemviews jobwidgets kio \
		notifications service solid statusnotifieritem widgetsaddons \
		windowsystem xdg-desktop-portal-kde xmlgui \
		ecm:build plasma-wayland-protocols:build
qt6_USE_QT=	base declarative wayland
qt6_CMAKE_ON=	BUILD_QT6
qt6_CMAKE_OFF=	BUILD_QT5

# Qt5 flavor
qt5_USES=	kde:5 pkgconfig qt:5
qt5_USE_KDE=	config configwidgets guiaddons i18n iconthemes kio \
		notifications wayland windowsystem xmlgui \
		ecm:build plasma-wayland-protocols:build
qt5_USE_QT=	core gui quickcontrols2 wayland x11extras \
		buildtools:build qmake:build
qt5_CMAKE_ON=	BUILD_QT5
qt5_CMAKE_OFF=	BUILD_QT6

.include <bsd.port.mk>
