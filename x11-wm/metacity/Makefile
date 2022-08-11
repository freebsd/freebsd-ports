PORTNAME=	metacity
PORTVERSION=	3.44.0
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window manager for the adult in you

LICENSE=	GPLv2

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.3.0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool \
		zenity>=3.0.0:x11/zenity
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libgtop-2.0.so:devel/libgtop \
		libstartup-notification-1.so:x11/startup-notification
RUN_DEPENDS=	gsettings-desktop-schemas>=3.3.0:devel/gsettings-desktop-schemas \
		zenity>=3.0.0:x11/zenity

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz xorg
GNU_CONFIGURE=	yes
USE_XORG=	x11 xcomposite xcursor xdamage xext xinerama xpresent xrandr \
		xrender xres
USE_GNOME=	gnomeprefix gtk30 intlhack libxml2:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.metacity.enums.xml \
		org.gnome.metacity.gschema.xml \
		org.gnome.metacity.keybindings.gschema.xml \
		org.gnome.metacity.theme.gschema.xml

.include <bsd.port.mk>
