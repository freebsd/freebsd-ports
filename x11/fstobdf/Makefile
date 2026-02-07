PORTNAME=	fstobdf
DISTVERSION=	1.0.7
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generate BDF font from X font server
WWW=		https://gitlab.freedesktop.org/xorg/app/fstobdf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	libfs x11 xorgproto

PLIST_FILES=	bin/fstobdf share/man/man1/fstobdf.1.gz

.include <bsd.port.mk>
