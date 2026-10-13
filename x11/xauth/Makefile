PORTNAME=	xauth
DISTVERSION=	1.1.5
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X authority file utility
WWW=		https://gitlab.freedesktop.org/xorg/app/xauth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		shebangfix xorg xorg-cat:app
USE_XORG=	x11 xau xext xmuu xorgproto
SHEBANG_FILES=	${WRKSRC}/tests/*.script
SHEBANG_LANG=	nobash
nobash_OLD_CMD=	/bin/bash
nobash_CMD=	/bin/sh
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_FILES=	bin/xauth \
		share/man/man1/xauth.1.gz

.include <bsd.port.mk>
