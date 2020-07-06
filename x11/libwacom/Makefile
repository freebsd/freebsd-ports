# Created by: johalun0@gmail.com
# $FreeBSD$

PORTNAME=	libwacom
DISTVERSIONPREFIX=libwacom-
DISTVERSION=	1.4.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Adds tablet support to libinput

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev
TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	linuxwacom
USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
