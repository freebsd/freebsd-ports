PORTNAME=	xset
DISTVERSION=	1.2.6
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	User preference utility for X
WWW=		https://gitlab.freedesktop.org/xorg/app/xset

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	x11 xext xmuu xorgproto

CONFIGURE_ARGS=	--without-fontcache

PLIST_FILES=	bin/xset share/man/man1/xset.1.gz

.include <bsd.port.mk>
