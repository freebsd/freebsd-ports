# New ports collection makefile for:	gnome2-lite
# Date created:		30 November 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-lite
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" of the GNOME desktop slimmed down for FreeBSD releases

RUN_DEPENDS=	${X11BASE}/libexec/cdplayer_applet2:${PORTSDIR}/x11/gnomeapplets2 \
		gnome-cd:${PORTSDIR}/audio/gnomemedia2 \
	 	gnome-dictionary:${PORTSDIR}/deskutils/gnomeutils2 \
		eog:${PORTSDIR}/graphics/eog2 \
		gnome-control-center:${PORTSDIR}/sysutils/gnomecontrolcenter2 \
		gedit:${PORTSDIR}/editors/gedit2 \
		gnome-terminal:${PORTSDIR}/x11/gnometerminal \
		gnome-session:${PORTSDIR}/x11/gnomesession \
		gnome-system-monitor:${PORTSDIR}/sysutils/gnomesystemmonitor \
		nautilus:${PORTSDIR}/x11-fm/nautilus2 \
		yelp:${PORTSDIR}/x11/yelp \
		screensaver-properties-capplet:${PORTSDIR}/x11/xscreensaver-gnome \
		${X11BASE}/share/gnome/help/user-guide/C/user-guide.xml:${PORTSDIR}/misc/gnomeuserdocs2 \
		${X11BASE}/share/gnome/sounds/question.wav:${PORTSDIR}/audio/gnomeaudio2 \
		file-roller:${PORTSDIR}/archivers/fileroller \
		${X11BASE}/share/themes/HighContrast/gtk-2.0/gtkrc:${PORTSDIR}/x11-toolkits/gnome-themes \
		ggv:${PORTSDIR}/print/ggv2 \
		gcalctool:${PORTSDIR}/math/gcalctool \
		gucharmap:${PORTSDIR}/deskutils/gucharmap \
		gst-thumbnail:${PORTSDIR}/multimedia/nautilus-media \
		${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera

NO_BUILD=	yes

USE_PYTHON=	yes

CONFLICTS=	gnome2-[0-9]*

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
pre-configure:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

do-install:	# empty

.include <bsd.port.pre.mk>

.if ${ARCH} != "amd64" && ( ${ARCH} == "i386" || ${OSVERSION} > 500035 )
RUN_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
.endif

.include <bsd.port.post.mk>
