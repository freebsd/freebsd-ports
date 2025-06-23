PORTNAME=	lxqt-panel
PORTVERSION=	2.2.2
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Panel for the LXQt2 desktop
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbusmenu-lxqt.so:devel/libdbusmenu-lxqt \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-util.so:x11/xcb-util \
		libsysstat-qt6.so:sysutils/libsysstat-qt6 \
		libxcb-image.so:x11/xcb-util-image
BUILD_DEPENDS=	lxqt-menu-data>=2.0.0:x11/lxqt-menu-data
RUN_DEPENDS= 	lxqt-menu-data>=2.0.0:x11/lxqt-menu-data

USES=		cmake compiler:c++17-lang gettext-runtime kde:6 qt:6 gnome \
		lxqt:2 localbase:ldflags perl5 pkgconfig tar:xz xorg
USE_PERL5=	build
USE_QT=		base:run tools:build svg
USE_KDE=	layer-shell-qt windowsystem
USE_LXQT=	buildtools2 lxqt globalkeys qt6xdg
USE_XORG=	ice sm x11 xcb xcomposite xdamage xext xfixes xrender xtst
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
