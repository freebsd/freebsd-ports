# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for the GNOME 2 integrated X11 desktop

RUN_DEPENDS=	${X11BASE}/libexec/cdplayer_applet2:${PORTSDIR}/x11/gnomeapplets2 \
		gnome-cd:${PORTSDIR}/audio/gnomemedia2 \
	 	gnome-calculator:${PORTSDIR}/deskutils/gnomeutils2 \
		eog:${PORTSDIR}/graphics/eog2 \
		gnome-control-center:${PORTSDIR}/sysutils/gnomecontrolcenter2 \
		gconf-editor:${PORTSDIR}/sysutils/gconf-editor \
		gnect:${PORTSDIR}/games/gnomegames2 \
		gedit:${PORTSDIR}/editors/gedit2 \
		gnome-terminal:${PORTSDIR}/x11/gnometerminal \
		gnome-session:${PORTSDIR}/x11/gnomesession \
		metacity-setup:${PORTSDIR}/x11-wm/metacity-setup \
		bug-buddy:${PORTSDIR}/devel/bugbuddy2 \
		gnome-system-monitor:${PORTSDIR}/sysutils/gnomesystemmonitor \
		nautilus:${PORTSDIR}/x11-fm/nautilus2 \
		yelp:${PORTSDIR}/x11/yelp \
		gdm:${PORTSDIR}/x11/gdm2 \
		screensaver-properties-capplet:${PORTSDIR}/x11/xscreensaver-gnome \
		${X11BASE}/share/gnome/help/user-guide/C/user-guide.xml:${PORTSDIR}/misc/gnomeuserdocs2 \
		${X11BASE}/share/gnome/sounds/question.wav:${PORTSDIR}/audio/gnomeaudio2 \
		${X11BASE}/libdata/pkgconfig/libgail-gnome.pc:${PORTSDIR}/x11-toolkits/libgail-gnome \
		${X11BASE}/libdata/pkgconfig/vte.pc:${PORTSDIR}/x11-toolkits/vte \
		${X11BASE}/libdata/pkgconfig/libzvt-2.0.pc:${PORTSDIR}/x11-toolkits/libzvt \
		file-roller:${PORTSDIR}/archivers/fileroller \
		${X11BASE}/share/themes/HighContrast/gtk-2.0/gtkrc:${PORTSDIR}/x11-toolkits/gnome-themes \
		ggv:${PORTSDIR}/print/ggv2 \
		gnome-pkgview:${PORTSDIR}/sysutils/gnome-pkgview \
		acme:${PORTSDIR}/multimedia/acme \
		gst-thumbnail:${PORTSDIR}/multimedia/nautilus-media \
		${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera

NO_BUILD=	yes

USE_PYTHON=	yes

.if !defined(PACKAGE_BUILDING)
pre-configure:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

do-install:	# empty

.include <bsd.port.mk>
