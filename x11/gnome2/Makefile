# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2
PORTVERSION=	2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org

RUN_DEPENDS=	battstat-applet-2:${PORTSDIR}/x11/gnomeapplets2 \
		CDDBSlave2:${PORTSDIR}/audio/gnomemedia2 \
	 	archive-generator:${PORTSDIR}/misc/gnomeutils2 \
		eog:${PORTSDIR}/graphics/eog2 \
		gnome-control-center:${PORTSDIR}/sysutils/gnomecontrolcenter2 \
		gconf-editor:${PORTSDIR}/sysutils/gconf-editor \
		gnect:${PORTSDIR}/games/gnomegames2 \
		gedit:${PORTSDIR}/editors/gedit2 \
		gnome-terminal:${PORTSDIR}/x11/gnometerminal \
		gnome-session:${PORTSDIR}/x11/gnomesession \
		metatheme-edit:${PORTSDIR}/misc/metatheme2 \
		metacity:${PORTSDIR}/x11-wm/metacity \
		metacity-setup:${PORTSDIR}/x11-wm/metacity-setup \
		bug-buddy:${PORTSDIR}/devel/bugbuddy2 \
		gnome-system-monitor:${PORTSDIR}/sysutils/gnomesystemmonitor \
		yelp:${PORTSDIR}/x11/yelp \
		gdm:${PORTSDIR}/x11/gdm2 \
		${X11BASE}/share/themes/Metal/gtk-2.0/gtkrc:${PORTSDIR}/x11-toolkits/gtk-engines2 \
		nautilus:${PORTSDIR}/x11-fm/nautilus2 \
		nautilus-gtkhtml-view:${PORTSDIR}/www/nautilus-gtkhtml \
		xscreensaver:${PORTSDIR}/x11/xscreensaver

NO_BUILD=	yes

USE_PYTHON=	yes

GNOME_ONE_DESKTOP=	gnomecore gnomeapplets gnomemedia gnomeutils \
			gnomecontrolcenter gtop libgtop sawfish \
			nautilus glade gedit xalf bugbuddy gnomegames

pre-everything::
	@for package in ${GNOME_ONE_DESKTOP}; do \
		if ${PKG_INFO} | ${GREP} $$package"-[0-9]" >/dev/null 2>&1; then \
		    ${ECHO_MSG} "$$package was detected on the system.  This package is part of the GNOME 1.x"; \
		    ${ECHO_MSG} "desktop, and cannot coexist with the GNOME 2.0 desktop."; \
		    ${ECHO_MSG} ""; \
		    ${ECHO_MSG} "Please deinstall the GNOME 1.x desktop before installing this port."; \
		    ${FALSE}; \
		fi; \
	done

do-install:	# empty

.include <bsd.port.mk>
