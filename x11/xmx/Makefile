# Created by: Oliver Breuninger <ob@seicom.NET>
# $FreeBSD$

PORTNAME=	xmx
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.brown.edu/pub/xmx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X protocol multiplexor

USES=		tar:Z xorg
USE_XORG=	x11

PLIST_FILES=	bin/xmx man/man1/xmx.1.gz

MAKE_ARGS+=	BIN=${STAGEDIR}${PREFIX}/bin/ MANPATH=${STAGEDIR}${MAN1PREFIX}/man/

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xmx

.include <bsd.port.mk>
