# New ports collection makefile for:   XKeyWrap
# Date created:        7 January 2000
# Whom:                Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xkeywrap
PORTVERSION=	1.1
CATEGORIES=	x11
MASTER_SITES=	http://www.seki.ee.kagu.tus.ac.jp/~sakai/myfreesoft/ \
		http://hp.vector.co.jp/authors/VA014157/myfreesoft/ \
		http://www.people.or.jp/~hsakai/myfreesoft/

MAINTAINER=	sakai@seki.ee.kagu.tus.ac.jp
COMMENT=	Record, repeat, and play key sequence from keyboard

USE_X_PREFIX=	yes
MAN1=		xkeywrap.1
MANCOMPRESSED=	yes
PORTSDOCDIR=	${PREFIX}/share/doc/xkeywrap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xkeywrap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xkeywrap.1.gz ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORTSDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PORTSDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/demo.dat ${PORTSDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/xkeywrap_demo.c ${PORTSDOCDIR}
.endif

.include <bsd.port.mk>
