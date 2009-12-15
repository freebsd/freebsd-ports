# New ports collection makefile for:	9menu
# Date created:				Sun Aug 13 12:36:14 CDT 1995
# Whom:					Eric L. Hernes <erich@rrnet.com>
#
# $FreeBSD$
#

PORTNAME=	9menu
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	x11 plan9
MASTER_SITES=	ftp://freefriends.org/arnold/Source/ \
		${MASTER_SITE_NETBSD}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple menu patterned after Plan9

EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	| ${SH}

USE_XORG=	x11
NO_WRKSUBDIR=	yes
MAKEFILE=	Makefile.noimake
ALL_TARGET=	9menu
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lX11"
PLIST_FILES=	bin/9menu
MAN1=		9menu.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
