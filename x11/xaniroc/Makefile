# New ports collection makefile for:   xaniroc
# Date created:        20 Sep 1997
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	xaniroc
PORTVERSION=	1.02
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.freebird.org/unixware/freebird/x11/utils/ \
		ftp://netlab1.usu.edu/pub/mirror/freebird/x11/utils/
DISTNAME=	${PORTNAME}	
EXTRACT_SUFX=	.src.tar.Z

MAINTAINER=	sec@42.org

USE_IMAKE=	yes
MAN1=		xaniroc.1

post-extract:
	${MV} ${WRKSRC}/manpage.1 ${WRKSRC}/xaniroc.man

.include <bsd.port.mk>
