# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2
PORTVERSION=	2.0
PORTREVISION=	6
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org

RUN_DEPENDS=	${X11BASE}/libexec/cdplayer_applet2:${PORTSDIR}/x11/gnomeapplets2 \
		gnome-cd:${PORTSDIR}/audio/gnomemedia2 \
	 	archive-generator:${PORTSDIR}/misc/gnomeutils2 \
		eog:${PORTSDIR}/graphics/eog2 \
		gnome-control-center:${PORTSDIR}/sysutils/gnomecontrolcenter2 \
		gconf-editor:${PORTSDIR}/sysutils/gconf-editor \
		gnect:${PORTSDIR}/games/gnomegames2 \
		gedit:${PORTSDIR}/editors/gedit2 \
		gnome-terminal:${PORTSDIR}/x11/gnometerminal \
		gnome-session:${PORTSDIR}/x11/gnomesession \
		glade-2:${PORTSDIR}/devel/glade2 \
		metatheme-edit:${PORTSDIR}/misc/metatheme2 \
		metacity:${PORTSDIR}/x11-wm/metacity \
		sawfish:${PORTSDIR}/x11-wm/sawfish2 \
		metacity-setup:${PORTSDIR}/x11-wm/metacity-setup \
		bug-buddy:${PORTSDIR}/devel/bugbuddy2 \
		gnome-system-monitor:${PORTSDIR}/sysutils/gnomesystemmonitor \
		yelp:${PORTSDIR}/x11/yelp \
		gdm:${PORTSDIR}/x11/gdm2 \
		${X11BASE}/share/themes/Metal/gtk-2.0/gtkrc:${PORTSDIR}/x11-toolkits/gtk-engines2 \
		nautilus-gtkhtml-view:${PORTSDIR}/www/nautilus-gtkhtml \
		screensaver-properties-capplet:${PORTSDIR}/x11/xscreensaver-gnome \
		${X11BASE}/share/gnome/help/user-guide/C/user-guide.xml:${PORTSDIR}/misc/gnomeuserdocs2 \
		${X11BASE}/share/gnome/sounds/login.wav:${PORTSDIR}/audio/gnomeaudio \
		gnome-pkgview:${PORTSDIR}/sysutils/gnome-pkgview

NO_BUILD=	yes

USE_PYTHON=	yes

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
pre-build:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

do-install:	# empty

.include <bsd.port.mk>
