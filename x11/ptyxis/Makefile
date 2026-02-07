PORTNAME=	ptyxis
DISTVERSION=	47.13
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal for GNOME with first-class support for containers
WWW=		https://gitlab.gnome.org/chergert/ptyxis

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libportal-gtk4.so:deskutils/libportal-gtk4 \
		libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		cpe desktop-file-utils gettext gnome localbase:ldflags \
		meson pkgconfig tar:xz
USE_GNOME=	dconf gdkpixbuf glib20 gtk40 libadwaita pango vte3

GLIB_SCHEMAS=	org.gnome.Ptyxis.gschema.xml

.include <bsd.port.mk>
