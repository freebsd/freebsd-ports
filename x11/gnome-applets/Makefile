# New ports collection makefile for:	gnomeapplets2
# Date created:				26th May 2000
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-applets/Makefile,v 1.211 2010/03/28 17:55:31 marcus Exp $
#

PORTNAME=	gnome-applets
PORTVERSION=	2.30.0
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the GNOME 2 Desktop Environment

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/system-tools-backends-2.0.pc:${PORTSDIR}/sysutils/system-tools-backends \
		${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon
LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		gweather.1:${PORTSDIR}/net/libgweather \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit \
		xklavier.12:${PORTSDIR}/x11/libxklavier \
		gucharmap.7:${PORTSDIR}/deskutils/gucharmap
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/system-tools-backends-2.0.pc:${PORTSDIR}/sysutils/system-tools-backends \
		${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomepanel gnomedocutils \
		libgnomekbd
WANT_GNOME=	yes
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gstreamer=0.10 \
		--enable-mixer-applet \
		--disable-networkmanager
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		OS_SYS="/usr/include"

GCONF_SCHEMAS=	charpick.schemas drivemount.schemas geyes.schemas \
		mixer.schemas multiload.schemas stickynotes.schemas

OPTIONS=	MINI_COMMANDER "Enable mini-commander applet" off

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/libnotify.pc) || \
	!defined(WITHOUT_LIBNOTIFY)
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC"
PLIST_SUB=	BATTERY="@comment "
.else
GCONF_SCHEMAS+=	battstat.schemas
PLIST_SUB=	BATTERY=""
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
PLIST_SUB+=	CPUFREQ="@comment "
.else
PLIST_SUB+=	CPUFREQ=""
GCONF_SCHEMAS+=	cpufreq-applet.schemas
.endif

.if defined(WITH_MINI_COMMANDER)
CONFIGURE_ARGS+=	--enable-mini-commander
GCONF_SCHEMAS+=	mini-commander-global.schemas mini-commander.schemas
PLIST_SUB+=	COMMANDER=""
.else
PLIST_SUB+=	COMMANDER="@comment "
.endif

.if ( exists(${pygnomedesktop_DETECT}) ) || \
	( ( ${HAVE_GNOME:Mpygnomedesktop}!="" ) && ${ARCH}!="sparc64" )
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygnomedesktop
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|" == "|" = "|g'
.if !defined(USE_PYTHON)
	@${REINPLACE_CMD} -e 's|HAVE_PYGTK="yes"|HAVE_PYGTK="no"|' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
