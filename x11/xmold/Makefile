# New ports collection makefile for:	xmold
# Version required:	1.0
# Date created:		11 October 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	xmold
PKGNAME=	xmold-1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xwin/

MAINTAINER=	nakai@FreeBSD.org

USE_IMAKE=	yes
NO_INSTALL_MANPAGE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmold ${PREFIX}/bin

.include <bsd.port.mk>
