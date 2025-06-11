PORTNAME=	libgnomekbd
PORTVERSION=	3.28.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	2ed57e84.patch:-p1
PATCHFILES+=	7887700a.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Keyboard management library
WWW=		https://gitlab.gnome.org/GNOME/libgnomekbd

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libxklavier.so:x11/libxklavier

USES=		gettext gnome localbase pkgconfig meson \
		tar:xz xorg
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 introspection:build
USE_XORG=	x11
USE_LDCONFIG=	yes

MESON_ARGS=	-Dtests=false \
		-Dvapi=false # vapi files are not generated

GLIB_SCHEMAS=	org.gnome.libgnomekbd.desktop.gschema.xml \
		org.gnome.libgnomekbd.gschema.xml \
		org.gnome.libgnomekbd.keyboard.gschema.xml

post-extract:
	@${MV} ${WRKSRC}/libgnomekbd/gkbd-keyboard-display.desktop.in.in \
		${WRKSRC}/libgnomekbd/gkbd-keyboard-display.desktop.in

post-patch:
	${MV} ${WRKSRC}/data/icons/hicolor/scalable/apps/org.notanapp.KeyboardLayout.Devel.svg \
		${WRKSRC}/data/icons/hicolor/scalable/apps/org.gnome.KeyboardLayout.Devel.svg
	${MV} ${WRKSRC}/data/icons/hicolor/scalable/apps/org.notanapp.KeyboardLayout.svg \
		${WRKSRC}/data/icons/hicolor/scalable/apps/org.gnome.KeyboardLayout.svg
	${MV} ${WRKSRC}/data/icons/hicolor/symbolic/apps/org.notanapp.KeyboardLayout-symbolic.svg \
		${WRKSRC}/data/icons/hicolor/symbolic/apps/org.gnome.KeyboardLayout-symbolic.svg

.include <bsd.port.mk>
