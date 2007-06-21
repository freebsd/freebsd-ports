# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome2/Makefile,v 1.201 2007/03/14 21:39:30 marcus Exp $
#

PORTNAME=	gnome2
PORTVERSION=	2.18.2
PORTREVISION?=	1
CATEGORIES?=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	The "meta-port" for the GNOME 2 integrated X11 desktop

RUN_DEPENDS?=	${LOCALBASE}/libexec/gweather-applet-2:${PORTSDIR}/x11/gnome-applets \
		gnome-cd:${PORTSDIR}/audio/gnome-media \
	 	gnome-dictionary:${PORTSDIR}/deskutils/gnome-utils \
		eog:${PORTSDIR}/graphics/eog \
		gconf-editor:${PORTSDIR}/sysutils/gconf-editor \
		gnect:${PORTSDIR}/games/gnome-games \
		gedit:${PORTSDIR}/editors/gedit \
		gnome-terminal:${PORTSDIR}/x11/gnome-terminal \
		gnome-session:${PORTSDIR}/x11/gnome-session \
		bug-buddy:${PORTSDIR}/devel/bug-buddy \
		gnome-system-monitor:${PORTSDIR}/sysutils/gnome-system-monitor \
		nautilus:${PORTSDIR}/x11-fm/nautilus \
		${LOCALBASE}/sbin/gdm:${PORTSDIR}/x11/gdm \
		${LOCALBASE}/share/gnome/help/user-guide/C/user-guide.xml:${PORTSDIR}/misc/gnome-user-docs \
		${LOCALBASE}/share/gnome/sounds/question.wav:${PORTSDIR}/audio/gnome-audio \
		${LOCALBASE}/libdata/pkgconfig/libgail-gnome.pc:${PORTSDIR}/x11-toolkits/libgail-gnome \
		file-roller:${PORTSDIR}/archivers/file-roller \
		${LOCALBASE}/share/themes/HighContrast/gtk-2.0/gtkrc:${PORTSDIR}/x11-themes/gnome-themes \
		gok:${PORTSDIR}/accessibility/gok \
		nautilus-cd-burner:${PORTSDIR}/sysutils/nautilus-cd-burner \
		gcalctool:${PORTSDIR}/math/gcalctool \
		gucharmap:${PORTSDIR}/deskutils/gucharmap \
		zenity:${PORTSDIR}/x11/zenity \
		${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		${LOCALBASE}/libexec/gnome-netstatus-applet:${PORTSDIR}/net/gnome-netstatus \
		dasher:${PORTSDIR}/accessibility/dasher \
		evolution-2.10:${PORTSDIR}/mail/evolution \
		${LOCALBASE}/libexec/evolution-webcal:${PORTSDIR}/www/evolution-webcal \
		network-admin:${PORTSDIR}/sysutils/gnome-system-tools \
		gnome-nettool:${PORTSDIR}/net/gnome-nettool \
		vino-session:${PORTSDIR}/net/vino \
		exchange-connector-setup-2.10:${PORTSDIR}/mail/evolution-exchange \
		${LOCALBASE}/lib/gstreamer-0.10/.gstreamer-plugins-core.keep:${PORTSDIR}/multimedia/gstreamer-plugins-core \
		${LOCALBASE}/lib/gstreamer-0.10/libgstgconfelements.so:${PORTSDIR}/devel/gstreamer-plugins-gconf \
		totem:${PORTSDIR}/multimedia/totem \
		gnome-control-center:${PORTSDIR}/sysutils/gnome-control-center \
		${LOCALBASE}/share/gnome/gnome-background-properties/gnome-branded.xml:${PORTSDIR}/x11-themes/gnome-backgrounds \
		sound-juicer:${PORTSDIR}/audio/sound-juicer \
		gnome-keyring-manager:${PORTSDIR}/security/gnome-keyring-manager \
		${LOCALBASE}/libdata/pkgconfig/libgtkhtml-2.0.pc:${PORTSDIR}/www/libgtkhtml \
		evince:${PORTSDIR}/graphics/evince \
		${LOCALBASE}/libexec/fast-user-switch-applet:${PORTSDIR}/x11/fast-user-switch-applet \
		${LOCALBASE}/lib/deskbar-applet/deskbar-applet:${PORTSDIR}/deskutils/deskbar-applet \
		alacarte:${PORTSDIR}/deskutils/alacarte \
		gnome-power-manager:${PORTSDIR}/sysutils/gnome-power-manager \
		gnome-volume-manager:${PORTSDIR}/sysutils/gnome-volume-manager \
		orca:${PORTSDIR}/accessibility/orca \
		gnome-mount:${PORTSDIR}/sysutils/gnome-mount \
		${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon \
		seahorse:${PORTSDIR}/security/seahorse

NO_BUILD=	yes

.if !defined(GNOME_SLAVE)
USE_PYTHON=	yes
.endif

.if !defined(GNOME_SLAVE) || ${.CURDIR:T}=="gnome2-lite"
OPTIONS=	XSCREENSAVER "Use xscreensaver as screen saver app" off
.endif

do-install:	# empty

.include <bsd.port.pre.mk>

.if !defined(GNOME_SLAVE)
.if (${ARCH}!="sparc64" || ${OSVERSION} >= 601101) && ${ARCH}!="ia64"
RUN_DEPENDS+=	yelp:${PORTSDIR}/x11/yelp \
		epiphany:${PORTSDIR}/www/epiphany
.endif
.if ${.CURDIR:T}!="gnome2-lite"
.if ${ARCH} == "i386" && ${OSVERSION} < 700042
RUN_DEPENDS+=	tomboy:${PORTSDIR}/deskutils/tomboy
.endif
.if ${OSVERSION}>=600000
RUN_DEPENDS+=	ekiga:${PORTSDIR}/net/ekiga
.endif
.endif
.endif

.if ${.CURDIR}==${MASTERDIR} || ${.CURDIR:T}=="gnome2-lite"
.if defined(WITH_XSCREENSAVER)
RUN_DEPENDS+=	${LOCALBASE}/share/gnome/applications/gnome-screensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
.else
RUN_DEPENDS+=	gnome-screensaver:${PORTSDIR}/x11/gnome-screensaver
.endif
.endif

.include <bsd.port.post.mk>
