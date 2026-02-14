PORTNAME=	tepl
DISTVERSION=	6.14.0
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	6
DISTNAME=	libgedit-${PORTNAME}-${DISTVERSIONFULL}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text editor product line
WWW=		https://gitlab.gnome.org/World/gedit/libgedit-tepl

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-3.0-or-later.txt

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgedit-amtk-5.so:x11-toolkits/amtk \
		libgedit-gfls-1.so:filesystems/libgedit-gfls \
		libgedit-gtksourceview-300.so:x11-toolkits/libgedit-gtksourceview \
		libicuuc.so:devel/icu \
		libhandy-1.so:x11-toolkits/libhandy

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:bz2
USE_GNOME=	glib20 gtk30 introspection:build
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/gedit
GL_PROJECT=	libgedit-tepl

MESON_ARGS=	-Dgtk_doc=false

.include <bsd.port.mk>
