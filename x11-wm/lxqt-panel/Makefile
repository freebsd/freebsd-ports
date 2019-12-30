# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-panel
PORTVERSION=	0.14.1
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Panel for the LXQt desktop

LICENSE=	LGPL21+

LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-util.so:x11/xcb-util \
		libsysstat-qt5.so:sysutils/libsysstat
RUN_DEPENDS=	lxmenu-data>=0.1.2:x11/lxmenu-data

USES=	cmake compiler:c++14-lang gettext-runtime kde:5 qt:5 gnome \
	localbase:ldflags lxqt pkgconfig tar:xz xorg
USE_QT=	buildtools_build qmake_build core dbus gui svg widgets \
	x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt globalkeys qtxdg
USE_XORG=	ice sm x11 xcb xcomposite xdamage xext xfixes xrender
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_RADIO=	SOUND
OPTIONS_RADIO_SOUND=	ALSA PULSEAUDIO
OPTIONS_DEFINE=	CPULOAD MOUNT
OPTIONS_DEFAULT=	PULSEAUDIO

CPULOAD_DESC=	CPU stat plugin
MOUNT_DESC=	Mount removable devices support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_ON=	-DVOLUME_USE_PULSEAUDIO:BOOL=OFF
CPULOAD_LIB_DEPENDS=	libstatgrab.so:devel/libstatgrab
CPULOAD_CMAKE_OFF=	-DCPULOAD_PLUGIN:BOOL=OFF
PULSEAUDIO_CMAKE_ON=	-DVOLUME_USE_ALSA:BOOL=OFF
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
MOUNT_USE=	kde=solid
MOUNT_CMAKE_OFF=	-DMOUNT_PLUGIN:BOOL=OFF
OPTIONS_SUB=	yes

LDFLAGS+=	-Xlinker --export-dynamic

CMAKE_ARGS+=	-DSENSORS_PLUGIN:BOOL=OFF \
	-DNETWORKMONITOR_PLUGIN:BOOL=OFF \
	-DWITH_SCREENSAVER_FALLBACK:BOOL=OFF

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MALSA} && ! ${PORT_OPTIONS:MPULSEAUDIO}
CMAKE_ARGS+=	-DVOLUME_PLUGIN:BOOL=OFF
PLIST_SUB+=	SOUND="@comment "
.elif ${PORT_OPTIONS:MALSA} || ${PORT_OPTIONS:MPULSEAUDIO}
PLIST_SUB+=	SOUND=""
.endif

.include <bsd.port.mk>
