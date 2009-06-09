# New ports collection makefile for:   xmove
# Date created:        16 Jan 1997
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	xmove
PORTVERSION=	2.0b2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.columbia.edu/pub/xmove/
DISTNAME=	${PORTNAME}.${PORTVERSION:S/b/beta/}

MAINTAINER=	sec@42.org
COMMENT=	Pseudoserver to support mobile X11 clients

WRKSRC=		${WRKDIR}/xmove

USE_IMAKE=	yes
USE_XORG=	x11

MAN1=		xmove.1 xmovectrl.1

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${CP} ${FILESDIR}/Imakefile ${WRKSRC}
	(cd ${WRKSRC}; \
	 ${CP} man/man1/xmove.1 xmove/xmove.man; \
	 ${CP} man/man1/xmovectrl.1 xmovectrl/xmovectrl.man)

.include <bsd.port.mk>
