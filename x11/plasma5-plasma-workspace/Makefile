PORTNAME=	plasma-workspace
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	2
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Plasma workspace

LIB_DEPENDS=	libcln.so:math/cln \
		libdbusmenu-qt5.so:devel/libdbusmenu-qt \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libqalculate.so:math/libqalculate \
		libwayland-client.so:graphics/wayland \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util
RUN_DEPENDS=	ck-launch-session:sysutils/consolekit2\
		iceauth:x11/iceauth \
		xmessage:x11/xmessage \
		xrdb:x11/xrdb \
		xset:x11/xset \
		xsetroot:x11/xsetroot \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:x11/xkeyboard-config \
		iso-codes>=0:misc/iso-codes \
		${LOCALBASE}/bin/genv:sysutils/coreutils

USES=		cmake compiler:c++11-lib cpe desktop-file-utils gettext kde:5 \
		pkgconfig qt:5 tar:xz xorg
USE_KDE=	activities activities-stats activitymanagerd archive attica \
		auth baloo bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons filemetadata globalaccel \
		guiaddons holidays i18n iconthemes idletime init itemmodels \
		itemviews jobwidgets js jsembed kcmutils kdeclarative kdesu \
		kdewebkit kio kscreenlocker kwin libkscreen libksysguard \
		newstuff notifications notifyconfig package parts people \
		plasma-framework plasma-integration prison pty runner service \
		solid sonnet texteditor textwidgets unitconversion wallet \
		wayland widgetsaddons windowsystem xmlgui xmlrpcclient \
		doctools_build ecm_build \
		breeze-icons_run breeze_run kded_run kquickcharts_run \
		milou_run oxygen-icons5_run
USE_QT=		concurrent core dbus declarative graphicaleffects gui network \
		phonon4 printsupport qdbus script sql svg wayland webkit \
		widgets x11extras xml \
		buildtools_build qmake_build testlib_build \
		paths_run quickcontrols_run
USE_XORG=	ice sm x11 xau xcb xcomposite xcursor xext xfixes xft xkbfile xrender xtst

CPE_VENDOR=	kde

CMAKE_OFF=	BUILD_TESTING

# In 5.15 a file was moved from x11/plasma5-plasma-desktop to x11/plasma5-plasma-workspace:
CONFLICTS_INSTALL=	plasma5-plasma-desktop-5.14.*

post-stage:
	${INSTALL_SCRIPT} ${FILESDIR}/startplasma-wayland.sh ${STAGEDIR}/${LOCALBASE}/bin/

.include <bsd.port.mk>
