PORTNAME=	plasma-desktop
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 plasma desktop
WWW=		https://www.kde.org/plasma-desktop

# TODO: update packagekit-qt5
#LIB_DEPENDS=    libpackagekit-qt.so:ports-mgmt/packagekit-qt5
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util \
		libxkbfile.so:x11/libxkbfile \
		libwayland-client.so:graphics/wayland
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		xf86-input-evdev>0:x11-drivers/xf86-input-evdev \
		xf86-input-libinput>0:x11-drivers/xf86-input-libinput \
		xdg-user-dir:devel/xdg-user-dirs \
		setxkbmap:x11/setxkbmap
BUILD_DEPENDS=	xf86-input-evdev>0:x11-drivers/xf86-input-evdev \
		xf86-input-synaptics>0:x11-drivers/xf86-input-synaptics \
		xf86-input-libinput>0:x11-drivers/xf86-input-libinput \
		xdg-user-dir:devel/xdg-user-dirs \
		wayland-protocols>=1.18:graphics/wayland-protocols

USES=		cmake compiler:c++11-lib cpe desktop-file-utils gettext gnome \
		kde:5 pkgconfig python:run qt:5 shebangfix tar:xz xorg
USE_GNOME=	glib20
USE_KDE=	activities activities-stats archive attica auth baloo \
		bookmarks codecs completion config configwidgets coreaddons \
		crash dbusaddons emoticons filemetadata globalaccel guiaddons \
		i18n iconthemes init itemmodels itemviews jobwidgets kcmutils \
		kdeclarative kdelibs4support kio libksysguard newstuff \
		notifications notifyconfig package parts people \
		plasma-framework plasma-workspace runner service solid sonnet \
		textwidgets unitconversion wallet widgetsaddons windowsystem \
		xmlgui \
		doctools:build ecm:build \
		drkonqi:run infocenter:run kde-cli-tools:run kmenuedit:run \
		ksysguard:run polkit-kde-agent-1:run systemsettings:run
USE_QT=		concurrent core dbus declarative gui network phonon4 \
		printsupport sql svg wayland widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xcb xcursor xext xfixes xft xi xrender

CPE_VENDOR=	kde

CMAKE_ON=	WANT_SYNAPTICS

SHEBANG_FILES=	kcms/ksmserver/kconf_update/*.py \
		kcms/keyboard/*.py

OPTIONS_SUB=	yes

OPTIONS_DEFINE=		ACCOUNTS
OPTIONS_DEFAULT=	ACCOUNTS
OPTIONS_GROUP=		IM
OPTIONS_GROUP_IM=	IBUS SCIM
IM_DESC=		Input Method Support

IBUS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_IBus
IBUS_LIB_DEPENDS=	libibus-1.0.so:textproc/ibus
IBUS_DESC=		Enable IBUS backend for input dialog
SCIM_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_SCIM
SCIM_LIB_DEPENDS=	libscim-1.0.so:textproc/scim
SCIM_DESC=		Enable SCIM backend for input dialog
ACCOUNTS_LIB_DEPENDS=	libkaccounts.so:net-im/kaccounts-integration \
			libaccounts-qt5.so:net-im/libaccounts-qt5
ACCOUNTS_USE=		gnome=intltool
ACCOUNTS_DESC=		Accounts management library support

post-patch:
# Set the correct iso-codes directory
	${REINPLACE_CMD} -e '/isoCodesXmlDir/ s#/usr/share#${LOCALBASE}/share#g' \
		${PATCH_WRKSRC}/kcms/keyboard/iso_codes.h

.include <bsd.port.mk>
