PORTNAME=	zenity
PORTVERSION=	3.44.5
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line
WWW=		https://gitlab.gnome.org/GNOME/zenity

LICENSE=	LGPL21+

CONFLICTS_INSTALL=	zenity4-4.*

BUILD_DEPENDS=	itstool:textproc/itstool

USES=		gettext gnome localbase meson pkgconfig \
		perl5 tar:xz xorg
USE_CSTD=	c99
USE_GNOME=	cairo gdkpixbuf gtk30
USE_XORG=	x11
MESON_ARGS=	-Dwebkitgtk=false

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MESON_TRUE=	libnotify

.include <bsd.port.mk>
