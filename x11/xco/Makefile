# New ports collection makefile for:	xco
# Date created:		6 Jun 1997
# Whom:			Satoshi TAOKA
#
# $FreeBSD$
#

PORTNAME=	xco
PORTVERSION=	1.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.purdue.edu/pub/bingle/
DISTNAME=	${PORTNAME}

MAINTAINER=	taoka@FreeBSD.org

USE_IMAKE=	yes
USE_REINPLACE=	yes
MAN1=		xco.1
MANCOMPRESSED=	yes
DOCDIR=		${PREFIX}/share/doc/xco

post-patch:
		@${REINPLACE_CMD} -e 's/extern char \*malloc();//g' \
			${WRKSRC}/xco.c ${WRKSRC}/xargs.c

post-install:
		@${MKDIR} ${DOCDIR}
		@${INSTALL_DATA} ${FILESDIR}/copyright ${DOCDIR}

.include <bsd.port.mk>
