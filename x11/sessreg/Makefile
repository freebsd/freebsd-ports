PORTNAME=	sessreg
DISTVERSION=	1.1.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Manage utmpx/wtmpx entries for non-init X clients
WWW=		https://gitlab.freedesktop.org/xorg/app/sessreg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	xorgproto

PLIST_FILES=	bin/sessreg share/man/man1/sessreg.1.gz

.include <bsd.port.mk>
