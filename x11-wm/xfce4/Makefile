# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce
PORTVERSION=	4.10
PORTREVISION=	9
CATEGORIES=	x11-wm xfce
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	The "meta-port" for the Xfce Desktop Environment

OPTIONS_DEFINE=	APPFINDER ICONS MIXER MOUSEPAD NOTIFY ORAGE PRINT SLIM SQUEEZE TERMINAL XPM
OPTIONS_DEFAULT=	APPFINDER ICONS MOUSEPAD NOTIFY ORAGE TERMINAL
ORAGE_DESC=	Calendar
MOUSEPAD_DESC=	Text editor
TERMINAL_DESC=	Terminal emulator
APPFINDER_DESC=	Launcher and finder
SQUEEZE_DESC=	Archive manager
XPM_DESC=	Power manager
SLIM_DESC=	SLiM, login manager

RUN_DEPENDS=	xfwm4:${PORTSDIR}/x11-wm/xfce4-wm \
		xfce4-session:${PORTSDIR}/x11-wm/xfce4-session \
		xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel \
		xfdesktop:${PORTSDIR}/x11-wm/xfce4-desktop \
		${LOCALBASE}/lib/gtk-2.0/2.10.0/engines/libxfce.so:${PORTSDIR}/x11-themes/gtk-xfce-engine \
		xfsettingsd:${PORTSDIR}/sysutils/xfce4-settings

NO_BUILD=	yes
LATEST_LINK=	xfce4

NO_MTREE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONS}
RUN_DEPENDS+=	gnome-icon-theme>=3.12.0:${PORTSDIR}/misc/gnome-icon-theme
.endif

.if ${PORT_OPTIONS:MORAGE}
RUN_DEPENDS+=	orage:${PORTSDIR}/deskutils/orage
.endif

.if ${PORT_OPTIONS:MMOUSEPAD}
RUN_DEPENDS+=	mousepad:${PORTSDIR}/editors/mousepad
.endif

.if ${PORT_OPTIONS:MTERMINAL}
RUN_DEPENDS+=	xfce4-terminal:${PORTSDIR}/x11/xfce4-terminal
.endif

.if ${PORT_OPTIONS:MAPPFINDER}
RUN_DEPENDS+=	xfce4-appfinder:${PORTSDIR}/misc/xfce4-appfinder
.endif

.if ${PORT_OPTIONS:MMIXER}
RUN_DEPENDS+=	xfce4-mixer:${PORTSDIR}/audio/xfce4-mixer
.endif

.if ${PORT_OPTIONS:MPRINT}
RUN_DEPENDS+=	xfprint4:${PORTSDIR}/print/xfce4-print
.endif

.if ${PORT_OPTIONS:MSQUEEZE}
RUN_DEPENDS+=   squeeze:${PORTSDIR}/archivers/squeeze
.endif

.if ${PORT_OPTIONS:MNOTIFY}
RUN_DEPENDS+=	xfce4-notifyd-config:${PORTSDIR}/deskutils/xfce4-notifyd
.endif

.if ${PORT_OPTIONS:MXPM}
RUN_DEPENDS+=	xfce4-power-manager:${PORTSDIR}/sysutils/xfce4-power-manager
.endif

.if ${PORT_OPTIONS:MSLIM}
RUN_DEPENDS+=	slim:${PORTSDIR}/x11/slim
.endif

do-install:	# empty

.include <bsd.port.mk>
