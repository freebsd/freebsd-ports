# $FreeBSD$

PORTNAME=	rofi-calc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5
CATEGORIES=	x11

MAINTAINER=	alex@xanderio.de
COMMENT=	Do live calculations in rofi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rofi:x11/rofi
BUILD_DEPENDS=	rofi:x11/rofi
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libglib-2.0.so:devel/glib20 \
		libqalculate.so:math/libqalculate

USES=		autoreconf gettext-runtime libtool pkgconfig
USE_GITHUB=	yes

GH_ACCOUNT=	svenstaro
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/rofi/calc.so

.include <bsd.port.mk>
