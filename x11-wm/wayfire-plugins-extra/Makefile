PORTNAME=	wayfire-plugins-extra
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	x11-wm wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Additional plugins for Wayfire
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		evdev-proto>0:devel/evdev-proto \
		wayland-scanner:graphics/wayland \
		wayland-protocols>0:graphics/wayland-protocols \
		wayfire>0:x11-wm/wayfire
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwf-config.so:devel/wf-config \
		libwayland-server.so:graphics/wayland \
		libwlroots-0.19.so:x11-toolkits/wlroots019

USES=		compiler:c++17-lang gl gnome meson pkgconfig
USE_GITHUB=	yes
USE_GITLAB=	nodefault
USE_GL=		glesv2
USE_GNOME=	cairo glibmm
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	timgott:wayfire-shadows:v0.9.0-1-g453c217:wayfire_shadows/subprojects/wayfire-shadows \
		soreau:pixdecor:8a0b028:pixdecor/subprojects/pixdecor \
		soreau:filters:00024b5:filters/subprojects/filters
GL_TUPLE=	wayfireplugins:focus-request:v0.9.0:focus_request/subprojects/focus-request
MESON_ARGS=	-Denable_focus_request=true -Denable_wayfire_shadows=true \
		-Denable_filters=true

OPTIONS_DEFINE=	PANGO
OPTIONS_DEFAULT=PANGO
OPTIONS_SUB=	yes

PANGO_USE=		GNOME=pango
PANGO_MESON_TRUE=	enable_pixdecor

.include <bsd.port.mk>
