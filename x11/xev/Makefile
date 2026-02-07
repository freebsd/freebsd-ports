PORTNAME=	xev
PORTVERSION=	1.2.6
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Print contents of X events

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xrandr

PLIST_FILES=	bin/xev share/man/man1/xev.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
