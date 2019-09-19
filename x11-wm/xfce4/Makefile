# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce
PORTVERSION=	4.14
CATEGORIES=	x11-wm xfce

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	meta-port for the Xfce Desktop Environment

RUN_DEPENDS=	xfwm4:x11-wm/xfce4-wm \
		xfce4-session:x11-wm/xfce4-session \
		xfce4-panel:x11-wm/xfce4-panel \
		xfdesktop:x11-wm/xfce4-desktop \
		xfsettingsd:sysutils/xfce4-settings

USES=	metaport

OPTIONS_DEFINE=		APPFINDER GREYBIRD GTK2ENGINE ICONS LIGHTDM MOUSEPAD NOTIFY ORAGE PRINT SQUEEZE \
			TERMINAL XPM
OPTIONS_DEFAULT=	APPFINDER GREYBIRD ICONS MOUSEPAD NOTIFY TERMINAL
APPFINDER_RUN_DEPENDS=	xfce4-appfinder:misc/xfce4-appfinder
APPFINDER_DESC=		Launcher and finder
GREYBIRD_DESC=		Install Greybird theme
GREYBIRD_RUN_DEPENDS=	greybird-theme>0:x11-themes/greybird-theme
GTK2ENGINE_DESC=	Install old gtk2 only engine theme
GTK2ENGINE_RUN_DEPENDS=	gtk-xfce-engine>0:x11-themes/gtk-xfce-engine
ICONS_RUN_DEPENDS=	adwaita-icon-theme>0:x11-themes/adwaita-icon-theme
LIGHTDM_RUN_DEPENDS=	lightdm-gtk-greeter:x11/lightdm-gtk-greeter
LIGHTDM_DESC=		LightDM display manger
MOUSEPAD_RUN_DEPENDS=	mousepad:editors/mousepad
MOUSEPAD_DESC=		Text editor
NOTIFY_RUN_DEPENDS=	xfce4-notifyd-config:deskutils/xfce4-notifyd
ORAGE_RUN_DEPENDS=	orage:deskutils/orage
ORAGE_DESC=		Calendar
PRINT_RUN_DEPENDS=	xfprint4:print/xfce4-print
SQUEEZE_RUN_DEPENDS=	squeeze:archivers/squeeze
SQUEEZE_DESC=		Archive manager
TERMINAL_RUN_DEPENDS=	xfce4-terminal:x11/xfce4-terminal
TERMINAL_DESC=		Terminal emulator
XPM_RUN_DEPENDS=	xfce4-power-manager:sysutils/xfce4-power-manager
XPM_DESC=		Power manager

do-install:	# empty

.include <bsd.port.mk>
