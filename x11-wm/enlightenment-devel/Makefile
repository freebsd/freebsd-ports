# New ports collection makefile for:   enlightenment
# Version required:    0.12.6
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.7 1997/10/30 22:34:04 max Exp $
#

DISTNAME=	enl_DR-0.12.6
PKGNAME=	enlightenment-0.12.6
CATEGORIES=	x11
MASTER_SITES=	ftp://cthulhu.mandrake.net/pub/enlightenment/ \
		http://www.rasterman.com/ftp/

MAINTAINER=	vanilla@MinJe.com.TW

LIB_DEPENDS=	Im\\.3\\.:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
WRKSRC=		${WRKDIR}/enl-0.12.6

.include <bsd.port.mk>
