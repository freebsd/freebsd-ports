# New ports collection makefile for:	wm2
# Date created:		16 February 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	wm2
PORTVERSION=	4.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.all-day-breakfast.com/wm2/
DISTNAME=	${PORTNAME}-4

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
ALL_TARGET=	depend wm2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wm2 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/wm2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wm2
.endif

.include <bsd.port.mk>
