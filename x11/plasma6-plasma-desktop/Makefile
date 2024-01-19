PORTNAME=	plasma-desktop
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-plasma

COMMENT=	KDE Plasma Desktop
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols \
		xf86-input-evdev>0:x11-drivers/xf86-input-evdev \
		xf86-input-libinput>0:x11-drivers/xf86-input-libinput \
		xf86-input-synaptics>0:x11-drivers/xf86-input-synaptics
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libicuuc.so:devel/icu \
		liboauth2plugin.so:sysutils/signon-plugin-oauth2@qt6 \
		libwayland-client.so:graphics/wayland \
		libxcb-util.so:x11/xcb-util \
		libxkbcommon.so:x11/libxkbcommon \
		libxkbfile.so:x11/libxkbfile
RUN_DEPENDS=	noto-emoji>0:x11-fonts/noto-emoji \
		xdg-user-dir:devel/xdg-user-dirs \
		xf86-input-evdev>0:x11-drivers/xf86-input-evdev \
		xf86-input-libinput>0:x11-drivers/xf86-input-libinput \
		xf86-input-synaptics>0:x11-drivers/xf86-input-synaptics

USES=		cmake gettext gl kde:6 pkgconfig python qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	activities activities-stats attica5 auth baloo5 bookmarks \
		codecs colorscheme completion config configwidgets coreaddons \
		crash dbusaddons doctools filemetadata globalaccel guiaddons \
		i18n iconthemes itemmodels itemviews jobwidgets kcmutils kio \
		libksysguard libplasma newstuff notifications notifyconfig \
		package plasma-workspace plasma5support runner service solid \
		sonnet svg widgetsaddons windowsystem xmlgui \
		ecm:build \
		kirigami-addons:run kirigami2:run kpipewire:run \
		qqc2-desktop-style:run
USE_QT=		5compat base declarative svg
USE_XORG=	x11 xcb xcursor xext xfixes xi xrender

#SHEBANG_FILES=	kcms/keyboard/*.py kcms/ksmserver/kconf_update/*.py

.include <bsd.port.mk>
