# New ports collection makefile for:	lupe
# Date created:		4 February 1998
# Whom:			FURUSAWA,Kazuhisa <kazu@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	lupe
PORTVERSION=	0.08c
CATEGORIES=	x11 accessibility
MASTER_SITES=	http://www.oersted.co.jp/~yav/soft/
DISTNAME=	lupe008c

MAINTAINER=	kazu@jp.freebsd.org
COMMENT=	Real-time magnifying glass for X11

WRKSRC=		${WRKDIR}/lupe
USE_IMAKE=	yes
USE_XORG=	x11 xext
XMKMF=		xmkmf
MAN1=		lupe.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/lupe.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
