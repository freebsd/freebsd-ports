PORTNAME=	appmenu-gtk-module
DISTVERSION=	0.7.6
PORTREVISION=	2
CATEGORIES=	x11

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	442bcebcc00e.patch:-p1 # meson >= 0.60

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	GTK module for putting application menubar in a global menubar

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/subprojects/appmenu-gtk-module/LICENSE

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libbamf3.so:sysutils/bamf

USES=	meson gnome pkgconfig

MESON_ARGS=	-Dappmenu-gtk-module=enabled \
		-Dbudgie=disabled \
		-Djayatana=disabled \
		-Dmate=disabled \
		-Dregistrar=disabled \
		-Dxfce=disabled \
		-Dvalapanel=disabled

USE_GITLAB=	yes
GL_ACCOUNT=	vala-panel-project
GL_PROJECT=	vala-panel-appmenu
GL_COMMIT=	4e362c22ab3a23c98f13fb379c782786ee057cf6

USE_GNOME=	gtk30 glib20 gtk20 gdkpixbuf2
GLIB_SCHEMAS=	org.appmenu.gtk-module.gschema.xml

USE_LDCONFIG=	yes
.include <bsd.port.mk>
