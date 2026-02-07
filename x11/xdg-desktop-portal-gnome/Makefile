PORTNAME=	xdg-desktop-portal-gnome
DISTVERSION=	47.3
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Backend implementation for xdg-desktop-portal for GNOME
WWW=		https://gitlab.gnome.org/GNOME/xdg-desktop-portal-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libgraphene-1.0.so:graphics/graphene \
		libwayland-client.so:graphics/wayland
RUN_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal

USES=		gettext-tools gnome meson pkgconfig tar:xz xorg

USE_XORG=	x11
USE_GNOME=	cairo gdkpixbuf gnomedesktop4 glib20 gtk40 libadwaita
GLIB_SCHEMAS=	xdg-desktop-portal-gnome.gschema.xml

MESON_ARGS=	-Dsystemd=disabled \
		-Dsystemduserunitdir=no

PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|SystemdService|#SystemdService|' \
		${WRKSRC}/data/org.freedesktop.impl.portal.desktop.gnome.service.in

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
