PORTNAME=	tecla
PORTVERSION=	47.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Keyboard layout viewer for the GNOME desktop
WWW=		https://gitlab.gnome.org/GNOME/tecla

LICENSE=	GPLv2+

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libwayland-client.so:graphics/wayland

USES=		gettext gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 gtk40 libadwaita

.include <bsd.port.mk>
