# New ports collection makefile for:   xmold
# Version required:    1.0
# Date created:        11 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/11/15 16:25:36 erich Exp $
#

DISTNAME=	xmold
PKGNAME=	xmold-1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xwin/

MAINTAINER=	nacai@iname.com

USE_IMAKE=	yes

do-install:
	@mkdir -p ${PREFIX}/bin
	@install -c -s ${WRKSRC}/xmold ${PREFIX}/bin
	@chmod 755 ${PREFIX}/bin/xmold
	@chown bin.bin ${PREFIX}/bin/xmold

.include <bsd.port.mk>
