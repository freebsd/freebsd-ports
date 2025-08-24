PORTNAME=	metacity
PORTVERSION=	3.57.1
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window manager for GNOME Flashback
WWW=		https://gitlab.gnome.org/GNOME/metacity

LICENSE=	GPLv2

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libharfbuzz.so:print/harfbuzz \
		libgtop-2.0.so:devel/libgtop \
		libstartup-notification-1.so:x11/startup-notification
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		compiler:c11 gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz xorg
GNU_CONFIGURE=	yes
USE_XORG=	sm ice x11 xcomposite xcursor xdamage xext xfixes xinerama \
		xpresent xrandr xrender xres
USE_GNOME=	glib20 gtk30 libxml2:build pango
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	VULKAN
OPTIONS_DEFAULT=	VULKAN
OPTIONS_SUB=	yes

VULKAN_DESC=	Add support for Vulkan (compositor)
VULKAN_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_CONFIGURE_ENABLE=	vulkan

GLIB_SCHEMAS=	org.gnome.metacity.enums.xml \
		org.gnome.metacity.gschema.xml \
		org.gnome.metacity.keybindings.gschema.xml \
		org.gnome.metacity.theme.gschema.xml

.include <bsd.port.mk>
