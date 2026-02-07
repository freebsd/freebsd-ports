PORTNAME=	xrdb
DISTVERSION=	1.2.2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X server resource database utility
WWW=		https://gitlab.freedesktop.org/xorg/app/xrdb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xmuu xorgproto

PLIST_FILES=	bin/xrdb share/man/man1/xrdb.1.gz

.include <bsd.port.mk>
