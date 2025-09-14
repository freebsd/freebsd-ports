PORTNAME=	gnome-console
PORTVERSION=	48.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Minimal terminal for GNOME
WWW=		https://apps.gnome.org/Console/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^48\.

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
		libpcre2-8.so:devel/pcre2

USES=		compiler:c11 desktop-file-utils gettext-tools gnome localbase \
		meson pkgconfig tar:xz
USE_CSTD=	c11
USE_GNOME=	glib20 gtk40 libadwaita pango vte3
GLIB_SCHEMAS=	org.gnome.Console.gschema.xml

.include <bsd.port.mk>
