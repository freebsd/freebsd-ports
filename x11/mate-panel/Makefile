# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-panel
PORTVERSION=	1.22.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the MATE Desktop

LICENSE=	GPLv2 GFDL LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING-DOCS
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libstartup-notification-1.so:x11/startup-notification

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig \
		tar:xz xorg
USE_MATE=	desktop libmateweather menus
USE_XORG=	ice sm x11 xau xrandr
USE_GNOME=	cairo dconf gnomeprefix gtk30 intltool \
		introspection:build librsvg2 libwnck3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.panel.applet.clock.gschema.xml \
		org.mate.panel.applet.fish.gschema.xml \
		org.mate.panel.applet.notification-area.gschema.xml \
		org.mate.panel.applet.window-list.gschema.xml \
		org.mate.panel.applet.workspace-switcher.gschema.xml \
		org.mate.panel.enums.xml \
		org.mate.panel.gschema.xml \
		org.mate.panel.menubar.gschema.xml \
		org.mate.panel.object.gschema.xml \
		org.mate.panel.toplevel.gschema.xml

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
