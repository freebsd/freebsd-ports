# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome2/Makefile,v 1.142 2006/04/23 20:10:22 marcus Exp $
#

PORTNAME=	gnome2
PORTVERSION=	2.14.1
PORTREVISION?=	0
CATEGORIES?=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	The "meta-port" for the GNOME 2 integrated X11 desktop

RUN_DEPENDS?=	${X11BASE}/libexec/gweather-applet-2:${PORTSDIR}/x11/gnomeapplets2 \
		gnome-cd:${PORTSDIR}/audio/gnomemedia2 \
	 	gnome-dictionary:${PORTSDIR}/deskutils/gnomeutils2 \
		eog:${PORTSDIR}/graphics/eog \
		gconf-editor:${PORTSDIR}/sysutils/gconf-editor \
		gnect:${PORTSDIR}/games/gnomegames2 \
		gedit:${PORTSDIR}/editors/gedit \
		gnome-terminal:${PORTSDIR}/x11/gnometerminal \
		gnome-session:${PORTSDIR}/x11/gnomesession \
		bug-buddy:${PORTSDIR}/devel/bugbuddy \
		gnome-system-monitor:${PORTSDIR}/sysutils/gnomesystemmonitor \
		nautilus:${PORTSDIR}/x11-fm/nautilus2 \
		yelp:${PORTSDIR}/x11/yelp \
		${X11BASE}/sbin/gdm:${PORTSDIR}/x11/gdm \
		${X11BASE}/share/gnome/help/user-guide/C/user-guide.xml:${PORTSDIR}/misc/gnomeuserdocs2 \
		${X11BASE}/share/gnome/sounds/question.wav:${PORTSDIR}/audio/gnomeaudio2 \
		${X11BASE}/libdata/pkgconfig/libgail-gnome.pc:${PORTSDIR}/x11-toolkits/libgail-gnome \
		file-roller:${PORTSDIR}/archivers/fileroller \
		${X11BASE}/share/themes/HighContrast/gtk-2.0/gtkrc:${PORTSDIR}/x11-themes/gnome-themes \
		gok:${PORTSDIR}/accessibility/gok \
		nautilus-cd-burner:${PORTSDIR}/sysutils/nautilus-cd-burner \
		gcalctool:${PORTSDIR}/math/gcalctool \
		gucharmap:${PORTSDIR}/deskutils/gucharmap \
		zenity:${PORTSDIR}/x11/zenity \
		${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		gnopernicus:${PORTSDIR}/accessibility/gnopernicus \
		${X11BASE}/libexec/gnome-netstatus-applet:${PORTSDIR}/net/gnomenetstatus \
		dasher:${PORTSDIR}/accessibility/dasher \
		evolution-2.6:${PORTSDIR}/mail/evolution \
		${X11BASE}/libexec/evolution-webcal:${PORTSDIR}/www/evolution-webcal \
		network-admin:${PORTSDIR}/sysutils/gnomesystemtools \
		gnome-nettool:${PORTSDIR}/net/gnomenettool \
		vino-session:${PORTSDIR}/net/vino \
		ximian-connector-setup-2.6:${PORTSDIR}/mail/evolution-exchange \
		${X11BASE}/lib/gstreamer-0.10/.gstreamer-plugins-core.keep:${PORTSDIR}/multimedia/gstreamer-plugins-core \
		${X11BASE}/lib/gstreamer-0.10/libgstgconfelements.so:${PORTSDIR}/devel/gstreamer-plugins-gconf \
		totem:${PORTSDIR}/multimedia/totem-gstreamer \
		gnome-control-center:${PORTSDIR}/sysutils/gnomecontrolcenter2 \
		${X11BASE}/share/gnome/gnome-background-properties/gnome-branded.xml:${PORTSDIR}/x11-themes/gnome-backgrounds \
		sound-juicer:${PORTSDIR}/audio/sound-juicer \
		gnome-keyring-manager:${PORTSDIR}/security/gnomekeyringmanager \
		${X11BASE}/libdata/pkgconfig/libgtkhtml-2.0.pc:${PORTSDIR}/www/libgtkhtml \
		evince:${PORTSDIR}/graphics/evince \
		${X11BASE}/libexec/fast-user-switch-applet:${PORTSDIR}/x11/fast-user-switch-applet \
		${X11BASE}/lib/deskbar-applet/deskbar-applet:${PORTSDIR}/deskutils/deskbar-applet

NO_BUILD=	yes

.if !defined(GNOME_SLAVE)
USE_PYTHON=	yes
.endif

.if !defined(BATCH) && !defined(PACKAGE_BUILDING) && !defined(GNOME_SLAVE)
pre-configure:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

.if !defined(GNOME_SLAVE) || ${.CURDIR:T}=="gnome2-lite"
OPTIONS=	XSCREENSAVER "Use xscreensaver as screen saver app" off
.endif

do-install:	# empty

.include <bsd.port.pre.mk>

.if !defined(GNOME_SLAVE)
.if ${ARCH} == "i386" || ${OSVERSION} > 500035
RUN_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
.endif
.if ${.CURDIR:T}!="gnome2-lite"
.if ${ARCH}!="sparc64" || ${OSVERSION} >= 700003
RUN_DEPENDS+=	ekiga:${PORTSDIR}/net/ekiga
.endif
.endif
.endif

.if ${.CURDIR}==${MASTERDIR} || ${.CURDIR:T}=="gnome2-lite"
.if defined(WITH_XSCREENSAVER)
RUN_DEPENDS+=	${X11BASE}/share/gnome/applications/gnome-screensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
.else
RUN_DEPENDS+=	gnome-screensaver:${PORTSDIR}/x11/gnome-screensaver
.endif
.endif

.include <bsd.port.post.mk>
