# New ports collection makefile for:   xmold
# Version required:    1.0
# Date created:        11 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.3 1999/08/22 19:01:07 mharo Exp $
#

DISTNAME=	xmold
PKGNAME=	xmold-1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xwin/

MAINTAINER=	nacai@iname.com

USE_IMAKE=	yes

do-install:
	@${MKDIR} ${PREFIX}/bin
	@install -c -s ${WRKSRC}/xmold ${PREFIX}/bin
	@${CHMOD} 755 ${PREFIX}/bin/xmold
	@${CHOWN} bin.bin ${PREFIX}/bin/xmold

.include <bsd.port.mk>
