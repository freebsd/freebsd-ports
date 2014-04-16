# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/gnome-session/Makefile,v 1.187 2010/11/17 12:00:11 kwm Exp $

PORTNAME=	gnome-session
PORTVERSION=	2.32.1
PORTREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 2 desktop

CONFLICTS=	gnome-session-2.31.* gnome-session-2.90.* gnome-session-3.*

BUILD_DEPENDS=	${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libupower-glib.so:${PORTSDIR}/sysutils/upower
RUN_DEPENDS=	${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon \
    		${LOCALBASE}/sbin/console-kit-daemon:${PORTSDIR}/sysutils/consolekit \
		${LOCALBASE}/bin/xdpyinfo:${PORTSDIR}/x11/xdpyinfo

INSTALLS_ICONS=	yes
USES=		gettext gmake pathfix pkgconfig tar:bzip2
USE_XORG=	ice sm xau xrandr
USE_GNOME=	gnomeprefix intlhack gconf2
GNOME_DESKTOP_VERSION=2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnome-session.schemas

.include <bsd.port.mk>
