PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.49.0
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Phone compositor
WWW=		https://gitlab.gnome.org/World/Phosh/phoc

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.15:graphics/wayland-protocols
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libudev.so:devel/libudev-devd \
		libwayland-server.so:graphics/wayland \
		libwlroots-0.19.so:x11-toolkits/wlroots019 \
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
GL_TUPLE=	World/Phosh:gmobile:v0.2.0:gmobile/subprojects/gmobile \
		GNOME:gvdb:4758f6f:gvdb/subprojects/gvdb
MESON_ARGS=	-Dembed-wlroots=disabled
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-outputs-states \
		share/man/man1/${PORTNAME}-outputs-states.1.gz \
		share/man/man5/${PORTNAME}.ini.5.gz \
		share/applications/mobi.phosh.Phoc.desktop \
		share/icons/hicolor/symbolic/apps/mobi.phosh.Phoc.svg
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils
MANPAGES_MESON_TRUE=	man
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man5/${PORTNAME}.gsettings.5.gz

.ifdef GL_TUPLE
post-configure:
	@${REINPLACE_CMD} 's/meson install/& \
		--skip-subprojects/' ${BUILD_WRKSRC}/build.ninja
.endif

.include <bsd.port.mk>
