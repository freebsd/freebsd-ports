PORTNAME=	kwin
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-wm kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 window manager
WWW=		https://www.kde.org/plasma-desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libepoll-shim.so:devel/libepoll-shim \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinput.so:x11/libinput \
		libudev.so:devel/libudev-devd \
		liblcms2.so:graphics/lcms2 \
		libwayland-cursor.so:graphics/wayland \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxkbcommon.so:x11/libxkbcommon \
		libxcvt.so:x11/libxcvt
BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		xwayland-devel>0:x11-servers/xwayland-devel \
		wayland-protocols>0:graphics/wayland-protocols \
		hwdata>0:misc/hwdata
RUN_DEPENDS=	xwayland-devel>0:x11-servers/xwayland-devel \
		hwdata>0:misc/hwdata

CONFLICTS_INSTALL=	kwinft # bin/kwin_wayland

USES=		cmake compiler:c++11-lib gettext gl gnome kde:5 pkgconfig qt:5 \
		shebangfix tar:xz xorg \
		python:run
USE_GL=		egl gbm
USE_GNOME=	glib20
USE_KDE=	activities attica auth breeze codecs config configwidgets \
		coreaddons crash dbusaddons decoration globalaccel i18n \
		idletime init itemviews kcmutils kdeclarative kscreenlocker \
		kwayland-integration newstuff notifications package \
		plasma-framework runner service wayland widgetsaddons \
		windowsystem xmlgui \
		doctools:build ecm:build plasma-wayland-protocols:build
USE_LDCONFIG=	yes
USE_QT=		concurrent core dbus declarative gui network uiplugin uitools \
		widgets x11extras xml \
		buildtools:build qmake:build testlib:build \
		multimedia:run quickcontrols2:run virtualkeyboard:run
USE_XORG=	ice sm x11 xcb xext xi
SHEBANG_FILES=	kconf_update/*.py \
		kconf_update/*.pl \
		src/effects/strip-effect-metadata.py

OPTIONS_DEFINE=		PIPEWIRE
OPTIONS_DEFAULT=	PIPEWIRE
PIPEWIRE_DESC=		Required for Wayland screencasting
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	KWIN_BUILD_PIPEWIRE

# A (hopefully) temporary workaround for
# https://gitlab.freedesktop.org/gstreamer/gstreamer/-/issues/2026
post-patch:
	${FIND} ${WRKSRC}/src/effects -name metadata.json -exec \
		${REINPLACE_CMD} -E \
			's|https://files.kde.org/plasma/kwin/effect-videos/([a-z_]+)\.ogv|https://arrowd.name/kwin-effect-videos/\1\.webm|' \
			{} \;

.include <bsd.port.mk>
