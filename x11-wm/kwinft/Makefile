PORTNAME=	kwinft
DISTVERSIONPREFIX=	${PORTNAME}@
DISTVERSION=	5.27.0
PORTREVISION=	4
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland compositor and X11 window manager
WWW=		https://gitlab.com/kwinft/kwinft

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libwayland-server.so:graphics/wayland \
		libWraplandServer.so:graphics/wrapland \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-icccm.so:x11/xcb-util-wm
TEST_DEPENDS=	${qt-testlib_PORT:T}>0:${qt-testlib_PORT}

CONFLICTS_INSTALL=	plasma5-kwin # bin/kwin_wayland

USES=		cmake:testing gl kde:5 pkgconfig python:run qt:5 shebangfix xorg
USE_GITLAB=	yes
USE_GL=		egl
USE_KDE=	ecm:build auth config configwidgets \
		coreaddons crash dbusaddons decoration globalaccel i18n \
		idletime kcmutils kdeclarative kio kscreenlocker newstuff \
		notifications package plasma-framework service \
		widgetsaddons windowsystem xmlgui
USE_LDCONFIG=	yes
USE_QT=		qmake:build buildtools:build core dbus declarative gui \
		multimedia:run quickcontrols2:run widgets x11extras
USE_XORG=	pixman x11 xcb xi
SHEBANG_FILES=	effect/effects/*.py kconf_update/*.py kconf_update/*.pl
PLIST_SUB=	VERSION=${PORTVERSION}
LDFLAGS+=	-Wl,--as-needed # GL, ICE/SM/Xext, glib, intl, Qt5*, KF5*

OPTIONS_DEFINE=	BREEZE DOCS QA11Y
OPTIONS_DEFAULT=BREEZE QA11Y

BREEZE_DESC=		Default window decoration plugin
BREEZE_USE=		KDE=breeze
BREEZE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Breeze

DOCS_USE=		KDE=doctools:build
DOCS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF5DocTools

QA11Y_DESC=		Accessibility (focus tracking) for Zoom effect
QA11Y_LIB_DEPENDS=	libqaccessibilityclient-qt5.so:accessibility/libqaccessibilityclient@qt5
QA11Y_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_QAccessibilityClient

post-patch:
# Convert nodes from linprocfs(5) to procfs(5)
# XXX kwinft lacks https://invent.kde.org/plasma/kwin/-/commit/1bc7afe8aaa9
	@${REINPLACE_CMD} -e '/proc/,+1s,/exe,/file,' \
		${WRKSRC}/base/wayland/filtered_display.cpp \
		${WRKSRC}/desktop/kde/service_utils.h
# Generic nodes are not supported by procfs(5)
	@${REINPLACE_CMD} -e '/mounts/s,/proc,/compat/linux&,' \
		${WRKSRC}/debug/perf/ftrace_impl.cpp

.include "${.CURDIR:H:H}/x11-toolkits/wlroots016/override.mk"
.include <bsd.port.mk>
