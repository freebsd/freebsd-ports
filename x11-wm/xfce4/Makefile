# New ports collection makefile for:	xfce4
# Date created:		9 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce
PORTVERSION=	4.0.3.1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	The "meta-port" for the XFce 4 desktop environment

RUN_DEPENDS=	${X11BASE}/lib/xfce4/mcs-plugins/ui_plugin.so:${PORTSDIR}/sysutils/xfce4-mcs-plugins \
		xfwm4:${PORTSDIR}/x11-wm/xfce4-wm \
		xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel \
		xfdesktop:${PORTSDIR}/x11-wm/xfce4-desktop \
		startxfce4:${PORTSDIR}/sysutils/xfce4-utils \
		xffm:${PORTSDIR}/x11-fm/xfce4-fm \
		xfprint4:${PORTSDIR}/print/xfce4-print \
		xfce4-iconbox:${PORTSDIR}/misc/xfce4-iconbox \
		${X11BASE}/lib/gtk-2.0/2.2.0/engines/libxfce.so:${PORTSDIR}/x11-toolkits/gtk-xfce-engine

.if !defined(WITHOUT_EXTRAS)
.if !defined(WITHOUT_THEMES)
RUN_DEPENDS+=	${X11BASE}/share/xfce4/themes/BeOS/terminal.png:${PORTSDIR}/misc/xfce4-panel-themes \
		${X11BASE}/share/xffm/pixmaps/xfce/mime.xml:${PORTSDIR}/x11-fm/xfce4-fm-icons \
		${X11BASE}/share/xfwm4/themes/atlanta2/themerc:${PORTSDIR}/misc/xfce4-wm-themes
.endif

.if !defined(WITHOUT_PLUGINS)
RUN_DEPENDS+=	${X11BASE}/lib/xfce4/panel-plugins/libmixer.so:${PORTSDIR}/audio/xfce4-mixer \
		${X11BASE}/lib/xfce4/panel-plugins/libsystray.so:${PORTSDIR}/x11-wm/xfce4-systray \
		xfce4-tips:${PORTSDIR}/games/xfce4-toys
.endif
.endif

LATEST_LINK=	xfce4
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
