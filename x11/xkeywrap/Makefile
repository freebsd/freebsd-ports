# New ports collection makefile for:   XKeyWrap
# Date created:        7 January 2000
# Whom:                Sakai Hiroaki <sakai@seki.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xkeywrap
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://www.seki.ee.kagu.sut.ac.jp/~sakai/

MAINTAINER=	sakai@seki.ee.kagu.sut.ac.jp

USE_X_PREFIX=	yes
MAN1=		xkeywrap.1
PORTSDOCDIR=	${PREFIX}/share/doc/xkeywrap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xkeywrap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xkeywrap.man ${PREFIX}/man/man1/xkeywrap.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORTSDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PORTSDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/demo.dat ${PORTSDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/xkeywrap_demo.c ${PORTSDOCDIR}
.endif

.include <bsd.port.mk>
