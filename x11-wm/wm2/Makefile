# New ports collection makefile for:	wm2
# Version required:	3.0
# Date created:		16 February 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	wm2-3
PKGNAME=	wm2-3.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.netcomuk.co.uk/~cannam/

MAINTAINER=	nacai@iname.com

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/wm2
ALL_TARGET=	depend wm2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wm2 ${PREFIX}/bin

.include <bsd.port.mk>
