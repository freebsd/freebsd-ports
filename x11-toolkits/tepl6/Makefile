PORTNAME=	tepl
DISTVERSION=	6.4.0
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	6
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text editor product line
WWW=		https://wiki.gnome.org/Projects/Tepl

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-3.0-or-later.txt

BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
LIB_DEPENDS=	libamtk-5.so:x11-toolkits/amtk \
		libicuuc.so:devel/icu \
		libuchardet.so:textproc/uchardet

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtksourceview4 libxml2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
