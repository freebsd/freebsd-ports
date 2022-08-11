PORTNAME=	xfce
PORTVERSION=	4.16
CATEGORIES=	x11-wm xfce

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Meta-port for the Xfce Desktop Environment

RUN_DEPENDS=	xfwm4:x11-wm/xfce4-wm \
		xfce4-session:x11-wm/xfce4-session \
		xfce4-panel:x11-wm/xfce4-panel \
		xfdesktop:x11-wm/xfce4-desktop \
		xfsettingsd:sysutils/xfce4-settings

USES=	metaport

OPTIONS_DEFINE=		APPFINDER GREYBIRD ICONS LIGHTDM MOUSEPAD NOTIFY \
			TERMINAL XPM
OPTIONS_DEFAULT=	APPFINDER GREYBIRD ICONS MOUSEPAD NOTIFY TERMINAL \
			XPM
APPFINDER_RUN_DEPENDS=	xfce4-appfinder:misc/xfce4-appfinder
APPFINDER_DESC=		Launcher and finder
GREYBIRD_DESC=		Install Greybird theme
GREYBIRD_RUN_DEPENDS=	greybird-theme>0:x11-themes/greybird-theme
ICONS_RUN_DEPENDS=	adwaita-icon-theme>0:x11-themes/adwaita-icon-theme
LIGHTDM_RUN_DEPENDS=	lightdm-gtk-greeter:x11/lightdm-gtk-greeter
LIGHTDM_DESC=		LightDM display manger
MOUSEPAD_RUN_DEPENDS=	mousepad:editors/mousepad
MOUSEPAD_DESC=		Text editor
NOTIFY_RUN_DEPENDS=	xfce4-notifyd-config:deskutils/xfce4-notifyd
TERMINAL_RUN_DEPENDS=	xfce4-terminal:x11/xfce4-terminal
TERMINAL_DESC=		Terminal emulator
XPM_RUN_DEPENDS=	xfce4-power-manager:sysutils/xfce4-power-manager
XPM_DESC=		Power manager

do-install:	# empty

.include <bsd.port.mk>
