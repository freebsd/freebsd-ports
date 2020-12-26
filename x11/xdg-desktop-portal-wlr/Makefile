# $FreeBSD$

PORTNAME=	xdg-desktop-portal-wlr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	7e9f693e5d2a.patch:-p1 # https://github.com/emersion/xdg-desktop-portal-wlr/pull/73
PATCHFILES+=	485af2c45ab0.patch:-p1 # https://github.com/emersion/xdg-desktop-portal-wlr/pull/73
PATCHFILES+=	08ad7e4182e6.patch:-p1 # https://github.com/emersion/xdg-desktop-portal-wlr/pull/73

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xdg-desktop-portal backend for wlroots

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libbasu.so:devel/basu \
		libwayland-client.so:graphics/wayland \
		libpipewire-0.3.so:multimedia/pipewire

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	emersion
MESON_ARGS=	-Dsd-bus-provider=basu
PLIST_FILES=	libexec/${PORTNAME} \
		share/dbus-1/services/org.freedesktop.impl.portal.desktop.wlr.service \
		share/xdg-desktop-portal/portals/wlr.portal

.include <bsd.port.mk>
