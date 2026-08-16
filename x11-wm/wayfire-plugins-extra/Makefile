PORTNAME=	wayfire-plugins-extra
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	x11-wm wayland

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Additional plugins for Wayfire
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		evdev-proto>0:devel/evdev-proto \
		glm>0:math/glm \
		wayfire>0:x11-wm/wayfire \
		wayland-protocols>0:graphics/wayland-protocols \
		wayland-scanner:graphics/wayland
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwayland-server.so:graphics/wayland \
		libwf-config.so:devel/wf-config \
		libwlroots-0.20.so:x11-toolkits/wlroots020

USES=		cmake:indirect compiler:c++17-lang gettext-tools gl gnome meson \
		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	timgott:wayfire-shadows:4bfdbbf:wayfireshadows/subprojects/wayfire-shadows \
		soreau:pixdecor:a9465be:pixdecor/subprojects/pixdecor \
		soreau:filters:8fcaad8:filters/subprojects/filters
USE_GITLAB=	nodefault
GL_TUPLE=	wayfireplugins:focus-request:v0.9.0:focus_request/subprojects/focus-request
USE_GL=		glesv2
USE_GNOME=	cairo glibmm

MESON_ARGS=	-Denable_filters=true \
		-Denable_focus_request=true \
		-Denable_wayfire_shadows=true

OPTIONS_DEFINE=		PANGO
OPTIONS_DEFAULT=	PANGO
OPTIONS_SUB=		yes

PANGO_USE=		GNOME=pango
PANGO_MESON_TRUE=	enable_pixdecor

.include <bsd.port.mk>
