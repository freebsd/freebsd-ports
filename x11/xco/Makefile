# New ports collection makefile for:	xco
# Date created:		6 Jun 1997
# Whom:			Satoshi TAOKA
#
# $FreeBSD$
#

PORTNAME=	xco
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	x11
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display X11 color names and colors

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
