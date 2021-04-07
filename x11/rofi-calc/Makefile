PORTNAME=	rofi-calc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	x11

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Do live calculations in rofi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rofi:x11/rofi
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libglib-2.0.so:devel/glib20 \
		libqalculate.so:math/libqalculate
RUN_DEPENDS=	rofi:x11/rofi

USES=		autoreconf gettext-runtime libtool pkgconfig
USE_GITHUB=	yes

GH_ACCOUNT=	svenstaro
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/rofi/calc.so

.include <bsd.port.mk>
