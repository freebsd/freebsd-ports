PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.29.0
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

USES=		compiler:c11 gettext gl gnome meson pkgconfig python:build shebangfix xorg
USE_GITLAB=	yes
USE_GL=		glesv2
USE_GNOME=	cairo gnomedesktop3
USE_XORG=	pixman xcb
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/Phosh
GL_COMMIT=	e2848b26104200e2f7fff3d29f8eb7365313f474
GL_TUPLE=	https://gitlab.gnome.org:guidog:gmobile:ff854988bff80f2d4c1181ccf3c94b032603b6f9:gmobile/subprojects/gmobile
SHEBANG_FILES=	build-aux/post_install.py
MESON_ARGS=	-Dembed-wlroots=disabled
CFLAGS+=	-Wno-error=format-nonliteral # clang
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/sm.puri.Phoc.desktop \
		share/icons/hicolor/symbolic/apps/sm.puri.Phoc.svg
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils
MANPAGES_MESON_TRUE=	man
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

.include "${.CURDIR:H:H}/x11-toolkits/wlroots015/override.mk"
.include <bsd.port.mk>
