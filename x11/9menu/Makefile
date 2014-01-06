# Created by: Eric L. Hernes <erich@rrnet.com>
# $FreeBSD$

PORTNAME=	9menu
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	x11 plan9
MASTER_SITES=	ftp://freefriends.org/arnold/Source/ \
		${MASTER_SITE_NETBSD}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple menu patterned after Plan9

EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	| ${SH}

USE_XORG=	x11
NO_WRKSUBDIR=	yes
MAKEFILE=	Makefile.noimake
ALL_TARGET=	9menu
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lX11"
PLIST_FILES=	bin/9menu man/man1/9menu.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9menu.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
