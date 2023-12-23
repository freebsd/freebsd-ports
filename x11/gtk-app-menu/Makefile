PORTNAME=	appmenu-gtk-module
DISTVERSION=	0.7.6
PORTREVISION=	4
CATEGORIES=	x11

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	442bcebcc00e.patch:-p1 # meson >= 0.60

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	GTK module for putting application menubar in a global menubar
WWW=		https://gitlab.com/vala-panel-project/vala-panel-appmenu/-/tree/master/subprojects/appmenu-gtk-module

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/subprojects/appmenu-gtk-module/LICENSE

LIB_DEPENDS=	libbamf3.so:sysutils/bamf

USES=	meson gnome pkgconfig vala:build

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
GL_TAGNAME=	4e362c22ab3a23c98f13fb379c782786ee057cf6

USE_GNOME=	gtk30 glib20 gtk20 gdkpixbuf2
GLIB_SCHEMAS=	org.appmenu.gtk-module.gschema.xml

USE_LDCONFIG=	yes
.include <bsd.port.mk>
