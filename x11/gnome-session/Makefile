# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/gnome-session/Makefile,v 1.187 2010/11/17 12:00:11 kwm Exp $

PORTNAME=	gnome-session
PORTVERSION=	2.32.1
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 2 desktop

CONFLICTS=	gnome-session-2.31.* gnome-session-2.90.* gnome-session-3.*

BUILD_DEPENDS=	${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring \
		notify.4:${PORTSDIR}/devel/libnotify \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		upower-glib.1:${PORTSDIR}/sysutils/upower
RUN_DEPENDS=	${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon \
    		${LOCALBASE}/sbin/console-kit-daemon:${PORTSDIR}/sysutils/consolekit \
		${LOCALBASE}/bin/xdpyinfo:${PORTSDIR}/x11/xdpyinfo

INSTALLS_ICONS=	yes
USES=		gettext gmake pkgconfig
USE_BZIP2=	yes
USE_XORG=	ice sm xau xrandr
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2
GNOME_DESKTOP_VERSION=2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gnome-session.1 gnome-wm.1 gnome-session-properties.1 \
		gnome-session-save.1
GCONF_SCHEMAS=	gnome-session.schemas

NO_STAGE=	yes
.include <bsd.port.mk>
