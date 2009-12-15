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

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	| sh

USE_XORG=	x11
NO_WRKSUBDIR=	yes
MAKEFILE=	Makefile.noimake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lX11"
PLIST_FILES=	bin/9menu
MAN1=		9menu.1
MANCOMPRESSED=	yes	# vendor installation routine does this for us

.include <bsd.port.mk>
