# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-terminal
PORTVERSION=	3.38.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 3 Desktop

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool \
		vala:lang/vala \
		xsltproc:textproc/libxslt \
		docbook-xsl>0:textproc/docbook-xsl
LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libgnutls.so:security/gnutls \
		libfribidi.so:converters/fribidi \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		cpe gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz xorg
USE_GNOME=	cairo dconf gdkpixbuf2 gtk30 intltool vte3
USE_XORG=	x11
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.Terminal.gschema.xml

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		SEARCHPROVIDER NAUTILUS
OPTIONS_DEFAULT=	SEARCHPROVIDER NAUTILUS

SEARCHPROVIDER_DESC=	Gnome-shell search provider
SEARCHPROVIDER_CONFIGURE_ENABLE=	search-provider
SEARCHPROVIDER_BUILD_DEPENDS=	gnome-shell:x11/gnome-shell
SEARCHPROVIDER_RUN_DEPENDS=	gnome-shell:x11/gnome-shell

NAUTILUS_CONFIGURE_WITH=	nautilus-extension
NAUTILUS_USE=		GNOME=nautilus3
NAUTILUS_DESC=		Open in terminal extension for nautilus

.include <bsd.port.mk>
