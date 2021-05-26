PORTNAME=	tepl
DISTVERSION=	6.00.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	6
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text editor product line

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-3.0-or-later.txt

LIB_DEPENDS=	libamtk-5.so:x11-toolkits/amtk \
		libicuuc.so:devel/icu \
		libuchardet.so:textproc/uchardet

USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtksourceview4 libxml2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
