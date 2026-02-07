PORTNAME=	xsetroot
DISTVERSION=	1.1.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Root window parameter setting utility for X
WWW=		https://gitlab.freedesktop.org/xorg/app/xsetroot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xbitmaps xcursor xmuu xorgproto

PLIST_FILES=	bin/xsetroot share/man/man1/xsetroot.1.gz

.include <bsd.port.mk>
