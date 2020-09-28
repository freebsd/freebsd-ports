# $FreeBSD$

PORTNAME=	wcm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayfire Config Manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayfire>0:x11-wm/wayfire \
		wf-shell>0:x11/wf-shell
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwf-config.so:devel/wf-config \
		libwayland-client.so:graphics/wayland

CONFLICTS_INSTALL=	wcmcommander # bin/wcm

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtk30 libxml2
GH_ACCOUNT=	WayfireWM
DATADIR=	${PREFIX}/share/wayfire
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
