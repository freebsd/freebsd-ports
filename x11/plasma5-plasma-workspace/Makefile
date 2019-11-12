# $FreeBSD$

PORTNAME=	plasma-workspace
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Plasma workspace

LIB_DEPENDS=	libcln.so:math/cln \
		libdbusmenu-qt5.so:devel/libdbusmenu-qt \
		libqalculate.so:math/libqalculate \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util
RUN_DEPENDS=	ck-launch-session:sysutils/consolekit2\
		iceauth:x11/iceauth \
		xsetroot:x11/xsetroot \
		xset:x11/xset \
		xmessage:x11/xmessage \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:x11/xkeyboard-config \
		iso-codes>=0:misc/iso-codes \
		${LOCALBASE}/bin/genv:sysutils/coreutils


USES=		cmake compiler:c++11-lib cpe gettext kde:5 pkgconfig \
		qt:5 tar:xz xorg
USE_KDE=	activities activities-stats activitymanagerd attica auth baloo bookmarks \
		codecs completion config configwidgets coreaddons crash \
		dbusaddons doctools emoticons filemetadata globalaccel \
		guiaddons holidays i18n iconthemes idletime init itemmodels \
		itemviews jobwidgets js jsembed kcmutils kdeclarative \
		kdelibs4support kdesu kdewebkit kio kscreenlocker \
		notifications package pty kwin libkscreen libksysguard \
		newstuff notifyconfig parts people plasma-framework \
		plasma-integration prison runner service solid sonnet \
		texteditor textwidgets unitconversion wallet wayland \
		widgetsaddons windowsystem xmlgui xmlrpcclient \
		breeze_run breeze-icons_run oxygen-icons5_run \
		kded_run milou_run
USE_QT=		concurrent core declarative dbus graphicaleffects gui network phonon4 \
		printsupport qdbus quickcontrols_run script sql \
		testlib webkit widgets x11extras xml \
		paths_run \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xau xcb xcomposite xext xfixes xft xkbfile xrender xtst

CMAKE_OFF=	BUILD_TESTING

# In 5.15 a file was moved from x11/plasma5-plasma-desktop to x11/plasma5-plasma-workspace:
CONFLICTS_INSTALL=	plasma5-plasma-desktop-5.14.*

.include <bsd.port.mk>
