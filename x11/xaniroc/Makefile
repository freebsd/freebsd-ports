# New ports collection makefile for:   xaniroc
# Date created:        20 Sep 1997
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	xaniroc
PORTVERSION=	1.02
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.42.org/pub/orphan/
DISTNAME=	${PORTNAME}	
EXTRACT_SUFX=	.src.tar.Z

MAINTAINER=	sec@42.org
COMMENT=	Animate your root-cursor

USE_IMAKE=	yes
MAN1=		xaniroc.1
PLIST_FILES=	bin/xaniroc

post-extract:
	${MV} ${WRKSRC}/manpage.1 ${WRKSRC}/xaniroc.man

.include <bsd.port.mk>
