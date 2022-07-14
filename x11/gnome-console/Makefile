PORTNAME=	gnome-console
PORTVERSION=	42.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Minimal terminal for GNOME

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool>0:textproc/itstool \
		sassc>0:textproc/sassc
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libgtop-2.0.so:devel/libgtop \
		libhandy-1.so:x11-toolkits/libhandy \
		libicudata.so:devel/icu \
		libpcre2-8.so:devel/pcre2 \
		libvte-2.91.so:x11-toolkits/vte3

USES=		compiler:c11 desktop-file-utils gettext gnome localbase meson \
		pkgconfig tar:xz
USE_CSTD=	c11
USE_GNOME=	gtk30 gtksourceview5 libadwaita
GLIB_SCHEMAS=	org.gnome.Console.gschema.xml

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
