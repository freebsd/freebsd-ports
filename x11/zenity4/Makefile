PORTNAME=	zenity
PORTVERSION=	4.2.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	4
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display GTK4 dialogs from the command line
WWW=		https://gitlab.gnome.org/GNOME/zenity

LICENSE=	LGPL21+

BUILD_DEPENDS=	itstool:textproc/itstool \
		help2man:misc/help2man

USES=		gettext-tools gnome localbase meson pkgconfig \
		perl5 tar:xz xorg
USE_CSTD=	c99
USE_GNOME=	gtk40 libadwaita
USE_XORG=	x11
MESON_ARGS=	-Dwebkitgtk=false

CONFLICTS_INSTALL=	zenity-3.*

.include <bsd.port.mk>
