# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for the GNOME 2 integrated X11 desktop

RUN_DEPENDS=	${X11BASE}/libexec/cdplayer_applet2:${PORTSDIR}/x11/gnomeapplets2 \
		gnome-cd:${PORTSDIR}/audio/gnomemedia2 \
	 	gnome-dictionary:${PORTSDIR}/deskutils/gnomeutils2 \
		eog:${PORTSDIR}/graphics/eog2 \
		gnome-control-center:${PORTSDIR}/sysutils/gnomecontrolcenter2 \
		gconf-editor:${PORTSDIR}/sysutils/gconf-editor \
		gnect:${PORTSDIR}/games/gnomegames2 \
		gedit:${PORTSDIR}/editors/gedit2 \
		gnome-terminal:${PORTSDIR}/x11/gnometerminal \
		gnome-session:${PORTSDIR}/x11/gnomesession \
		bug-buddy:${PORTSDIR}/devel/bugbuddy2 \
		gnome-system-monitor:${PORTSDIR}/sysutils/gnomesystemmonitor \
		nautilus:${PORTSDIR}/x11-fm/nautilus2 \
		yelp:${PORTSDIR}/x11/yelp \
		gdm:${PORTSDIR}/x11/gdm2 \
		screensaver-properties-capplet:${PORTSDIR}/x11/xscreensaver-gnome \
		${X11BASE}/share/gnome/help/user-guide/C/user-guide.xml:${PORTSDIR}/misc/gnomeuserdocs2 \
		${X11BASE}/share/gnome/sounds/question.wav:${PORTSDIR}/audio/gnomeaudio2 \
		${X11BASE}/libdata/pkgconfig/libgail-gnome.pc:${PORTSDIR}/x11-toolkits/libgail-gnome \
		file-roller:${PORTSDIR}/archivers/fileroller \
		${X11BASE}/share/themes/HighContrast/gtk-2.0/gtkrc:${PORTSDIR}/x11-toolkits/gnome-themes \
		ggv:${PORTSDIR}/print/ggv2 \
		acme:${PORTSDIR}/multimedia/acme \
		gok:${PORTSDIR}/accessibility/gok \
		gpdf:${PORTSDIR}/graphics/gpdf \
		nautilus-cd-burner:${PORTSDIR}/sysutils/nautilus-cd-burner \
		gcalctool:${PORTSDIR}/math/gcalctool \
		gucharmap:${PORTSDIR}/deskutils/gucharmap \
		zenity:${PORTSDIR}/x11/zenity \
		gst-thumbnail:${PORTSDIR}/multimedia/nautilus-media \
		${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		gnopernicus:${PORTSDIR}/accessibility/gnopernicus

NO_BUILD=	yes

USE_PYTHON=	yes

CONFLICTS=	gnome2-lite*

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
pre-configure:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

do-install:	# empty

.include <bsd.port.pre.mk>

.if ${ARCH} != "amd64" && ( ${ARCH} == "i386" || ${OSVERSION} > 500035 )
RUN_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
.endif

.if ${ARCH} == "i386"
RUN_DEPENDS+=	gnomemeeting:${PORTSDIR}/net/gnomemeeting
.endif

.include <bsd.port.post.mk>
