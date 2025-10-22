PORTNAME=	rofi-calc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	x11

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Do live calculations in rofi
WWW=		https://github.com/svenstaro/rofi-calc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	re2c:devel/re2c \
		rofi:x11/rofi
RUN_DEPENDS=	qalc:math/libqalculate \
		rofi:x11/rofi

USES=		gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	svenstaro
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PLIST_FILES=	lib/rofi/libcalc.so

.include <bsd.port.mk>
