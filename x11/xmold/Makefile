# New ports collection makefile for:	xmold
# Date created:		11 October 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xmold
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xwin/ \
		ftp://ftp.opaopa.org/pub/archives/games/
DISTNAME=	${PORTNAME}

MAINTAINER=	nakai@FreeBSD.org

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmold ${PREFIX}/bin

.include <bsd.port.mk>
