# New ports collection makefile for:   XKeyWrap
# Date created:        7 January 2000
# Whom:                Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xkeywrap
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://hp.vector.co.jp/authors/VA014157/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Record, repeat, and play key sequence from keyboard

USE_XORG=	x11 xt
MAN1=		xkeywrap.1
MANCOMPRESSED=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xkeywrap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xkeywrap.1.gz ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/demo.dat ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/xkeywrap_demo.c ${DOCSDIR}
.endif

.include <bsd.port.mk>
