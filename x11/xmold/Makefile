# New ports collection makefile for:   xmold
# Version required:    1.0
# Date created:        11 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: porting.sgml,v 1.25 1996/08/01 00:12:11 asami Exp $
#

DISTNAME=	xmold
PKGNAME=        xmold-1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xwin/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_IMAKE=	yes

do-install:
	@mkdir -p ${PREFIX}/bin
	@install -c -s ${WRKSRC}/xmold ${PREFIX}/bin
	@chmod 755 ${PREFIX}/bin/xmold
	@chown bin.bin ${PREFIX}/bin/xmold

.include <bsd.port.mk>
