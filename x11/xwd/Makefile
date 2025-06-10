PORTNAME=	xwd
DISTVERSION=	1.0.9
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Dump an image of an X window
WWW=		https://gitlab.freedesktop.org/xorg/app/xwd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xkbfile xorgproto

PLIST_FILES=	bin/xwd share/man/man1/xwd.1.gz

.include <bsd.port.mk>
