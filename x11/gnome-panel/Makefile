PORTNAME=	gnome-panel
PORTVERSION=	3.56.0
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel for the GNOME Flashback session
WWW=		https://gitlab.gnome.org/GNOME/gnome-panel

LICENSE_COMB=	multi
LICENSE=	GPLv2 LGPL21

BUILD_DEPENDS=	gdm>0:x11/gdm \
		itstool>0:textproc/itstool
LIB_DEPENDS=	libgweather-4.so:net/libgweather4 \
		libgeocode-glib-2.so:net/geocode-glib2 \
		libsoup-3.0.so:devel/libsoup3 \
		libjson-glib-1.0.so:devel/json-glib \
		libical.so:devel/libical \
		libical-glib.so:devel/libical \
		libicalss.so:devel/libical \
		libicalvcal.so:devel/libical \
		libconsolekit.so:sysutils/consolekit2 \
		libpolkit-gobject-1.so:sysutils/polkit \
		libgdm.so:x11/gdm

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz xorg
GNU_CONFIGURE=	yes
USE_GNOME=	cairo dconf evolutiondataserver3 gdkpixbuf glib20 \
		gnomedesktop3 gnomemenus3 gtk30 libwnck3 pango libxml2
USE_XORG=	x11 xext xi xrandr

CONFIGURE_ARGS=	--disable-documentation \
		--disable-gtk-doc-html \
		--without-html-dir

INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gnome-panel.applet.clock.gschema.xml \
		org.gnome.gnome-panel.applet.fish.gschema.xml \
		org.gnome.gnome-panel.applet.initial-settings.gschema.xml \
		org.gnome.gnome-panel.applet.window-list.gschema.xml \
		org.gnome.gnome-panel.applet.workspace-switcher.gschema.xml \
		org.gnome.gnome-panel.applet.menu-button.gschema.xml \
		org.gnome.gnome-panel.applet.launcher.gschema.xml \
		org.gnome.gnome-panel.gschema.xml \
		org.gnome.gnome-panel.enums.xml \
		org.gnome.gnome-panel.object.gschema.xml \
		org.gnome.gnome-panel.toplevel.gschema.xml

post-extract:
	${CP} ${FILESDIR}/gp-consolekit-manager-gen.* \
		${WRKSRC}/modules/menu/
	${CP} ${FILESDIR}/org.freedesktop.ConsoleKit.Manager.xml \
		${WRKSRC}/modules/menu/

.include <bsd.port.mk>
