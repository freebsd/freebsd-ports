# New ports collection makefile for:	wm2
# Version required:	3.0
# Date created:		16 February 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1998/08/05 09:31:49 asami Exp $
#

DISTNAME=	wm2-3
PKGNAME=        wm2-3.0
CATEGORIES=     x11-wm
MASTER_SITES=   http://www.netcomuk.co.uk/~cannam/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/wm2
ALL_TARGET=	depend wm2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wm2 ${PREFIX}/bin

.include <bsd.port.mk>
