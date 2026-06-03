PORTNAME=	xdg-user-dirs-gtk
PORTVERSION=	0.16
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk+ integration of special directories
WWW=		https://gitlab.gnome.org/GNOME/xdg-user-dirs-gtk

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xdg-user-dir:devel/xdg-user-dirs

USES=		gettext-tools gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 gtk30

.include <bsd.port.mk>
