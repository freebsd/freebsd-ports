# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome3
PORTVERSION=	3.18.0
CATEGORIES?=	x11 gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	"meta-port" for the GNOME 3 integrated X11 desktop

RUN_DEPENDS?=	dconf-editor:devel/dconf-editor \
		gnome-session>=3.0.0:x11/gnome-session \
		gnome-themes-standard>=3.0.0:x11-themes/gnome-themes-standard \
		gnome-icon-theme-extras>=3.0.0:misc/gnome-icon-theme-extras \
		gnome-icon-theme-symbolic>=3.0.0:x11-themes/gnome-icon-theme-symbolic \
		gnome-keyring>=3.0.0:security/gnome-keyring \
		gnome-power-manager>=3.0.0:sysutils/gnome-power-manager \
		orca>=3.0.0:accessibility/orca \
		gnome-mount:sysutils/gnome-mount \
		gnome-shell>=3.0.0:x11/gnome-shell \
		gnome-shell-extensions>=3.0.0:x11/gnome-shell-extensions \
		gnome-tweak-tool:deskutils/gnome-tweak-tool \
		sushi>=0:x11-fm/sushi \
		nautilus>=3.0.0:x11-fm/nautilus \
		${LOCALBASE}/share/fonts/bitstream-vera/Vera.ttf:x11-fonts/bitstream-vera \
		${LOCALBASE}/share/hal/fdi/information/10freedesktop/10-camera-ptp.fdi:sysutils/hal-info \
		yelp>=3.0.0:x11/yelp \
		zenity>=3.0.0:x11/zenity \
		seahorse>=3.0.0:security/seahorse \
		gnome-control-center>=3.0.0:sysutils/gnome-control-center \
		${LOCALBASE}/share/gnome-background-properties/gnome-backgrounds.xml:x11-themes/gnome-backgrounds \
		caribou>=0:accessibility/caribou \
		${LOCALBASE}/share/sounds/freedesktop/index.theme:audio/freedesktop-sound-theme \
		ekiga:net-im/ekiga

CONFLICTS?=	gnome3-lite-[0-9]*

USES=		metaport

.if ${.CURDIR:T}!="gnome3-lite"
OPTIONS_DEFINE+=MAPI DOCS
MAPI_DESC=	Depend on evolution-mapi (pulls in samba4)

DOCS_RUN_DEPENDS=	gnome-user-docs>=0:misc/gnome-user-docs
MAPI_RUN_DEPENDS=	evolution-mapi>=3.0.0:mail/evolution-mapi
.endif

.include <bsd.port.options.mk>

.if ${.CURDIR:T}!="gnome3-lite"
RUN_DEPENDS+=	empathy>=3.0.0:net-im/empathy \
		epiphany>=3.0.0:www/epiphany \
		gucharmap>=3.0.0:deskutils/gucharmap \
		gnome-characters>=3.0.0:deskutils/gnome-characters \
		gnome-calendar>=3.0:deskutils/gnome-calendar \
		eog>=3.0.0:graphics/eog \
		eog-plugins>=3.0.0:graphics/eog-plugins \
		gedit>=3.0.0:editors/gedit \
		gedit-plugins>=3.0.0:editors/gedit-plugins \
		gnome-terminal>=3.0.0:x11/gnome-terminal \
		mousetweaks>=3.0.0:accessibility/mousetweaks \
		brasero>=3.0.0:sysutils/brasero \
		accerciser>=3.0.0:accessibility/accerciser \
		gnome-calculator>=3.0.0:math/gnome-calculator \
		gnome-utils>=3.6.0:deskutils/gnome-utils \
		file-roller>=3.0.0:archivers/file-roller \
		evince>=3.0.0:graphics/evince \
		vino>=3.0.0:net/vino \
		vinagre>=3.0.0:net/vinagre \
		gnome-games>=3.0.0:games/gnome-games \
		totem>=3.0.0:multimedia/totem \
		gconf-editor>=3.0.0:sysutils/gconf-editor \
		gdm>=3.0.0:x11/gdm \
		gnome-color-manager>=0:graphics/gnome-color-manager \
		evolution>=3.0.0:mail/evolution \
		cheese>=3.0.0:multimedia/cheese

.endif # !gnome3-lite section

.include <bsd.port.mk>
