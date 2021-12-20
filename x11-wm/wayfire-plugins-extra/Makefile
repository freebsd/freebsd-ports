PORTNAME=	wayfire-plugins-extra
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	4
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a8eca14c44b9.patch:-p1 # https://github.com/WayfireWM/wayfire-plugins-extra/pull/106

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Additional plugins for Wayfire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-scanner:graphics/wayland \
		wayland-protocols>0:graphics/wayland-protocols \
		wayfire>0:x11-wm/wayfire
LIB_DEPENDS=	libwf-config.so:devel/wf-config \
		libwlroots.so:x11-toolkits/wlroots

USES=		compiler:c++17-lang gnome meson pkgconfig shebangfix
USE_GITHUB=	yes
USE_GITLAB=	nodefault
USE_GNOME=	cairo glibmm
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	damianatorrpm:wayfire-plugin_dbus_interface:c705bf1:dbus/subprojects/dbus
GL_TUPLE=	wayfireplugins:windecor:6ad31bfc10c5d39c0da7c68fa435064effad6381:windecor/subprojects/windecor
SHEBANG_FILES=	subprojects/dbus/compile-schemas.sh
bash_CMD=	${SH}

OPTIONS_DEFINE=	DBUS LIBRSVG2
OPTIONS_DEFAULT=DBUS LIBRSVG2
OPTIONS_SUB=	yes

DBUS_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
DBUS_USES=		xorg
DBUS_USE=		XORG=xcb
DBUS_MESON_TRUE=	enable_dbus
DBUS_VARS=		GLIB_SCHEMAS+=org.wayland.compositor.dbus.gschema.xml

LIBRSVG2_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIBRSVG2_USES=		xorg
LIBRSVG2_USE=		GNOME=librsvg2 XORG=pixman
LIBRSVG2_MESON_TRUE=	enable_windecor

.include <bsd.port.mk>
