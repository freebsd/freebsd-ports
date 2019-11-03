# $FreeBSD$

PORTNAME=	xrandr
PORTVERSION=	1.5.1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Primitive command line interface to the RandR extension

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	xrandr xrender x11

PLIST_FILES=	bin/xrandr \
		bin/xkeystone \
		man/man1/xrandr.1.gz

.include <bsd.port.mk>
