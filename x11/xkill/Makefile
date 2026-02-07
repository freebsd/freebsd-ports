PORTNAME=	xkill
DISTVERSION=	1.0.6
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Utility for killing a client by its X resource
WWW=		https://gitlab.freedesktop.org/xorg/app/xkill

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xmuu xorgproto

PLIST_FILES=	bin/xkill share/man/man1/xkill.1.gz

.include <bsd.port.mk>
