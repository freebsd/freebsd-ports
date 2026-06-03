PORTNAME=	xbacklight
DISTVERSION=	1.2.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Utility to adjust backlight brightness using RandR extension
WWW=		https://gitlab.freedesktop.org/xorg/app/xbacklight

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	xcb

PLIST_FILES=	bin/xbacklight share/man/man1/xbacklight.1.gz

.include <bsd.port.mk>
