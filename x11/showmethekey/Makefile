PORTNAME=	showmethekey
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Show keys you typed on screen

LICENSE=	APACHE20

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libevdev.so:devel/libevdev \
		libudev.so:devel/libudev-devd \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${PKEXEC}

USES=		compiler:c11 gettext-tools gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gtk30
GH_ACCOUNT=	AlynxZhou
PKEXEC?=	pkexec:sysutils/polkit
MESON_ARGS=	-Dpkexec_path="${PKEXEC:C/\:.*//}"
GLIB_SCHEMAS=	one.alynx.showmethekey.gschema.xml

.include <bsd.port.mk>
