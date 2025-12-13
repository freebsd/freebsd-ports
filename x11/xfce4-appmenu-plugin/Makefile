PORTNAME=	xfce4-appmenu-plugin
DISTVERSION=	0.7.6
PORTREVISION=	4
CATEGORIES=	x11

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	442bcebcc00e.patch:-p1 # meson >= 0.60

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Application Menu plugin for XFCE panel
WWW=		https://gitlab.com/vala-panel-project/vala-panel-appmenu

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbamf3.so:sysutils/bamf
RUN_DEPENDS=	appmenu-registrar>=0:x11/appmenu-registrar \
		appmenu-gtk-module>=0:x11/gtk-app-menu

USES=	meson gnome xfce pkgconfig gettext vala:build

MESON_ARGS=	-Dvalapanel=disabled \
		-Dxfce=enabled \
		-Dmate=disabled \
		-Dbudgie=disabled \
		-Djayatana=disabled \
		-Dregistrar=disabled \
		-Dappmenu-gtk-module=disabled

USE_XFCE=	panel xfconf
USE_GNOME=	gtk30 glib20 gtk20 gdkpixbuf

USE_GITLAB=	yes
GL_ACCOUNT=	vala-panel-project
GL_PROJECT=	vala-panel-appmenu
GL_TAGNAME=	4e362c22ab3a23c98f13fb379c782786ee057cf6

.include <bsd.port.mk>
