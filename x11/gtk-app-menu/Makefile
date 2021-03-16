# $FreeBSD$

PORTNAME=	appmenu-gtk-module
DISTVERSION=	0.7.6
CATEGORIES=	x11

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	GTK module for putting application menubar in a global menubar

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/subprojects/appmenu-gtk-module/LICENSE

LIB_DEPENDS=	libbamf3.so:sysutils/bamf
BUILD_DEPENDS=	valac:lang/vala

USES=	meson gnome pkgconfig

MESON_ARGS=	-Dvalapanel=disabled -Dxfce=disabled -Dmate=disabled -Dbudgie=disabled -Djayatana=disabled -Dregistrar=disabled -Dappmenu-gtk-module=enabled

USE_GNOME=	gtk30 glib20 gtk20 gdkpixbuf2
GLIB_SCHEMAS=	org.appmenu.gtk-module.gschema.xml

USE_GITLAB=	yes
GL_ACCOUNT=	vala-panel-project
GL_PROJECT=	vala-panel-appmenu
GL_COMMIT=	4e362c22ab3a23c98f13fb379c782786ee057cf6

.include <bsd.port.mk>
