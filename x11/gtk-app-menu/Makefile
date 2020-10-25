# $FreeBSD$

PORTNAME=	appmenu-gtk-module
DISTVERSION=	0.7.3.2
CATEGORIES=	x11

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	GTK module for putting application menubar in a global menubar

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/subprojects/appmenu-gtk-module/LICENSE

USES=	cmake gnome pkgconfig

CMAKE_SOURCE_PATH=	${WRKSRC}/subprojects/appmenu-gtk-module

USE_GNOME=	gtk30 glib20 gtk20 gdkpixbuf2
GLIB_SCHEMAS=	org.appmenu.gtk-module.gschema.xml

USE_GITLAB=	yes
GL_ACCOUNT=	vala-panel-project
GL_PROJECT=	vala-panel-appmenu
GL_COMMIT=	c2cb48f07d95079e566eed78b28880e00f31c637

.include <bsd.port.mk>
