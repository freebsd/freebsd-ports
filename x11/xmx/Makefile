PORTNAME=	xmx
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.brown.edu/pub/xmx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X protocol multiplexor
WWW=		https://cs.brown.edu/software/xmx/

USES=		tar:Z xorg
USE_XORG=	x11

PLIST_FILES=	bin/xmx share/man/man1/xmx.1.gz

MAKE_ARGS+=	BIN=${STAGEDIR}${PREFIX}/bin/ MANPATH=${STAGEDIR}${PREFIX}/share/man/

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xmx

.include <bsd.port.mk>
