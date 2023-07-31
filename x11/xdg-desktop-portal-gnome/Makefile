PORTNAME=	xdg-desktop-portal-gnome
DISTVERSION=	43.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Backend implementation for xdg-desktop-portal for GNOME
WWW=		https://gitlab.gnome.org/GNOME/xdg-desktop-portal-gnome

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal \
		xdg-desktop-portal-gtk>0:x11/xdg-desktop-portal-gtk
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libgnome-desktop-4.so:x11/gnome-desktop
RUN_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal \
		xdg-desktop-portal-gtk>0:x11/xdg-desktop-portal-gtk

USES=		gettext-tools gnome meson pkgconfig tar:xz xorg

USE_XORG=	x11
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk40 libadwaita
GLIB_SCHEMAS=	xdg-desktop-portal-gnome.gschema.xml

PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
