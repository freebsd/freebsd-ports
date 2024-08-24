PORTNAME=	wayfire-plugins-extra
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Additional plugins for Wayfire
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-scanner:graphics/wayland \
		wayland-protocols>0:graphics/wayland-protocols \
		wayfire>0:x11-wm/wayfire
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwf-config.so:devel/wf-config \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots017

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GITLAB=	nodefault
USE_GNOME=	cairo glibmm
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	timgott:wayfire-shadows:de32395:wayfire_shadows/subprojects/wayfire-shadows \
		soreau:pixdecor:d172e84:pixdecor/subprojects/pixdecor \
		soreau:filters:5850fee:filters/subprojects/filters
GL_TUPLE=	wayfireplugins:focus-request:bc41d54:focus_request/subprojects/focus-request \
		wayfireplugins:windecor:f609ac0:windecor/subprojects/windecor
MESON_ARGS=	-Denable_focus_request=true -Denable_wayfire_shadows=true \
		-Denable_filters=true

OPTIONS_DEFINE=	LIBRSVG2 PANGO
OPTIONS_DEFAULT=LIBRSVG2 PANGO
OPTIONS_SUB=	yes

PANGO_USE=		GNOME=pango
PANGO_MESON_TRUE=	enable_pixdecor

LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_MESON_TRUE=	enable_windecor

post-patch:
# Respect PREFIX for icons
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/subprojects/windecor/deco-icontheme.cpp

.include <bsd.port.mk>
