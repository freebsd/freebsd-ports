PORTNAME=	plasma-workspace
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	2
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Plasma workspace
WWW=		https://www.kde.org/plasma-desktop

LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt@qt5 \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libicui18n.so:devel/icu \
		libwayland-client.so:graphics/wayland \
		libLayerShellQtInterface.so:x11/plasma5-layer-shell-qt \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util
RUN_DEPENDS=	iceauth:x11/iceauth \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:x11/xkeyboard-config

USES=		cmake compiler:c++11-lib cpe gettext gl \
		kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=		gl
USE_KDE=	activities activities-stats activitymanagerd archive attica \
		auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons globalaccel \
		guiaddons holidays i18n iconthemes idletime init itemmodels \
		itemviews jobwidgets kcmutils kdeclarative kdesu \
		kio kscreenlocker kwin libkscreen libksysguard \
		newstuff notifications notifyconfig package parts people \
		plasma-framework plasma-integration prison pty runner service \
		solid sonnet syntaxhighlighting texteditor textwidgets unitconversion \
		wallet wayland widgetsaddons windowsystem xmlgui \
		ecm:build \
		breeze-icons:run breeze:run kded:run kquickcharts:run \
		oxygen-icons5:run
USE_QT=		concurrent core dbus declarative graphicaleffects gui network \
		phonon4 printsupport qdbus sql svg wayland \
		widgets x11extras xml \
		buildtools:build qmake:build testlib:build \
		paths:run quickcontrols:run
USE_XORG=	ice sm x11 xau xcb xcomposite xcursor xext xfixes xft xi xkbfile xrender xtst

CPE_VENDOR=	kde

CMAKE_OFF=	BUILD_TESTING

OPTIONS_DEFINE=		BALOO DOCS QALCULATE CONSOLEKIT POLKIT
OPTIONS_DEFAULT=	BALOO DOCS QALCULATE CONSOLEKIT POLKIT
OPTIONS_SUB=		yes
BALOO_DESC=		KDE Baloo support
QALCULATE_DESC=		Build QT Calculator
CONSOLEKIT_DESC=	Console Kit support
POLKIT_DESC=		Polkit

OPTIONS_EXCLUDE_purecap=	BALOO QALCULATE CONSOLEKIT POLKIT

.include <bsd.port.pre.mk>

# In 5.15 a file was moved from x11/plasma5-plasma-desktop to x11/plasma5-plasma-workspace:
CONFLICTS_INSTALL=	plasma5-plasma-desktop-5.14.*

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/startkde/startplasma.cpp

post-stage:
	${INSTALL_SCRIPT} ${FILESDIR}/startplasma-wayland.sh ${STAGEDIR}/${LOCALBASE}/bin/

.if !${ABI:Mpurecap}
USES+=		desktop-file-utils
USE_KDE+=	filemetadata kdewebkit js jsembed xmlrpcclient milou_run
USE_QT+=	script webkit
LIB_DEPENDS+=	libcln.so:math/cln
RUN_DEPENDS+=	xmessage:x11/xmessage \
		xrdb:x11/xrdb \
		xset:x11/xset \
		xsetroot:x11/xsetroot \
		iso-codes>=0:misc/iso-codes \
		${LOCALBASE}/bin/genv:sysutils/coreutils \
		accountsservice>=0:sysutils/accountsservice
.endif

.if ${PORT_OPTIONS:MBALOO}
USE_KDE+=	baloo
.endif

.if ${PORT_OPTIONS:MQALCULATE}
LIB_DEPENDS+=	libqalculate.so:math/libqalculate
.endif

.if ${PORT_OPTIONS:MCONSOLEKIT}
RUN_DEPENDS+=	ck-launch-session:sysutils/consolekit2
.endif

.include <bsd.port.post.mk>
