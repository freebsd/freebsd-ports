# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome3
PORTVERSION=	3.36
PORTREVISION=	3
CATEGORIES?=	x11 gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"meta-port" for the GNOME 3 integrated X11 desktop

FLAVORS=	full lite
FLAVOR?=	full

RUN_DEPENDS?=	dconf-editor:devel/dconf-editor \
		gdm>=3.0.0:x11/gdm \
		gnome-session>=3.0.0:x11/gnome-session \
		gnome-themes-extra>=3.28:x11-themes/gnome-themes-extra \
		gnome-icon-theme-extras>=3.0.0:misc/gnome-icon-theme-extras \
		gnome-icon-theme-symbolic>=3.0.0:x11-themes/gnome-icon-theme-symbolic \
		gnome-keyring>=3.0.0:security/gnome-keyring \
		gnome-power-manager>=3.0.0:sysutils/gnome-power-manager \
		orca>=3.0.0:accessibility/orca \
		gnome-shell>=3.0.0:x11/gnome-shell \
		gnome-shell-extensions>=3.0.0:x11/gnome-shell-extensions \
		gnome-tweaks:deskutils/gnome-tweaks \
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
		${LOCALBASE}/share/sounds/freedesktop/index.theme:audio/freedesktop-sound-theme

OPTIONS_DEFINE=	DOCS

USES=		metaport

.if ${FLAVOR} ==lite
OPTIONS_EXCLUDE=	DOCS
PKGNAMESUFFIX=	-lite
COMMENT=	The "meta-port" of the GNOME desktop slimmed down for only the basics
PKGMESSAGE=	${.CURDIR}/pkg-message-lite
DESCR=		${.CURDIR}/pkg-descr-lite
.endif

.if ${FLAVOR} == "full"
RUN_DEPENDS+=	epiphany>=3.0.0:www/epiphany \
		gucharmap>=3.0.0:deskutils/gucharmap \
		gnome-characters>=3.0.0:deskutils/gnome-characters \
		gnome-calendar>=3.0:deskutils/gnome-calendar \
		eog>=3.0.0:graphics/eog \
		eog-plugins>=3.0.0:graphics/eog-plugins \
		gedit>=3.0.0:editors/gedit \
		gedit-plugins>=3.0.0:editors/gedit-plugins \
		gnome-terminal>=3.0.0:x11/gnome-terminal \
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
		gnome-color-manager>=0:graphics/gnome-color-manager \
		evolution>=3.0.0:mail/evolution \
		cheese>=3.0.0:multimedia/cheese

.endif # !gnome3-lite section

DOCS_RUN_DEPENDS=	gnome-user-docs>=0:misc/gnome-user-docs \
			gnome-getting-started-docs>=0:misc/gnome-getting-started-docs


.include <bsd.port.mk>
