# $FreeBSD$

PORTNAME=	wayfire
DISTVERSION=	0.3.0
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	3D wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		${LOCALBASE}/include/xf86drmMode.h:graphics/libdrm \
		wayland-protocols>=1.12:graphics/wayland-protocols \
		glm>=0.9.8:math/glm
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libwf-config.so:devel/wf-config \
		libpng.so:graphics/png \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lib gl gnome jpeg meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		egl glesv2
USE_GNOME=	cairo
USE_XORG=	pixman
GH_ACCOUNT=	WayfireWM

OPTIONS_DEFINE=	SUID
OPTIONS_DEFAULT=SUID

SUID_DESC=		setuid bit on "${PORTNAME}" binary (required for DRM session)
SUID_PLIST_SUB=		MAYBE_SUID="@(,,4755) "
SUID_PLIST_SUB_OFF=	MAYBE_SUID=""

.include <bsd.port.mk>
