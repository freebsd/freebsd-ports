# New ports collection makefile for:	lupe
# Version required:	0.07
# Date created:		4 February 1998
# Whom:			FURUSAWA,Kazuhisa <kazu@jp.freebsd.org>
#
# $Id: Makefile,v 1.5 1998/10/05 05:17:56 steve Exp $
#

DISTNAME=	lupe008
PKGNAME=	lupe-0.08
CATEGORIES=	x11
MASTER_SITES=	http://www2s.biglobe.ne.jp/~yav/soft/

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
