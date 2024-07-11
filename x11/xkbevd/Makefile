PORTNAME=	xkbevd
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Keyboard Extension event daemon
WWW=		https://gitlab.freedesktop.org/xorg/app/xkbevd

LICENSE=	MIT

USES=		xorg xorg-cat:app
USE_XORG=	xkbfile x11

PLIST_FILES=	bin/xkbevd share/man/man1/xkbevd.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
