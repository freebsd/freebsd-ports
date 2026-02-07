PORTNAME=	plasma-desktop
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Plasma Desktop

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols \
		xf86-input-libinput>0:x11-drivers/xf86-input-libinput \
		libinput>0:x11/libinput
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libicuuc.so:devel/icu \
		libkaccounts6.so:net-im/kaccounts-integration \
		liboauth2plugin.so:sysutils/signon-plugin-oauth2@qt6 \
		libpackagekitqt6.so:ports-mgmt/packagekit-qt \
		libwayland-client.so:graphics/wayland \
		libxcb-util.so:x11/xcb-util \
		libxkbcommon.so:x11/libxkbcommon \
		libxkbfile.so:x11/libxkbfile
RUN_DEPENDS=	noto-emoji>0:x11-fonts/noto-emoji \
		xdg-user-dir:devel/xdg-user-dirs

USES=		cmake gettext gl gnome kde:6 pkgconfig python qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_GNOME=	intltool
USE_KDE=	activities activities-stats attica auth baloo bookmarks \
		codecs colorscheme completion config configwidgets coreaddons \
		crash dbusaddons doctools filemetadata globalaccel guiaddons \
		i18n iconthemes itemmodels itemviews jobwidgets kcmutils kio \
		libksysguard libplasma newstuff notifications notifyconfig \
		package plasma-workspace plasma5support runner service solid \
		sonnet svg widgetsaddons windowsystem xmlgui \
		ecm:build \
		kirigami-addons:run kirigami2:run kpipewire:run \
		qqc2-desktop-style:run
USE_QT=		5compat base declarative svg wayland
USE_XORG=	x11 xcb xcursor xext xfixes xi xrender

OPTIONS_DEFINE=		SDL X11
OPTIONS_DEFAULT=	X11
OPTIONS_GROUP=		IM
IM_DESC=		Input Method Support
OPTIONS_GROUP_IM=	IBUS SCIM
OPTIONS_SUB=		yes

IBUS_DESC=		Enable IBUS backend for input dialog
IBUS_LIB_DEPENDS=	libibus-1.0.so:textproc/ibus
IBUS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_IBus

SCIM_DESC=		Enable SCIM backend for input dialog
SCIM_LIB_DEPENDS=	libscim-1.0.so:textproc/scim
SCIM_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_SCIM

SDL_DESC=		Enable gamecontroller System Settings module
SDL_USES=		sdl
SDL_USE=		sdl=sdl2
SDL_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_SDL2

X11_RUN_DEPENDS=	xf86-input-libinput>0:x11-drivers/xf86-input-libinput

.include <bsd.port.mk>
