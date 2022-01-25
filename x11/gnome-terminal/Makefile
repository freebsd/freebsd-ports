# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	gnome-terminal
DISTVERSION=	3.42.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	9a168cc23962.patch:-p1 # meson 0.61

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME Desktop

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool \
		vala:lang/vala \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2 \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		cpe gettext gnome localbase meson pathfix pkgconfig python:3.7+ \
		tar:xz xorg
USE_GNOME=	cairo dconf gdkpixbuf2 gtk30 intltool vte3
USE_XORG=	x11
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.Terminal.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		NAUTILUS SEARCHPROVIDER
OPTIONS_DEFAULT=	NAUTILUS SEARCHPROVIDER
OPTIONS_SUB=		yes

SEARCHPROVIDER_DESC=		GNOME Shell search provider
SEARCHPROVIDER_MESON_TRUE=	search_provider
SEARCHPROVIDER_BUILD_DEPENDS=	gnome-shell:x11/gnome-shell
SEARCHPROVIDER_RUN_DEPENDS=	gnome-shell:x11/gnome-shell

NAUTILUS_MESON_TRUE=	nautilus_extension
NAUTILUS_USE=		GNOME=nautilus3
NAUTILUS_DESC=		Open in terminal extension for nautilus

.include <bsd.port.mk>
