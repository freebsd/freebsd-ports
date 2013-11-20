# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-session3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-session
PORTVERSION=	3.6.2
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

INSTALLS_ICONS=	yes
USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_XORG=	ice sm xau xext xtst xrender xtrans xcomposite
USE_GL=		gl
USE_GNOME=	gnomeprefix intlhack gconf2 intltool gtk30
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.SessionManager.gschema.xml

.include <bsd.port.mk>
