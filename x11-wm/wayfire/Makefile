# $FreeBSD$

PORTNAME=	wayfire
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	c51e3eda7fa0.patch:-p1 # drop unused
PATCHFILES+=	c4d4c941e773.patch:-p1 # support SUID
PATCHFILES+=	45535347c922.patch:-p1 # wlroots 0.7

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

USES=		compiler:c++11-lib gl jpeg meson pkgconfig
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
