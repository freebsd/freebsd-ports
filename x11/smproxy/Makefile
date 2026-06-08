PORTNAME=	smproxy
DISTVERSION=	1.0.8
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Session Manager Proxy
WWW=		https://gitlab.freedesktop.org/xorg/app/smproxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	ice sm x11 xmuu xorgproto xt

PLIST_FILES=	bin/smproxy share/man/man1/smproxy.1.gz

.include <bsd.port.mk>
