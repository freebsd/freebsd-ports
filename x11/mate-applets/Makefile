# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-applets
PORTVERSION=	1.6.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the MATE Desktop Environment

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libxklavier.so:${PORTSDIR}/x11/libxklavier \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libnotify.so:${PORTSDIR}/devel/libnotify

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build desktop docutils icontheme intlhack \
		libmateweather libmatewnck mucharmap panel \
		polkit settingsdaemon
USE_XORG=	x11
USE_GNOME=	gdkpixbuf2 glib20 gnomehier gtk20 introspection:build \
		libxml2 libxslt pygobject pygtk2
USE_PYTHON=	yes
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-mixer-applet \
		--disable-networkmanager
CONFIGURE_ENV=	OS_SYS="/usr/include"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
PATHFIX_MAKEFILEIN=	Makefile.*

GLIB_SCHEMAS=	org.mate.panel.applet.charpick.gschema.xml \
		org.mate.panel.applet.geyes.gschema.xml \
		org.mate.panel.applet.multiload.gschema.xml \
		org.mate.stickynotes.gschema.xml

FIX_APPLETS=	accessx-status battstat charpick drivemount geyes \
		invest-applet/data multiload stickynotes trashapplet

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CFLAGS+=	-fPIC
PLIST_SUB+=	BATTERY="@comment "
.else
GLIB_SCHEMAS+=	org.mate.panel.applet.battstat.gschema.xml
PLIST_SUB+=	BATTERY=""
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
PLIST_SUB+=	CPUFREQ="@comment "
.else
PLIST_SUB+=	CPUFREQ=""
GLIB_SCHEMAS+=	org.mate.panel.applet.cpufreq.gschema.xml
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.am | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|" == "|" = "|g'
	${MV} ${WRKSRC}/invest-applet/invest/invest-applet.py \
		${WRKSRC}/invest-applet/invest/mate-invest-applet.py
.for dir in ${FIX_APPLETS}
	@${REINPLACE_CMD} -e 's|@LIBEXECDIR@/|@LIBEXECDIR@/mate-|g' \
		${WRKSRC}/${dir}/org.mate.*
.endfor

.include <bsd.port.post.mk>
