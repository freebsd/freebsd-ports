PORTNAME=	gnome-applets
PORTVERSION=	3.56.0
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small programs for the GNOME panel
WWW=		https://gitlab.gnome.org/GNOME/gnome-applets

LICENSE=	GPLv2

BUILD_DEPENDS=	adwaita-icon-theme>=46.0:x11-themes/adwaita-icon-theme \
		xorgproto>0:x11/xorgproto \
		itstool>0:textproc/itstool
LIB_DEPENDS=	libgnome-panel.so:x11/gnome-panel \
		libgtop-2.0.so:devel/libgtop \
		libnotify.so:devel/libnotify \
		libupower-glib.so:sysutils/upower \
		libgweather-4.so:net/libgweather4 \
		libgucharmap_2_90.so:deskutils/gucharmap \
		libpcre2-8.so:devel/pcre2 \
		libpolkit-gobject-1.so:sysutils/polkit
RUN_DEPENDS=	adwaita-icon-theme>=46.0:x11-themes/adwaita-icon-theme

USES=		gettext gmake gnome iconv libtool pkgconfig tar:xz xorg
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libwnck3 libxml2 pango
USE_XORG=	ice sm x11
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-cpufreq \
		--enable-frequency-selector=no

OPTIONS_DEFINE=	TRACKER
OPTIONS_DEFAULT=	TRACKER

TRACKER_DESC=	Install search applet
TRACKER_LIB_DEPENDS=	libtinysparql-3.0.so:devel/tinysparql
TRACKER_CONFIGURE_ENABLE=	tracker-search-bar

GLIB_SCHEMAS=	org.gnome.gnome-applets.battstat.gschema.xml \
		org.gnome.gnome-applets.charpick.gschema.xml \
		org.gnome.gnome-applets.command.gschema.xml \
		org.gnome.gnome-applets.enums.xml \
		org.gnome.gnome-applets.geyes.gschema.xml \
		org.gnome.gnome-applets.gweather.gschema.xml \
		org.gnome.gnome-applets.mini-commander.gschema.xml \
		org.gnome.gnome-applets.stickynotes.gschema.xml \
		org.gnome.gnome-applets.timer.gschema.xml \
		org.gnome.gnome-applets.window-buttons.gschema.xml \
		org.gnome.gnome-applets.window-picker-applet.gschema.xml \
		org.gnome.gnome-applets.window-title.gschema.xml

.include <bsd.port.mk>
