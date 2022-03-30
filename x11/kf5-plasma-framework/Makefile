PORTNAME=	plasma-framework
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

EXTRA_PATCHES=	${PATCHDIR}/7352045b388f4b0ef553706bd219457e5018ce4e.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 plugin based UI runtime used to write user interfaces

USES=		cmake compiler:c++11-lib gettext gl kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=		egl gl
USE_KDE=	activities archive auth codecs completion config \
		configwidgets coreaddons dbusaddons doctools_build globalaccel \
		guiaddons i18n iconthemes jobwidgets kirigami2 kio package \
		notifications service wayland windowsystem xmlgui kdeclarative \
		widgetsaddons
USE_QT=		buildtools_build concurrent core dbus declarative gui network qmake_build \
		script sql svg widgets x11extras xml
USE_XORG=	ice sm x11 xcb xext xrandr

.include <bsd.port.mk>
