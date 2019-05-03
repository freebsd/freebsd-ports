# $FreeBSD$

PORTNAME=	cage
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	c69d394bedc6.patch:-p1
PATCHFILES+=	61894994f3c7.patch:-p1
PATCHFILES+=	9354781f3227.patch:-p1
PATCHFILES+=	6bb73b365807.patch:-p1
PATCHFILES+=	f23257d170d7.patch:-p1
PATCHFILES+=	5af455a905d4.patch:-p1
PATCHFILES+=	b16fc7d78082.patch:-p1
PATCHFILES+=	1de6054d7e8d.patch:-p1

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

USES=		compiler:c11 meson pkgconfig
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
