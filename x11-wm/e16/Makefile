# New ports collection makefile for:   enlightenment
# Version required:    0.12.4
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.5 1997/09/19 03:51:35 max Exp $
#

DISTNAME=	enl_DR-0.12.4
PKGNAME=	enlightenment-0.12.4
CATEGORIES=	x11
MASTER_SITES=	http://www.rasterman.com/ftp/ \
		ftp://cthulhu.mandrake.net/pub/enlightenment/

MAINTAINER=	vanilla@MinJe.com.TW

LIB_DEPENDS=	Im\\.3\\.:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
WRKSRC=		${WRKDIR}/enl-0.12.4

.include <bsd.port.mk>
