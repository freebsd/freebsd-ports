PORTNAME=	xf86dga
DISTVERSION=	1.0.3
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Test program for the XFree86-DGA extension
WWW=		https://gitlab.freedesktop.org/xorg/app/xf86dga

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:bz2 xorg xorg-cat:app
USE_XORG=	x11 xxf86dga xt xaw7 xmu

PLIST_FILES=	bin/dga share/man/man1/dga.1.gz

.include <bsd.port.mk>
