PORTNAME=	xkbcomp
DISTVERSION=	1.5.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XKB keyboard description compiler
WWW=		https://gitlab.freedesktop.org/xorg/app/xkbcomp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix tar:xz xorg xorg-cat:app
USE_XORG=	x11 xkbfile xorgproto

PLIST_FILES=	bin/xkbcomp \
		libdata/pkgconfig/xkbcomp.pc \
		share/man/man1/xkbcomp.1.gz

.include <bsd.port.mk>
