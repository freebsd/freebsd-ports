# $FreeBSD$

PORTNAME=	wayfire
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	3D Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wf-config>=0.5.0<0.6.0:devel/wf-config \
		${LOCALBASE}/include/xf86drmMode.h:graphics/libdrm \
		wayland-protocols>=1.12:graphics/wayland-protocols \
		glm>=0.9.8:math/glm \
		wlroots>=0.11.0<0.12.0:x11-toolkits/wlroots
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libwf-config.so:devel/wf-config \
		libpng.so:graphics/png \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++17-lang gl gnome jpeg meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		egl glesv2
USE_GNOME=	cairo
USE_XORG=	pixman
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	WayfireWM:wf-utils:f9b5eba:wfutils/subprojects/wf-utils

OPTIONS_DEFINE=	SUID X11
OPTIONS_DEFAULT=SUID X11

SUID_DESC=		setuid bit on "${PORTNAME}" binary (to claim DRM without seatd/console-kit-daemon)
SUID_PLIST_SUB=		MAYBE_SUID="@(,,4755) "
SUID_PLIST_SUB_OFF=	MAYBE_SUID=""

X11_USE=		XORG=xcb
X11_MESON_ENABLED=	xwayland

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
