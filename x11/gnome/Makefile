# New ports collection makefile for:	gnome
# Date created:		17 Aug 1998
# Whom:			Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnome
PORTVERSION=	1.4.1b2
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org

RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter \
		another_clock_applet:${PORTSDIR}/x11/gnomeapplets \
		gtcd:${PORTSDIR}/audio/gnomemedia \
		${X11BASE}/share/gnome/help/glossary/C/index.html:${PORTSDIR}/misc/gnomeuserdocs \
	 	gcalc:${PORTSDIR}/misc/gnomeutils \
		gnomecard:${PORTSDIR}/deskutils/gnomepim \
		gnomine:${PORTSDIR}/games/gnomegames \
		sawfish:${PORTSDIR}/x11-wm/sawfish \
		ggv:${PORTSDIR}/print/ggv \
		ghex:${PORTSDIR}/editors/ghex \
		bug-buddy:${PORTSDIR}/devel/bugbuddy \
		glade:${PORTSDIR}/devel/glade \
		gtop:${PORTSDIR}/sysutils/gtop \
		gdm:${PORTSDIR}/x11/gdm \
		xalf:${PORTSDIR}/x11/xalf \
		${X11BASE}/share/themes/Metal/ICON.png:${PORTSDIR}/x11-toolkits/gtk-engines \
		${PYTHON_SITELIBDIR}/gtk-1.2/_appletmodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		gnomeg:${PORTSDIR}/x11-toolkits/guile-gnome \
		${X11BASE}/etc/panelmmConf.sh:${PORTSDIR}/x11-toolkits/panel-- \
		nautilus:${PORTSDIR}/x11-fm/nautilus \
		screensaver-properties-capplet:${PORTSDIR}/x11/xscreensaver-gnome

NO_BUILD=	yes

USE_PYTHON=	yes

do-install:	# empty

.include <bsd.port.mk>
