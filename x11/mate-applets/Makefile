# $FreeBSD$

PORTNAME=	mate-applets
PORTVERSION=	1.20.2
PORTREVISION=	2
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the MATE Desktop Environment

LICENSE=	GPLv2 GFDL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING-DOCS

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libupower-glib.so:sysutils/upower \
		libgucharmap_2_90.so:deskutils/gucharmap \
		libnotify.so:devel/libnotify

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gmake libtool localbase pkgconfig \
		python:2.7 tar:xz
USE_CSTD=	c11

USE_MATE=	libmateweather panel
USE_XORG=	ice sm x11
USE_GNOME=	cairo gtk30 gtksourceview3 intltool libwnck3 libxml2 \
		pygobject3
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	OS_SYS="/usr/include"
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.panel.applet.charpick.gschema.xml \
		org.mate.panel.applet.command.gschema.xml \
		org.mate.panel.applet.geyes.gschema.xml \
		org.mate.panel.applet.multiload.gschema.xml \
		org.mate.panel.applet.netspeed.gschema.xml \
		org.mate.panel.applet.timer.gschema.xml \
		org.mate.stickynotes.gschema.xml

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CONFIGURE_ARGS+=--disable-battstat
CFLAGS+=	-fPIC
PLIST_SUB+=	BATTERY="@comment "
.else
#CONFIGURE_ARGS+=--enable-battstat
GLIB_SCHEMAS+=	org.mate.panel.applet.battstat.gschema.xml
PLIST_SUB+=	BATTERY=""
.endif

# requires linux libcpufreq library
#.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CONFIGURE_ARGS+=--disable-cpufreq
PLIST_SUB+=	CPUFREQ="@comment "
#.else
#CONFIGURE_ARGS+=--enable-cpufreq
#PLIST_SUB+=	CPUFREQ=""
#GLIB_SCHEMAS+=	org.mate.panel.applet.cpufreq.gschema.xml
#.endif

.include <bsd.port.post.mk>
