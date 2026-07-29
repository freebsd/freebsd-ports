PORTNAME=	xkbprint
DISTVERSION=	1.0.8
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generates a PostScript image of an XKB keyboard description.
WWW=		https://gitlab.freedesktop.org/xorg/app/xkbprint

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xkbfile xorgproto

PLIST_FILES=	bin/xkbprint share/man/man1/xkbprint.1.gz

.include <bsd.port.mk>
