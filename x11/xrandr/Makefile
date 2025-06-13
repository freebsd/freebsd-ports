PORTNAME=	xrandr
DISTVERSION=	1.5.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Primitive command line interface to the RandR extension
WWW=		https://gitlab.freedesktop.org/xorg/app/xrandr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xorgproto xrandr xrender

PLIST_FILES=	bin/xrandr \
		share/man/man1/xrandr.1.gz

.include <bsd.port.mk>
