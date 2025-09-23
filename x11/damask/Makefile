PORTNAME=	damask
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	x11 gnome

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Automatically set wallpaper images from Internet sources
WWW=		https://gitlab.gnome.org/subpop/damask

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libportal.so:deskutils/libportal \
		libportal-gtk4.so:deskutils/libportal-gtk4 \
		libjson-glib-1.0.so:devel/json-glib \
		libgee-0.8.so:devel/libgee \
		libsoup-3.0.so:devel/libsoup3
RUN_DEPENDS=	xdg-desktop-portal-gnome>0:x11/xdg-desktop-portal-gnome

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig \
		vala:build

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	subpop

USE_GNOME=	glib20 gtk40 libadwaita
GLIB_SCHEMAS=	app.drey.Damask.gschema.xml

# Don't create __pycache__ directory when executing blueprint-compiler
# This is a workaround to avoid filesystem violations during poudriere build
MAKE_ENV=	PYTHONDONTWRITEBYTECODE=1

.include <bsd.port.mk>
