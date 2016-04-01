# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce
PORTVERSION=	4.12
PORTREVISION=	1
CATEGORIES=	x11-wm xfce

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	The "meta-port" for the Xfce Desktop Environment

RUN_DEPENDS=	xfwm4:x11-wm/xfce4-wm \
		xfce4-session:x11-wm/xfce4-session \
		xfce4-panel:x11-wm/xfce4-panel \
		xfdesktop:x11-wm/xfce4-desktop \
		xfsettingsd:sysutils/xfce4-settings \
		gtk-xfce-engine>0:x11-themes/gtk-xfce-engine

USES=	metaport

OPTIONS_DEFINE=	APPFINDER ICONS MIXER MOUSEPAD NOTIFY ORAGE PRINT SLIM SQUEEZE TERMINAL XPM
OPTIONS_DEFAULT=	APPFINDER ICONS MOUSEPAD NOTIFY ORAGE TERMINAL
APPFINDER_RUN_DEPENDS=	xfce4-appfinder:misc/xfce4-appfinder
APPFINDER_DESC=	Launcher and finder
ICONS_RUN_DEPENDS=	adwaita-icon-theme>0:x11-themes/adwaita-icon-theme
MIXER_RUN_DEPENDS=	xfce4-mixer:audio/xfce4-mixer
MOUSEPAD_RUN_DEPENDS=	mousepad:editors/mousepad
MOUSEPAD_DESC=	Text editor
NOTIFY_RUN_DEPENDS=	xfce4-notifyd-config:deskutils/xfce4-notifyd
ORAGE_RUN_DEPENDS=	orage:deskutils/orage
ORAGE_DESC=	Calendar
PRINT_RUN_DEPENDS=	xfprint4:print/xfce4-print
SLIM_RUN_DEPENDS=	slim:x11/slim
SLIM_DESC=	SLiM, login manager
SQUEEZE_RUN_DEPENDS=	squeeze:archivers/squeeze
SQUEEZE_DESC=	Archive manager
TERMINAL_RUN_DEPENDS=	xfce4-terminal:x11/xfce4-terminal
TERMINAL_DESC=	Terminal emulator
XPM_RUN_DEPENDS=	xfce4-power-manager:sysutils/xfce4-power-manager
XPM_DESC=	Power manager

do-install:	# empty

.include <bsd.port.mk>
