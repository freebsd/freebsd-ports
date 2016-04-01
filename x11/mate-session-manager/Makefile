# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-session-manager
PORTVERSION=	1.12.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the MATE desktop

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libupower-glib.so:sysutils/upower
RUN_DEPENDS=	${LOCALBASE}/sbin/console-kit-daemon:sysutils/consolekit \
		${LOCALBASE}/bin/xdpyinfo:x11/xdpyinfo

PORTSCOUT=	limitw:1,even

USES=		execinfo gettext gmake libtool pathfix pkgconfig tar:xz
USE_MATE=	desktop
USE_XORG=	ice sm xau xext xrandr xrender xtrans xtst
USE_GNOME=	gtk20 intlhack librsvg2 libxslt pango
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs \
		--with-gtk=2.0 \
		--enable-upower \
		--with-systemd=no
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.session.gschema.xml

.include <bsd.port.mk>
