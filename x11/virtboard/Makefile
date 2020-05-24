# $FreeBSD$

PORTNAME=	virtboard
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.6
CATEGORIES=	x11

PATCH_SITES=	${GL_SITE}/jbeich/${GL_PROJECT}/-/commit/
PATCHFILES+=	42e698964e42.diff:-p1
PATCHFILES+=	86e6915d4920.diff:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Basic keyboard, blazing the path of modern Wayland keyboards

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libpng.so:graphics/png \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		compiler:c11 gettext-tools gnome meson pkgconfig xorg
USE_GITLAB=	yes
USE_GNOME=	cairo glib20
USE_XORG=	pixman
GL_SITE=	https://source.puri.sm
GL_ACCOUNT=	Librem5
GL_COMMIT=	1d30b07870bf6138395d6529ab496e321b8b3938
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/sm.puri.Virtboard.desktop \
		share/dbus-1/interfaces/sm.puri.OSK0.xml

.include <bsd.port.mk>
