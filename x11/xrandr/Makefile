PORTNAME=	xrandr
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Primitive command line interface to the RandR extension

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

EXTRACT_SUFX=	.tar.xz
USES=		tar:xz xorg xorg-cat:app
USE_XORG=	xrandr xrender x11

PLIST_FILES=	bin/xrandr \
		bin/xkeystone \
		share/man/man1/xrandr.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
