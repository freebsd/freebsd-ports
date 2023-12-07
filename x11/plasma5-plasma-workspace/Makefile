PORTNAME=	plasma-workspace
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	2
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Plasma workspace
WWW=		https://www.kde.org/plasma-desktop

LIB_DEPENDS=	libcln.so:math/cln \
		libdbusmenu-qt5.so:devel/libdbusmenu-qt@qt5 \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libicui18n.so:devel/icu \
		libqalculate.so:math/libqalculate \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util
RUN_DEPENDS=	ck-launch-session:sysutils/consolekit2 \
		iceauth:x11/iceauth \
		xmessage:x11/xmessage \
		xrdb:x11/xrdb \
		xset:x11/xset \
		xsetroot:x11/xsetroot \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:x11/xkeyboard-config \
		iso-codes>=0:misc/iso-codes \
		${LOCALBASE}/bin/genv:sysutils/coreutils \
		accountsservice>=0:sysutils/accountsservice

USES=		cmake compiler:c++11-lib cpe desktop-file-utils gettext gl \
		kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=		gl
USE_KDE=	activities activities-stats activitymanagerd archive attica \
		auth baloo bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons filemetadata globalaccel \
		guiaddons holidays i18n iconthemes idletime init itemmodels \
		itemviews jobwidgets js jsembed kcmutils kdeclarative kdesu \
		kio kscreenlocker kwin layer-shell-qt libkscreen \
		libksysguard newstuff notifications notifyconfig package parts \
		people phonon plasma-framework plasma-integration prison pty runner \
		service solid sonnet syntaxhighlighting texteditor textwidgets \
		unitconversion wallet wayland widgetsaddons windowsystem \
		xmlgui xmlrpcclient \
		doctools:build ecm:build \
		breeze-icons:run breeze:run kded:run kquickcharts:run \
		milou:run oxygen-icons5:run
USE_QT=		concurrent core dbus declarative graphicaleffects gui network \
		printsupport qdbus script sql svg wayland \
		widgets x11extras xml \
		buildtools:build qmake:build testlib:build \
		paths:run quickcontrols:run
USE_XORG=	ice sm x11 xau xcb xcomposite xcursor xext xfixes xft xi \
		xkbfile xrender xtst

CPE_VENDOR=	kde

CMAKE_OFF=	BUILD_TESTING

# In 5.15 a file was moved from x11/plasma5-plasma-desktop to x11/plasma5-plasma-workspace:
CONFLICTS_INSTALL=	plasma5-plasma-desktop-5.14.*

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/startkde/startplasma.cpp

post-stage:
	${INSTALL_SCRIPT} ${FILESDIR}/startplasma-wayland.sh ${STAGEDIR}/${LOCALBASE}/bin/

.include <bsd.port.mk>
