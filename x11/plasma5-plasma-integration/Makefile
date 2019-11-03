# $FreeBSD$

PORTNAME=	plasma-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Platform Theme integration plugins for the Plasma workspaces

RUN_DEPENDS=	hack-font>=0:x11-fonts/hack-font

USES=		cmake compiler:c++11-lib cpe gettext kde:5 pkgconfig \
		qt:5 shebangfix tar:xz xorg
USE_KDE=	auth bookmarks breeze codecs completion config configwidgets \
		coreaddons ecm i18n iconthemes itemviews jobwidgets kio \
		notifications service solid wayland \
		widgetsaddons windowsystem xmlgui \
		qqc2-desktop-style_run
USE_QT=		concurrent core declarative dbus gui network quickcontrols2 widgets \
		x11extras xml \
		buildtools_build qmake_build
USE_XORG=	xcb xcursor

SHEBANG_FILES=	src/platformtheme/fonts_akregator.pl \
		src/platformtheme/fonts_global.pl \
		src/platformtheme/fonts_kate.pl \
		src/platformtheme/mono_font.pl

OPTIONS_SINGLE=	NOTO
OPTIONS_SINGLE_NOTO=	LIGHT BIG
OPTIONS_DEFAULT=	LIGHT
NOTO_DESC=	KDE default font
LIGHT_DESC=	Use noto-light
BIG_DESC=	Use complete noto

LIGHT_RUN_DEPENDS=	noto-basic>=0:x11-fonts/noto-basic
BIG_RUN_DEPENDS=	noto>=0:x11-fonts/noto

.include <bsd.port.mk>
