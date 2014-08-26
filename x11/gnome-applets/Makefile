# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/gnome-applets/Makefile,v 1.219 2011/04/10 19:41:38 mezz Exp $

PORTNAME=	gnome-applets
PORTVERSION=	2.32.1.1
PORTREVISION=	6
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the GNOME 2 Desktop Environment

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/system-tools-backends-2.0.pc:${PORTSDIR}/sysutils/system-tools-backends \
		${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libgweather.so:${PORTSDIR}/net/libgweather \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libxklavier.so:${PORTSDIR}/x11/libxklavier \
		libgucharmap.so:${PORTSDIR}/deskutils/gucharmap
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/system-tools-backends-2.0.pc:${PORTSDIR}/sysutils/system-tools-backends \
		${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon

INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix gettext gmake pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack gnomepanel gnomedocutils libgnomekbd
WANT_GNOME=	yes
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mixer-applet \
		--disable-networkmanager
CONFIGURE_ENV=	OS_SYS="/usr/include"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

GCONF_SCHEMAS=	charpick.schemas drivemount.schemas geyes.schemas \
		mixer.schemas multiload.schemas stickynotes.schemas

OPTIONS_DEFINE=	MINI_COMMANDER NOTIFY PYTHON
MINI_COMMANDER_DESC=	Mini-commander applet

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/libnotify.pc) || \
	${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
.endif

.if ${PORT_OPTIONS:MMINI_COMMANDER}
CONFIGURE_ARGS+=	--enable-mini-commander
GCONF_SCHEMAS+=	mini-commander-global.schemas mini-commander.schemas
PLIST_SUB+=	COMMANDER="" OLDCOMMANDER="@comment "
.else
PLIST_SUB+=	COMMANDER="@comment " OLDCOMMANDER=""
.endif

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME 	 
WITH_GNOME=	yes 	 
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
USE_GNOME+=	pygnomedesktop
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ENV+=	ac_cv_path_PYTHON=none
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${PORT_OPTIONS:MPYTHON}
IGNORE=		Python bindings for gnomedesktop are unsupported on ${ARCH}"
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
PLIST_SUB+=	BATTERY="@comment "
.else
GCONF_SCHEMAS+=	battstat.schemas
PLIST_SUB+=	BATTERY=""
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
PLIST_SUB+=	CPUFREQ="@comment "
.else
PLIST_SUB+=	CPUFREQ=""
GCONF_SCHEMAS+= cpufreq-applet.schemas
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|" == "|" = "|g'
	@${REINPLACE_CMD} '/^geyes_applet2_LDADD =/s/=/= -lm/' \
		${WRKSRC}/geyes/Makefile.in
	@${REINPLACE_CMD} '/^stickynotes_applet_LDADD =/s/=/= $$(X_LIBS)/' \
		${WRKSRC}/stickynotes/Makefile.in
	@${REINPLACE_CMD} '/^trashapplet_LDADD =/s/=/= $$(X_LIBS)/' \
		${WRKSRC}/trashapplet/src/Makefile.in
.if !defined(USE_PYTHON)
	@${REINPLACE_CMD} -e 's|HAVE_PYGTK="yes"|HAVE_PYGTK="no"|' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
