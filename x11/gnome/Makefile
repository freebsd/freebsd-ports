PORTNAME=	gnome
PORTVERSION=	47
CATEGORIES?=	x11 gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Metaport for the GNOME desktop
WWW=		https://www.gnome.org/

FLAVORS=	full lite
FLAVOR?=	full

RUN_DEPENDS=	gdm>0:x11/gdm \
		gnome-shell>=47.0:x11/gnome-shell \
		xdg-desktop-portal-gnome>=47.0:x11/xdg-desktop-portal-gnome \
		xdg-user-dirs-gtk>0:x11/xdg-user-dirs-gtk \
		gnome-keyring>0:security/gnome-keyring \
		orca>0:accessibility/orca \
		sushi>0:x11-fm/sushi \
		nautilus>0:x11-fm/nautilus \
		gnome-console>0:x11/gnome-console \
		zenity>0:x11/zenity \
		adwaita-icon-theme>0:x11-themes/adwaita-icon-theme \
		cantarell-fonts>0:x11-fonts/cantarell-fonts \
		source-code-pro-ttf>0:x11-fonts/source-code-pro-ttf

USES=		metaport

.if ${FLAVOR} ==lite
PKGNAMESUFFIX=	-lite
COMMENT=	The "meta-port" of the GNOME desktop slimmed down for only the basics
DESCR=		${.CURDIR}/pkg-descr-lite
.endif

.if ${FLAVOR} == "full"
RUN_DEPENDS+=	epiphany>0:www/epiphany \
		gucharmap>0:deskutils/gucharmap \
		gnome-characters>0:deskutils/gnome-characters \
		gnome-calendar>0:deskutils/gnome-calendar \
		gnome-clocks>0:deskutils/gnome-clocks \
		gnome-font-viewer>0:deskutils/gnome-font-viewer \
		gnome-maps>0:deskutils/gnome-maps \
		gnome-weather>0:deskutils/gnome-weather \
		gnome-tweaks>0:deskutils/gnome-tweaks \
		eog>0:graphics/eog \
		gnome-text-editor>0:editors/gnome-text-editor \
		gnome-calculator>0:math/gnome-calculator \
		file-roller>0:archivers/file-roller \
		gnome-user-docs>0:misc/gnome-user-docs \
		yelp>0:x11/yelp \
		totem>0:multimedia/totem \
		evolution>0:mail/evolution \
		geary>0:mail/geary \
		gnome-shell-extensions>0:x11/gnome-shell-extensions

.endif

.include <bsd.port.mk>
