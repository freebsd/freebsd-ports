PORTNAME=	kwin
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-wm kde kde-plasma

COMMENT=	Easy to use, but flexible, Wayland Compositor
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		hwdata>0:misc/hwdata \
		wayland-protocols>0:graphics/wayland-protocols \
		Xwayland:x11-servers/xwayland
LIB_DEPENDS=	libdisplay-info.so:sysutils/libdisplay-info \
		libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinput.so:x11/libinput \
		liblcms2.so:graphics/lcms2 \
		libpipewire-0.3.so:multimedia/pipewire \
		libqaccessibilityclient-qt6.so:accessibility/libqaccessibilityclient@qt6 \
		libudev.so:devel/libudev-devd \
		libwayland-client.so:graphics/wayland \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcvt.so:x11/libxcvt \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	hwdata>0:misc/hwdata \
		Xwayland:x11-servers/xwayland

USES=		cmake gettext gl kde:6 pkgconfig python qt:6 shebangfix tar:xz \
		xorg
USE_GL=		egl gbm gl opengl
USE_KDE=	activities attica auth colorscheme config \
		configwidgets coreaddons crash dbusaddons decoration \
		globalaccel globalacceld guiaddons i18n idletime kcmutils \
		kdeclarative kpipewire kscreenlocker libplasma newstuff \
		notifications package runner service svg wayland widgetsaddons \
		windowsystem xmlgui \
		ecm:build plasma-wayland-protocols:build \
		aurorae:run breeze:run
USE_QT=		base declarative multimedia sensors tools wayland
USE_XORG=	ice sm x11 xcb xext xi

DATADIR=	${PREFIX}/share/kwin-wayland
BINARY_ALIAS=	python3=${PYTHON_CMD}
SHEBANG_FILES=	src/plugins/strip-effect-metadata.py

CONFLICTS_INSTALL=	theseus-ship # bin/kwin_wayland

OPTIONS_DEFINE=		EI
OPTIONS_DEFAULT=	EI
OPTIONS_SUB=		yes

EI_DESC=		Emulated input for Wayland
EI_LIB_DEPENDS=		libei.so:x11/libei
EI_CMAKE_BOOL=		KWIN_BUILD_EIS

.include <bsd.port.mk>
