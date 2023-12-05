PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.34.0_beta1
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Phone compositor
WWW=		https://gitlab.gnome.org/World/Phosh/phoc

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.15:graphics/wayland-protocols \
		wlroots>=0.17.0<0.18.0:x11-toolkits/wlroots
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/share/glib-2.0/schemas/org.gnome.mutter.gschema.xml:x11-wm/mutter

USES=		compiler:c11 gettext gl gnome meson pkgconfig xorg
USE_GITLAB=	yes
USE_GL=		glesv2
USE_GNOME=	cairo gnomedesktop3
USE_XORG=	pixman xcb
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/Phosh
GL_TUPLE=	World/Phosh:gmobile:v0.0.4-5-g5ae8f59:gmobile/subprojects/gmobile
MESON_ARGS=	-Dembed-wlroots=disabled
PLIST_FILES=	bin/${PORTNAME} \
		man/man5/${PORTNAME}.ini.5.gz \
		share/applications/sm.puri.Phoc.desktop \
		share/icons/hicolor/symbolic/apps/sm.puri.Phoc.svg
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils
MANPAGES_MESON_TRUE=	man
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
