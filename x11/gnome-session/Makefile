# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-session
PORTVERSION=	3.18.1.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 3 desktop

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libjson-glib-1.0.so:devel/json-glib \
		libupower-glib.so:sysutils/upower
RUN_DEPENDS=	${LOCALBASE}/sbin/console-kit-daemon:sysutils/consolekit \
		${LOCALBASE}/bin/xdpyinfo:x11/xdpyinfo

PORTSCOUT=	limitw:1,even

USES=		execinfo gettext gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gtk30 intlhack intlhack libxslt:build
USE_XORG=	ice sm xau xext xtst xrender xtrans xcomposite
USE_GL=		gl
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs \
		--enable-consolekit \
		--enable-gconf=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.SessionManager.gschema.xml

.include <bsd.port.mk>
