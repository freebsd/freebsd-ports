# New ports collection makefile for:	lupe
# Date created:		4 February 1998
# Whom:			FURUSAWA,Kazuhisa <kazu@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	lupe
PORTVERSION=	0.08
CATEGORIES=	x11
MASTER_SITES=	http://www.oersted.co.jp/~yav/soft/
DISTNAME=	lupe008	

MAINTAINER=	kazu@jp.freebsd.org

WRKSRC=		${WRKDIR}/lupe
USE_IMAKE=	yes
XMKMF=		xmkmf
MAN1=		lupe.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/lupe
	${INSTALL_MAN} ${WRKSRC}/lupe.doc ${PREFIX}/share/doc/lupe
.endif

.include <bsd.port.mk>
