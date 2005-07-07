# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2
PORTVERSION=	2.10.2
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for the GNOME 2 integrated X11 desktop

RUN_DEPENDS=	${X11BASE}/libexec/gweather-applet-2:${PORTSDIR}/x11/gnomeapplets2 \
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
		${X11BASE}/share/gnome/applications/gnome-screensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome \
		${X11BASE}/share/gnome/help/user-guide/C/user-guide.xml:${PORTSDIR}/misc/gnomeuserdocs2 \
		${X11BASE}/share/gnome/sounds/question.wav:${PORTSDIR}/audio/gnomeaudio2 \
		${X11BASE}/libdata/pkgconfig/libgail-gnome.pc:${PORTSDIR}/x11-toolkits/libgail-gnome \
		file-roller:${PORTSDIR}/archivers/fileroller \
		${X11BASE}/share/themes/HighContrast/gtk-2.0/gtkrc:${PORTSDIR}/x11-themes/gnome-themes \
		ggv:${PORTSDIR}/print/ggv \
		gok:${PORTSDIR}/accessibility/gok \
		gpdf:${PORTSDIR}/graphics/gpdf \
		nautilus-cd-burner:${PORTSDIR}/sysutils/nautilus-cd-burner \
		gcalctool:${PORTSDIR}/math/gcalctool \
		gucharmap:${PORTSDIR}/deskutils/gucharmap \
		zenity:${PORTSDIR}/x11/zenity \
		${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		gnopernicus:${PORTSDIR}/accessibility/gnopernicus \
		${X11BASE}/libexec/gnome-netstatus-applet:${PORTSDIR}/net/gnomenetstatus \
		dasher:${PORTSDIR}/accessibility/dasher \
		evolution-2.2:${PORTSDIR}/mail/evolution \
		${X11BASE}/libexec/evolution-webcal:${PORTSDIR}/www/evolution-webcal \
		network-admin:${PORTSDIR}/sysutils/gnomesystemtools \
		gnome-nettool:${PORTSDIR}/net/gnomenettool \
		vino-session:${PORTSDIR}/net/vino \
		ximian-connector-setup-2.2:${PORTSDIR}/mail/ximian-connector \
		${X11BASE}/lib/gstreamer-0.8/.gstreamer-plugins-core.keep:${PORTSDIR}/multimedia/gstreamer-plugins-core \
		totem:${PORTSDIR}/multimedia/totem-gstreamer \
		gnome-control-center:${PORTSDIR}/sysutils/gnomecontrolcenter2 \
		${X11BASE}/share/gnome/gnome-background-properties/gnome-branded.xml:${PORTSDIR}/x11-themes/gnome-backgrounds \
		sound-juicer:${PORTSDIR}/audio/sound-juicer \
		${X11BASE}/libdata/pkgconfig/libgtkhtml-2.0.pc:${PORTSDIR}/www/libgtkhtml

NO_BUILD=	yes

USE_PYTHON=	yes

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
pre-configure:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

do-install:	# empty

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${OSVERSION} > 500035
RUN_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
.endif

.include <bsd.port.post.mk>
