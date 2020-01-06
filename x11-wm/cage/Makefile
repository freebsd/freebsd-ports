# $FreeBSD$

PORTNAME=	cage
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
PORTREVISION=	6
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland kiosk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols \
		wlroots>=0.6.0:x11-toolkits/wlroots
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
GH_ACCOUNT=	Hjdskes
PLIST_FILES=	"${MAYBE_SUID}bin/${PORTNAME}"

OPTIONS_DEFINE=	SUID X11
OPTIONS_DEFAULT=SUID X11

SUID_DESC=	setuid bit on "${PORTNAME}" binary (required for DRM session)
SUID_VARS=	MAYBE_SUID="@(,,4755) "

X11_MESON_TRUE=	xwayland

.include <bsd.port.mk>
