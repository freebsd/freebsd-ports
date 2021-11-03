PORTNAME=	appmenu-registrar
DISTVERSION=	0.7.6
CATEGORIES=	x11

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	442bcebcc00e.patch:-p1 # meson >= 0.60

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Appmenu DBusMenu registrar

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbamf3.so:sysutils/bamf
BUILD_DEPENDS=	valac:lang/vala

USES=	meson gnome pkgconfig gettext

MESON_ARGS=	-Dvalapanel=disabled \
		-Dxfce=disabled \
		-Dmate=disabled \
		-Dbudgie=disabled \
		-Djayatana=disabled \
		-Dregistrar=enabled \
		-Dappmenu-gtk-module=disabled

USE_GNOME=	gtk30 glib20 gtk20 gdkpixbuf2

USE_GITLAB=	yes
GL_ACCOUNT=	vala-panel-project
GL_PROJECT=	vala-panel-appmenu
GL_COMMIT=	4e362c22ab3a23c98f13fb379c782786ee057cf6

.include <bsd.port.mk>
