# New ports collection makefile for:    9menu
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	9menu
PORTVERSION=	1.8
CATEGORIES=	x11 plan9
MASTER_SITES=	ftp://freefriends.org/arnold/Source/ \
		${MASTER_SITE_NETBSD}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	serge.gagnon@b2b2c.ca
COMMENT=	A simple menu patterened after plan9

PLIST_FILES=		bin/9menu
USE_XLIB=		yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
MAKEFILE=		Makefile.noimake
ALL_TARGET=		9menu

NO_WRKSUBDIR=	yes

MAN1=		9menu.1
MANCOMPRESSED=	yes

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -I${X11BASE}/include -L${X11BASE}/lib -lX11 -o 9menu 9menu.c

.include <bsd.port.mk>
