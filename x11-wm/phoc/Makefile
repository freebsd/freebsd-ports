PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26.0
PORTREVISION=	1
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Phone compositor
WWW=		https://gitlab.gnome.org/World/Phosh/phoc

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.15:graphics/wayland-protocols \
		wlroots>=0.15.1<0.16.0:x11-toolkits/wlroots
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/share/glib-2.0/schemas/org.gnome.mutter.gschema.xml:x11-wm/mutter

USES=		compiler:c11 gl gnome meson pkgconfig python:build shebangfix xorg
USE_GITLAB=	yes
USE_GL=		glesv2
USE_GNOME=	cairo gnomedesktop3
USE_XORG=	pixman xcb
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/Phosh
GL_COMMIT=	28d718ac3c1323f591481de4f90e9888edf4da10
GL_TUPLE=	https://gitlab.gnome.org:guidog:gmobile:ff854988bff80f2d4c1181ccf3c94b032603b6f9:gmobile/subprojects/gmobile
SHEBANG_FILES=	build-aux/post_install.py
MESON_ARGS=	-Dembed-wlroots=disabled
CFLAGS+=	-Wno-error=format-nonliteral # clang
PLIST_FILES=	bin/${PORTNAME}
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

.include "${.CURDIR:H:H}/x11-toolkits/wlroots015/override.mk"
.include <bsd.port.mk>
