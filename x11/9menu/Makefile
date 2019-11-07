# Created by: Eric L. Hernes <erich@rrnet.com>
# $FreeBSD$

PORTNAME=	9menu
PORTVERSION=	1.9
DISTVERSIONPREFIX=	${PORTNAME}-release-
CATEGORIES=	x11 plan9

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple menu patterned after Plan9

USE_GITHUB=	yes
GH_ACCOUNT=	arnoldrobbins
USES=		xorg
USE_XORG=	x11
MAKEFILE=	Makefile.noimake
ALL_TARGET=	9menu
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lX11"
PLIST_FILES=	bin/9menu man/man1/9menu.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9menu.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
