PORTNAME=	theseus-ship
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2.0
PORTREVISION=	3
CATEGORIES=	x11-wm wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	01030427325c.patch:-p1 # https://github.com/winft/theseus-ship/pull/17

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Wayland and X11 compositor for KDE Plasma Desktop
WWW=		https://github.com/winft/theseus-ship

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libwayland-server.so:graphics/wayland \
		libWraplandServer.so:graphics/wrapland \
		libcomo-script.so.0:x11-toolkits/como \
		libwlroots-0.18.so:x11-toolkits/wlroots018 \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-icccm.so:x11/xcb-util-wm

CONFLICTS_INSTALL=	plasma6-kwin # bin/kwin_wayland

USES=		cmake:testing gettext-tools kde:6 pkgconfig qt:6 xorg
USE_GITHUB=	yes
USE_KDE=	colorscheme config coreaddons crash dbusaddons decoration \
		ecm:build globalaccel i18n kcmutils kscreenlocker newstuff:build \
		notifications package svg widgetsaddons windowsystem xmlgui
USE_LDCONFIG=	yes
USE_QT=		base declarative tools
USE_XORG=	pixman x11 xcb xi
GH_ACCOUNT=	winft
GH_PROJECT=	theseus-ship
PLIST_SUB=	VERSION=${PORTVERSION}
LDFLAGS+=	-Wl,--as-needed # GL, ICE/SM/Xext, input, KF6Service

OPTIONS_DEFINE=	BREEZE
OPTIONS_DEFAULT=BREEZE

BREEZE_DESC=		Default window decoration plugin
BREEZE_USE=		KDE=breeze
BREEZE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Breeze

.include <bsd.port.mk>
