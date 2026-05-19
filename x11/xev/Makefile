PORTNAME=	xev
DISTVERSION=	1.2.7
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Print contents of X events
WWW=		https://gitlab.freedesktop.org/xorg/app/xev

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xorgproto xrandr

PLIST_FILES=	bin/xev share/man/man1/xev.1.gz

.include <bsd.port.mk>
