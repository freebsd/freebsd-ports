# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/x11/gnome-session/Makefile 19534 2014-04-15 20:23:23Z gusi $

PORTNAME=	gnome-session
PORTVERSION=	3.12.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 3 desktop

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libupower-glib.so:${PORTSDIR}/sysutils/upower
RUN_DEPENDS=	${LOCALBASE}/sbin/console-kit-daemon:${PORTSDIR}/sysutils/consolekit \
		${LOCALBASE}/bin/xdpyinfo:${PORTSDIR}/x11/xdpyinfo

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack intltool \
		libxslt:build
USE_XORG=	ice sm xau xext xtst xrender xtrans xcomposite
USE_GL=		gl
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs \
		--enable-gconf=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.SessionManager.gschema.xml

.include <bsd.port.mk>
