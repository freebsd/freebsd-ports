PORTNAME=	showmethekey
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18.4
CATEGORIES=	x11 wayland

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Show keys you typed on screen
WWW=		https://showmethekey.alynx.one/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libinput.so:x11/libinput \
		libjson-glib-1.0.so:devel/json-glib \
		libudev.so:devel/libudev-devd \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${PKEXEC}

USES=		compiler:c11 gettext-tools gnome meson pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	AlynxZhou
USE_GNOME=	cairo gtk40 libadwaita
GLIB_SCHEMAS=	one.alynx.showmethekey.gschema.xml
USE_XORG=	x11
PKEXEC?=	pkexec:sysutils/polkit
MESON_ARGS=	-Dpkexec_path="${PKEXEC:C/\:.*//}"

.include <bsd.port.mk>
