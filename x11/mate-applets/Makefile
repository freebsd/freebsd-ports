# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-applets
PORTVERSION=	1.8.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the MATE Desktop Environment

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libxklavier.so:${PORTSDIR}/x11/libxklavier \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	gucharmap:${PORTSDIR}/deskutils/gucharmap

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig python tar:xz
USE_MATE=	desktop icontheme libmateweather panel polkit settingsdaemon
USE_XORG=	x11
USE_GNOME=	gdkpixbuf2 gnomehier gtksourceview2 introspection:build \
		libxml2 libxslt pygobject pygobject3 libwnck intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-networkmanager
CONFIGURE_ENV=	OS_SYS="/usr/include"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.panel.applet.charpick.gschema.xml \
		org.mate.panel.applet.command.gschema.xml \
		org.mate.panel.applet.geyes.gschema.xml \
		org.mate.panel.applet.multiload.gschema.xml \
		org.mate.panel.applet.timer.gschema.xml \
		org.mate.stickynotes.gschema.xml

FIX_APPLETS=	accessx-status battstat charpick drivemount geyes \
		invest-applet/data multiload stickynotes trashapplet

.include <bsd.port.pre.mk>

#.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CONFIGURE_ARGS+=--disable-battstat
CFLAGS+=	-fPIC
PLIST_SUB+=	BATTERY="@comment "
#.else
#CONFIGURE_ARGS+=--enable-battstat
#GLIB_SCHEMAS+=	org.mate.panel.applet.battstat.gschema.xml
#PLIST_SUB+=	BATTERY=""
#.endif

#.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CONFIGURE_ARGS+=--disable-cpufreq
PLIST_SUB+=	CPUFREQ="@comment "
#.else
#CONFIGURE_ARGS+=--enable-cpufreq
#PLIST_SUB+=	CPUFREQ=""
#GLIB_SCHEMAS+=	org.mate.panel.applet.cpufreq.gschema.xml
#.endif

post-patch:
	${MV} ${WRKSRC}/invest-applet/invest/invest-applet.py \
		${WRKSRC}/invest-applet/invest/mate-invest-applet.py
.for dir in ${FIX_APPLETS}
	@${REINPLACE_CMD} -e 's|@LIBEXECDIR@/|@LIBEXECDIR@/mate-|g' \
		${WRKSRC}/${dir}/org.mate.*
.endfor

.include <bsd.port.post.mk>
